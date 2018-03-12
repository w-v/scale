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


/*template <class T>
class Vec2 {
public:
  T x;
  T y;

  Vec2(T,T);
  Vec2();

  Vec2<T> operator+(Vec2<T>);
};

template <class T>
Vec2<T>::Vec2(T x, T y){
  this->x = x;
  this->y = y;
}*/

//template <class T>
//class Controllable : public T{
struct input {

	int ch;
	unsigned int time;

};

class Controllable{

public:

	bool inputs[128];

	std::vector<input>& getInput( std::vector<input>& , unsigned int time);						/* returns an array with all currently pressed keys */

	void react_all(std::vector<input>&);
	virtual void react(input);

	//void control();
};

/*
//template <class T>
//std::vector<int>& Controllable<T>::getInput( std::vector<int>& in ){
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


//template <class T>
//void Controllable<T>::react_all( std::vector<int>& in ){
void Controllable::react_all( std::vector<int>& in ){

	std::vector<int>::const_iterator it;

	for(it = in.begin(); it != in.end(); ++it){

		react(*it);

	}

}

//template <class T>
//void Controllable<T>::react( int in ){
void Controllable::react( int in ){



}

*/
#endif /* INCLUDE_CONTROLLABLE_H_ */
