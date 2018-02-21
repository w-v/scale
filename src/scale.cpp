#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>


#define god(x) x=3;y=12


// Initialize ncurses
int init(){

  initscr();                    /* Start curses                         */

  raw();                        /* Disable line buffering               */
  noecho();                     /* Don't print typed characters         */
  keypad(stdscr, TRUE);         /* Read arrow keys and such             */
  nodelay(stdscr, TRUE);
  curs_set(FALSE);

  return 0;
}

int main(){

  init();
  int x = 0;
  int y = 0;
  int wsize[2];
  int ch;
  while((ch = getch()) != 'q'){

    switch(ch){

      case KEY_LEFT :
        x--;
        break;
      case KEY_RIGHT :
        x++;
        break;
      case KEY_UP :
        y--;
        break;
      case KEY_DOWN :
        y++;
        break;

    }

    getmaxyx(stdscr,wsize[0],wsize[1]);
    if( x > wsize[1] || x < 0 || y > wsize[0] || y < 0 ){ 
      x = 0;
      y = 0;
    }
    clear();
    wmove(stdscr,y,x);
    addch('o');
    refresh();                      /* Print it on to the real screen */
    usleep(10000);
  }
  endwin();                       /* End curses mode                */
  exit(0);

}
