#ifndef SCALE_TERRAIN
#define SCALE_TERRAIN

#define DRAW_DISTANCE         25  /* in chunks around a center chunk */

/* Forward declarations */
class Chunk;

class Terrain {

public:
  
  void load(Chunk&);                 /* load chunk i */
  
  Terrain();
};


#endif
