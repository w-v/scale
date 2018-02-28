#ifndef SCALE_VIEW
#define SCALE_VIEW

#include <vec2.h>
#include <entity.h>
#include <world.h>
#include <area.h>
#include <box.h>

class View {

public:
  

	Box<int> box;
                                /* : world coordinates */
                                /* forms the window the game is displayed in */ 

  void follow(Vec2<int> pos);            /* move the view around pos */

  void draw(World);

  void draw(Area);

  Box<int> clip(Displayable);

};

#endif
