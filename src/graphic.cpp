#include <graphic.h>

Graphic::Graphic(Eigen::Vector2i s)
	: size(s)
{
	resize(s.x());
	for (int i = 0; i < s.x(); ++i)
	    this->at(i).resize(s.y());
}
