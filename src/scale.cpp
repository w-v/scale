#include <utils.h>
#include <vec2.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <scale.h>
#include <vector>
#include <world.h>
#include <view.h>
#include <area.h>


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
  int ch;
  World *world = new World();
  View *view = new View();
  while((ch = getch()) != 'q'){

  	world->tick();

  	view->follow(Vec2<int>(0,0));

  	world->load(*view);

  	view->draw(*world);

  	refresh();
  	usleep(10000);
  }
  endwin();                       /* End curses mode                */
  exit(0);
	/*
  Vec2<int> pl(0,0);
  int wsize[2];
  int ch;
  while((ch = getch()) != 'q'){

    switch(ch){

      case KEY_LEFT :
        pl.x--;
        break;
      case KEY_RIGHT :
        pl.x++;
        break;
      case KEY_UP :
        pl.y--;
        break;
      case KEY_DOWN :
        pl.y++;
        break;

    }

    getmaxyx(stdscr,wsize[0],wsize[1]);
    if( pl.x > wsize[1] || pl.x < 0 || pl.y > wsize[0] || pl.y < 0 ){ 
      pl.x = 0;
      pl.y = 0;
    }
    clear();
    wmove(stdscr,pl.y,pl.x);
    addch('o');
    refresh();
    usleep(10000);
  }*/

}
