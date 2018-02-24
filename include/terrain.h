#ifndef SCALE_TERRAIN
#define SCALE_TERRAIN

#include <bloc.h>

class Terrain {

public:
  //vector<Bloc[64][64]> chunks;          /* chunk of blocks */
  vector<Bloc[8][8]> chunks;          /* chunk of blocks */
  
  void load(int chunk = 0);                 /* load chunk i */

  Terrain();
};

#endif
