#ifndef SCALE_WORLD
#define SCALE_WORLD

#include <vector>
#include <player.h>
#include <area.h>
#include <terrain.h>
#include <chrono>
#include <ctime>

//#define MAX_HEIGHT	256
#define GRAVITY			9.81


class World {

public:

	std::chrono::steady_clock::time_point time;
	std::chrono::steady_clock::time_point ntime;
  Player player;
  
  Area area;						/* loaded part of the world */
  Terrain terrain;				/* responsible for terrain loading */


  void tick();

  void load(View&);

  void init(View&);

  World();


};

#endif
