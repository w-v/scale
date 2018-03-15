#ifndef SCALE_AREA
#define SCALE_AREA

/* Forward declarations */
class View;
class Area;



#include <chunk.h>
#include <deque>
#include <terrain.h>
#include <bloc.h>

#include <Eigen/Dense>

class Area : public std::deque<Chunk>{

public:


  void load(View&, Terrain&);

  Vector2i get_spawnable(int x);

  bool is_loaded(int x);									/* is chunk containing coord x loaded ? */

  bool is_solid(Vector2i&);

  Bloc break_block(Vector2i&);

  Area();
};


#endif
