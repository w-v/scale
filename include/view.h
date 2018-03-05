#ifndef SCALE_VIEW
#define SCALE_VIEW

/* Forward declarations */
class Area;

#include <entity.h>
#include <world.h>
#include <Eigen/Dense>


using namespace Eigen;

class View {

public:
  
	Matrix2i coords;
                                /* : world coordinates */
                                /* forms the window the game is displayed in */ 

  //void follow(Vector2i& pos);            /* move the view around pos */

	Vector2i update_lim;

	Entity& followed;

	void follow(Entity&);

  void draw(World&);

  void draw(Area&);

  void update();

  View(Entity& fol);


};

#endif
