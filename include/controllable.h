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

class Controllable {

public:

	std::vector<int> inputs;
	std::vector<int>& getInput( std::vector<int>& );						/* returns an array with all currently pressed keys */
	//void control();
};


#endif /* INCLUDE_CONTROLLABLE_H_ */
