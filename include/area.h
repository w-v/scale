#ifndef SCALE_AREA
#define SCALE_AREA

/* Forward declarations */
class View;
class Area;



#include <chunk.h>
#include <vector>
#include <terrain.h>
#include <Eigen/Dense>

class Area : public vector<Chunk>{

public:


  void load(View&, Terrain&);

  Area();
};


#endif
