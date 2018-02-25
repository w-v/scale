#ifndef SCALE_TERRAIN
#define SCALE_TERRAIN

#define DRAW_DISTANCE         25  /* in chunks around a center chunk */

#include <chunk.h>
#include <vector>

class Terrain {

public:
  std::vector<std::vector<Chunk>> ldchunks;          /* loaded chunks */
  
  //Vec2<int> ldcenter;								/* load around */

  void load(Chunk);                 /* load chunk i */
  
  void moveload(Chunk, Vec2<int> coords);
  void loadAround(Vec2<int> chunk_coords);
  Terrain();
};


#endif
