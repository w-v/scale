#ifndef SCALE_PLAYER
#define SCALE_PLAYER


#include <entity.h>
#include <controllable.h>
#include <ncurses.h>


enum Status {standing, walking, jumping, falling};

class Player : public Controllable, public Entity
{



  public:
  
	Status status;

	void update();
  Player(World*);
  
  void react(input);

  void standing(int);
  void walking(int);
  void jumping(int);
  void falling(int);

  void stand();
  void walk(float dir);
  void jump(float dir);
  void fall(float dir);
};

#endif
