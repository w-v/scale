#include <vector>
#include <view.h>
#include <unistd.h>
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

World world;

int main(){

  init();
  int ch = getch();
  View view(world.player);

  world.init(view);

  while(ch != 'q'){


  	world.tick();										/* updates player & mob positions, makes things happen */

  	view.update();									/* updates the "camera" (view) depending on the player movements */

  	world.load(view);

  	view.draw(world);								/* actually displays on the terminal what has been loaded */

    mvprintw(0,0,"%d", world.time);

    std::vector<input>& in = world.player.inputs;
		mvprintw(1,0,"%d", world.player.status);
		mvprintw(2,0,"%c,%c,%c,%c", in[0].ch,in[1].ch,in[2].ch,in[3].ch);
		mvprintw(6,0,"%d,%d,%d,%d", in[0].ch,in[1].ch,in[2].ch,in[3].ch);
		mvprintw(3,0,"(%d,%d)",world.player.coords.x(),world.player.coords.y());
		mvprintw(4,0,"(%d,%d)(%d,%d)",view.coords.col(0).x(),view.coords.col(0).y(),view.coords.col(1).x(),view.coords.col(1).y());
		ch = world.player.inputs[0].ch;

  	refresh();
  	usleep(10000);
  	//return 0;
  }
  endwin();                       /* End curses mode                */
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
