#ifndef SCALE_DISPLAYABLE
#define SCALE_DISPLAYABLE

#include <graphic.h>
#include <Eigen/Dense>

using namespace Eigen;

class Displayable {
public:
  Graphic graphic;
  Vector2i coords;											 /* chunk coordinates (world coord)
                                         * if chunk coords are (x,y)
                                         * bloc of coords (0,0) inside the chunk
                                         * has world coord of :
                                         * (x*CHUNK_SIZE,y*CHUNK_SIZE)
                                         *
                                         * (1,1) :
                                         * (x*CHUNK_SIZE+1,y*CHUNK_SIZE+1)
                                         * (x is positive to the right)
                                         * (y is positive going up)
                                         */

  	Displayable(Vector2i = Vector2i(0,0));
  	Displayable(Vector2i, Vector2i);
};

#endif
