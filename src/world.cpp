#include <world.h>
#include <ncurses.h>

World::World()
	: time(0), player(), area(), terrain()
{}

void World::tick(){
  
  
	player.inputs = player.getInput(player.inputs);

  time++;
}

