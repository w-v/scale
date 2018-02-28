#include <bloc.h>
#include <ncurses.h>

void Bloc::display(Vec2<int> vcoords){


	wmove(stdscr,vcoords.y,vcoords.x);
	addch(this->type);

}
