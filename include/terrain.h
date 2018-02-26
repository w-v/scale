#ifndef SCALE_TERRAIN
#define SCALE_TERRAIN

#define DRAW_DISTANCE         25  /* in chunks around a center chunk */

#include <chunk.h>
#include <vector>

class Terrain {

public:
  
  //Vec2<int> ldcenter;								/* load around */

  void load(Chunk);                 /* load chunk i */
  
  Terrain();
};


#endif
