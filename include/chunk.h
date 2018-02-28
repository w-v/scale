#ifndef SCALE_CHUNK
#define SCALE_CHUNK

#include <vec2.h>
#include <bloc.h>
#include <terrain.h>
#include <world.h>

#define CHUNK_SIZE 16

class Chunk : public Displayable {

public:

Vec2<int> coords;                       /* chunk coordinates (world coord)
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

Bloc blocs [MAX_HEIGHT][CHUNK_SIZE];

static const Vec2<int> chunk_size = Vec2<int>(MAX_HEIGHT,CHUNK_SIZE);

Chunk(Vec2<int> coords, Bloc blocs[][] = 0);

};

#endif

