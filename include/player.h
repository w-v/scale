#ifndef SCALE_PLAYER
#define SCALE_PLAYER


#include <entity.h>
#include <controllable.h>
#include <ncurses.h>
#include <bloc.h>


enum Status {standing, walking, jumping, falling};

class Player : public Controllable, public Entity
{



  public:
  
	Status status;

	Bloc breakotron = Bloc('@');

	void update();
  Player(World*);
  
  void react();

  void standing();
  void walking();
  void jumping();
  void falling();

  void stand();
  void walk(float dir);
  void jump(float dir);
  void fall(float dir);
};

#endif
