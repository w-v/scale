/*
 * holding.cpp
 *
 *  Created on: 14 mars 2018
 *      Author: robin
 */


#include <holding.h>
#include <entity.h>

Holding::Holding(Entity& e):
	holder(e), is_held_down(false)
{}

void Holding::hold_down(Direction dir){

	Vector2i v(0,0);

	switch(dir) {

	case left :
		v(0)--;
		break;
	case right :
		v(0)++;
		break;
	case up :
	case down :
		v(1)--;


	}

	this->coords=holder.coords+v;

}

void Holding::hold_up(){

	this->coords=holder.coords+Vector2i(0,1);

}

void Holding::update_coords(){

	if(this->is_held_down)
		hold_down(holder.dir);
	else
		hold_up();

}
