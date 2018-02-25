#ifndef SCALE_TERRAIN
#define SCALE_TERRAIN

#define DRAW_DISTANCE           /* in chunks around a center chunk */

#include <chunk.h>

class Terrain {

public:
  vector<vector<Chunk>> ldchunks;          /* loaded chunks */
  
  void load();                 /* load chunk i */
  
  void loadAround(Chunk);
  Terrain();
};

#endif
