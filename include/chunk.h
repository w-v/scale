#ifndef SCALE_CHUNK
#define SCALE_CHUNK

#define CHUNK_SIZE 16

#include <vec2.h>
#include <bloc.h>
#include <terrain.h>

class Chunk {

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

Bloc blocs [CHUNK_SIZE][CHUNK_SIZE];

Chunk(Vec2<int> coords, Bloc blocs[][] = 0);

};

#endif

