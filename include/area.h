#ifndef SCALE_AREA
#define SCALE_AREA

/* Forward declarations */
class View;
class Area;



#include <chunk.h>
#include <vector>
#include <terrain.h>
#include <Eigen/Dense>

class Area {

public:
  vector<vector<Chunk>> chunks;          /* loaded chunks */


  void loadWith(Terrain&);                 /* load chunk i */

  void load(View&);

  Area();
};


#endif
