#ifndef SCALE_WORLD
#define SCALE_WORLD

#include <vector>
#include <displayable.h>
#include <player.h>

class World {

public:

  unsigned int time;
  const unsigned int uframe_delay = 10000;
  const float g = 9.81;
  Player player;
  
  void display();
  void tick();
   
  World(); 
};
#endif
