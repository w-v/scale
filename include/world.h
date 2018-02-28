#ifndef SCALE_WORLD
#define SCALE_WORLD

#include <vector>
#include <displayable.h>
#include <player.h>
#include <area.h>
#include <terrain.h>

#define MAX_HEIGHT	256

class World {

public:

  unsigned int time;
  const unsigned int uframe_delay = 10000;
  const float g = 9.81;
  Player player;
  
  Area area;						/* loaded part of the map */
  Terrain terrain;				/* responsible for terrain loading */

  void display();
  void tick();

  void load(View);
  World(); 
};
#endif
