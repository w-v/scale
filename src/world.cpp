#include <world.h>

World::World(){
  time = 0;
}

void World::tick(){
  
  
  /* Update loop */
  //vector<Displayable>::iterator it;
  //it = objects.begin();

  time++;
}

void World::load(View view){


  	this->area.load(*view);
  	this->area.loadWith()
}
