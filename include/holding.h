/*
 * holding.h
 *
 *  Created on: 14 mars 2018
 *      Author: robin
 */



#ifndef INCLUDE_HOLDING_H_
#define INCLUDE_HOLDING_H_

class Entity;

enum Direction : short;
#include "displayable.h"


class Holding : public Displayable
{


public :

	Entity& holder;

	bool is_held_down;

	Holding(Entity&);

	void hold_down(Direction);
	void hold_up();

	void update_coords();
};


#endif /* INCLUDE_HOLDING_H_ */
