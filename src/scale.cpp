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
  int ch = getch();
  World world;
  View view(world.player);

  while(ch != 'q'){


  	world.tick();										/* updates player & mob positions, makes things happen */

  	view.update();									/* updates the "camera" (view) depending on the player movements */

  	world.area.load(view,world.terrain);					/* loads all graphics visible in the view */

  	view.draw(world);								/* actually displays on the terminal what has been loaded */

    mvprintw(0,0,"%d", world.time);

    std::vector<int>& in = world.player.inputs;
		mvprintw(2,0,"%c,%c,%c,%c", in[0],in[1],in[2],in[3]);
		mvprintw(3,0,"(%d,%d)",world.player.coords.x(),world.player.coords.y());
		ch = world.player.inputs[0];
    switch(ch){

      case KEY_LEFT :
        world.player.coords.x()--;
        break;
      case KEY_RIGHT :
        world.player.coords.x()++;
        break;
      case KEY_UP :
        world.player.coords.y()++;
        break;
      case KEY_DOWN :
        world.player.coords.y()--;
        break;

    }


  	refresh();
  	usleep(10000);
  	//return 0;
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
