#ifndef SCALE_GRAPHIC
#define SCALE_GRAPHIC

#include <vector>
#include <char.h>
#include <Eigen/Dense>

//using namespace std;

class Graphic : public std::vector<std::vector<Char>> {

public:
	Eigen::Vector2i size;


	Graphic(Eigen::Vector2i);


};

#endif
