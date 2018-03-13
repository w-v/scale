/*
 * controllable.h
 *
 *  Created on: 6 mars 2018
 *      Author: robin
 */

#ifndef INCLUDE_CONTROLLABLE_H_
#define INCLUDE_CONTROLLABLE_H_

#define MAX_SIMULT_INPUT 5

#include <vector>
#include <ncurses.h>


class Controllable{

public:

	bool inputs[128];
	Controllable();

};

#endif /* INCLUDE_CONTROLLABLE_H_ */
