#ifndef SCALE_VIEW
#define SCALE_VIEW

#include <vec2.h>
#include <entity.h>
#include <world.h>

class View {

public:
  
  Vec2<int> tl;                 /* top left */
  Vec2<int> br;                 /* bottom right */
                                /* : world coordinates */
                                /* forms the window the game is displayed in */ 
  Entity *followed;

  void follow(Entity *e);            /* move the view around entity */

  void draw(World);
};

#endif
