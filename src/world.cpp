#include <world.h>
#include <ncurses.h>
#include <view.h>
#include <ctime>
#include <chrono>

World::World()
	: ntime(std::chrono::steady_clock::now()), time(std::chrono::steady_clock::now()), player(this), area(), terrain()
{}

void World::tick(){
  
	ntime = std::chrono::steady_clock::now();
	player.update();
  //time = ntime;
}

void World::load(View& view){

	area.load(view,terrain);					/* loads all graphics visible in the view */

}

void World::init(View& view){

	area.load(view,terrain);					/* loads all graphics visible in the view */
	player.spawn(0,area);
	view.center(player.coords);

}
