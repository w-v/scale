#ifndef SCALE_VIEW
#define SCALE_VIEW

#include <vec2.h>
#include <entity.h>
#include <world.h>
#include <area.h>

class View {

public:
  

  Vec2<int> size;               /* size */
  Vec2<int> orig;               /* bottom right */
                                /* : world coordinates */
                                /* forms the window the game is displayed in */ 

  void follow(Vec2<int> pos);            /* move the view around entity */

  void draw(World);

  void draw(Area);

  void draw(Chunk);

};

#endif
