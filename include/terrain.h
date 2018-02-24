#ifndef SCALE_TERRAIN
#define SCALE_TERRAIN

#include <chunk.h>

class Terrain {

public:
  vector<vector<Chunk>> ldchunks;          /* loaded chunks */
  
  void load(int chunk = 0);                 /* load chunk i */

  Terrain();
};

#endif
