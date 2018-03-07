#include <world.h>
#include <ncurses.h>
#include <view.h>

World::World()
	: time(0), player(this), area(), terrain()
{}

void World::tick(){
  
  
	player.update();
  time++;
}

void World::load(View& view){

	area.load(view,terrain);					/* loads all graphics visible in the view */

}

void World::init(View& view){

	area.load(view,terrain);					/* loads all graphics visible in the view */
	player.spawn(0,area);
	view.center(player.coords);

}
