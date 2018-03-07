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

	Vector2i y_down_transf;

	void follow(Entity&);

	void center(Vector2i&);

  void draw(World&);

  void draw(Area&);
  void draw(Displayable&);

  void update();

  void display(Char&, Vector2i&);

  View(Entity& fol);


};

#endif
