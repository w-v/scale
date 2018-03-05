#ifndef SCALE_GRAPHIC
#define SCALE_GRAPHIC

#include <vector>
#include <char.h>
#include <Eigen/Dense>

using namespace std;

class Graphic : public vector<vector<Char>> {
public:
	Eigen::Vector2i size;
};

#endif
