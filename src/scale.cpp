#include <vector>
#include <view.h>
#include <unistd.h>
#include <ncurses.h>
#include <iostream>
#include <Eigen/Dense>
#include <world.h>

#include <chrono>

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
  bool ch = 0;
  View view(world.player);

  world.init(view);
  int fc = 0;
  while(!ch){


  	world.tick();										/* updates player & mob positions, makes things happen */

  	view.update();									/* updates the "camera" (view) depending on the player movements */

  	world.load(view);

  	view.draw(world);								/* actually displays on the terminal what has been loaded */

    mvprintw(0,0,"%d", world.time);
    mvprintw(1,0,"%d", world.ntime);
    mvprintw(2,0,"%d", fc++);
    std::chrono::duration<double> dtime = std::chrono::duration_cast<std::chrono::duration<double>>(world.ntime - world.time);
    mvprintw(3,0,"%f", dtime.count());
    world.time = world.ntime;

    //std::vector<input>& in = world.player.inputs;
		mvprintw(8,0,"%d,%d,%d,%d", world.player.inputs[113],world.player.inputs[114],world.player.inputs[111],world.player.inputs[116]);
		mvprintw(4,0,"(%d,%d)",world.player.coords.x(),world.player.coords.y());
		mvprintw(5,0,"(%d,%d)(%d,%d)",view.coords.col(0).x(),view.coords.col(0).y(),view.coords.col(1).x(),view.coords.col(1).y());
		mvprintw(6,0,"(%f,%f)(%f,%f)(%f,%f)",world.player.acc.x(),world.player.acc.y(),world.player.vel.x(),world.player.vel.y(),world.player.pos.x(),world.player.pos.y());
		mvprintw(7,0,"%d", world.player.status);
		//mvprintw(2,0,"%c,%c,%c,%c", in[0].ch,in[1].ch,in[2].ch,in[3].ch);
		ch = world.player.inputs[38];

  	refresh();
  	//usleep(1000000);
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
