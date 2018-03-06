/*
 * controllable.cpp
 *
 *  Created on: 6 mars 2018
 *      Author: robin
 */

#include <controllable.h>
#include <ncurses.h>

std::vector<int>& Controllable::getInput( std::vector<int>& in ){

	in.clear();

	in.push_back(getch());

	char ch;

	while( (ch = getch()) != ERR && in.size() < MAX_SIMULT_INPUT){

		std::vector<int>::const_iterator it = in.begin();

		while(it != in.end() && *it != ch){
				++it;
		}
		if(it == in.end())
			in.push_back(ch);

	}

	return in;
}


