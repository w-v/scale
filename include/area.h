#ifndef SCALE_AREA
#define SCALE_AREA

#include <chunk.h>
#include <vector>
#include <terrain.h>
#include <view.h>

class Area {

public:
  std::vector<std::vector<Chunk>> chunks;          /* loaded chunks */

  Vec2<int> size;

  Chunk chunk(Vec2<int> coords);
  //Vec2<int> ldcenter;								/* load around */

  void loadWith(Terrain);                 /* load chunk i */

  void loadAround(View);
  Area();
};


#endif
