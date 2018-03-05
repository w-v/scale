#include <vector>
#include <view.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <iostream>
#include <Eigen/Dense>
#include <world.h>

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

	//Eigen::Vector2i v(9,2);
	Eigen::Vector2i a(1,3);
	Eigen::Vector2i b(2,2);
	std::cout << a.cwiseMax(b);

  init();
  int ch;
  World world;
  View view(world.player);

  while((ch = getch()) != 'q'){

  	world.tick();										/* updates player & mob positions, makes things happen */

  	view.update();									/* updates the "camera" (view) depending on the player movements */

  	world.area.load(view);					/* loads all graphics visible in the view */

  	view.draw(world);								/* actually displays on the terminal what has been loaded */

  	refresh();
  	usleep(10000);

  }
  return 0;
}
  //endwin();                       /* End curses mode                */
//  exit(0);

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

//}
