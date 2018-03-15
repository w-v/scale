#include <bloc.h>
#include <ncurses.h>


/*
void Bloc::display(Vec2<int> vcoords){


	wmove(stdscr,vcoords.y,vcoords.x);
	addch(this->type);

}*/


Bloc Bloc::clone(){

	Bloc v(this->ch);
	v.bcolor = this->bcolor;
	v.bold = this->bold;
	v.color = this->color;
	v.under = this->under;

	return v;

}
