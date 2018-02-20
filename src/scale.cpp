#include <ncurses.h>
#include <stdlib.h>

// Initialize ncurses
int init(){

  initscr();                    /* Start curses                         */
  
  raw();                        /* Disable line buffering               */
  noecho();                     /* Don't print typed characters         */
  keypad(stdscr, TRUE);         /* Read arrow keys and such             */

  return 0;
}

int main(){
  
  init();

  addch('0' | A_BOLD | A_UNDERLINE);
  //printw("Hello World !!!");      /* Print Hello World              */
  refresh();                      /* Print it on to the real screen */
  getch();                        /* Wait for user input */
  endwin();                       /* End curses mode                */
  exit(0);

}
