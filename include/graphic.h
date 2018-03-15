#ifndef SCALE_GRAPHIC
#define SCALE_GRAPHIC

#include <vector>
#include <char.h>
#include <Eigen/Dense>

//using namespace std;

class GenGraphic {


};

template <class T>
class Graphic : public std::vector<std::vector<T>> , GenGraphic {

public:
	Eigen::Vector2i size;


	Graphic(Eigen::Vector2i);


};

template <class T>
Graphic<T>::Graphic(Eigen::Vector2i s)
	: size(s)
{
	this->resize(s.x());
	for (int i = 0; i < s.x(); ++i)
	    this->at(i).resize(s.y());
}
#endif
