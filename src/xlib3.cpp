#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <xlib3.h>
#include <pthread.h>

void * read_kbd(void * in)
{
	bool * inputs = (bool *) in;
   Display *dpy;
   XEvent ev;
   char *s;
   unsigned int kc;
   int quit = 0;

   if (NULL==(dpy=XOpenDisplay(NULL))) {
      perror("Could not connect to X server");
      exit(1);
   }
  XAutoRepeatOff(dpy);

   /*
    * You might want to warp the pointer to somewhere that you know
    * is not associated with anything that will drain events.
    *  (void)XWarpPointer(dpy, None, DefaultRootWindow(dpy), 0, 0, 0, 0, x, y);
    */

   XGrabKeyboard(dpy, DefaultRootWindow(dpy),
                 True, GrabModeAsync, GrabModeAsync, CurrentTime);


   /* A very simple event loop: start at "man XEvent" for more info. */
   /* Also see "apropos XGrab" for various ways to lock down access to
    * certain types of info. coming out of or going into the server */
   for (;!quit;) {
      XNextEvent(dpy, &ev);
      switch (ev.type) {
         case KeyPress:
            kc = ((XKeyPressedEvent*)&ev)->keycode;
            s = XKeysymToString(XKeycodeToKeysym(dpy, kc, 0));
            /* s is NULL or a static no-touchy return string. */
            if (kc) inputs[kc] = 1;
            if (!strcmp(s, "q")) quit=~0;
            break;
         case KeyRelease:
            kc = ((XKeyReleasedEvent*)&ev)->keycode;
            s = XKeysymToString(XKeycodeToKeysym(dpy, kc, 0));
            /* s is NULL or a static no-touchy return string. */
            if (kc) inputs[kc] = 0;
            if (!strcmp(s, "q")) quit=~0;
            break;
         case Expose:
               /* Often, it's a good idea to drain residual exposes to
                * avoid visiting Blinky's Fun Club. */
               while (XCheckTypedEvent(dpy, Expose, &ev)) /* empty body */ ;
            break;
         case ButtonPress:
         case ButtonRelease:
         case MotionNotify:
         case ConfigureNotify:
         default:
            break;
      }
   }

   XUngrabKeyboard(dpy, CurrentTime);
   XAutoRepeatOn(dpy);

   if (XCloseDisplay(dpy)) {
      perror("Could not close connection to X server");
      exit(1);
   }

   pthread_exit((void*) 0);
   return 0;
}
