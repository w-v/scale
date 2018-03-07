/*
 * controllable.cpp
 *
 *  Created on: 6 mars 2018
 *      Author: robin
 */

#include <controllable.h>
#include <ncurses.h>



std::vector<input>& Controllable::getInput( std::vector<input>& in , unsigned int time){



	int ch = getch();

	//while( (ch = getch()) != ERR && in.size() < MAX_SIMULT_INPUT){

		std::vector<input>::iterator it = in.begin();

		//if ( (ch = getch()) != ERR) {

			while(it != in.end() && (*it).ch != ch){
					++it;
			}

			if(it == in.end()){
				in.push_back({ch,time});
			}
			else{
				in.erase(it);
				in.push_back({ch,time});
			}
		//}

			for(it = in.begin(); it != in.end(); ++it){
				if(time - (*it).time > 2){
					in.erase(it);
				}
			}

	//}



	return in;
}


//template <class T>
//void Controllable<T>::react_all( std::vector<int>& in ){
void Controllable::react_all( std::vector<input>& in ){

	std::vector<input>::const_iterator it;

	for(it = in.begin(); it != in.end(); ++it){

		react(*it);

	}

}

//template <class T>
//void Controllable<T>::react( int in ){
void Controllable::react( input in ){



		mvprintw(5,0,"nique ta mère");

}
