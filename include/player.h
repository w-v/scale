#ifndef SCALE_PLAYER
#define SCALE_PLAYER



#include <entity.h>
#include <scale.h>

class Player : public Entity
{
  public:
  
  int[MAX_SIMULT_INPUT] getInput();             /* returns an array with all currently pressed keys */
 
  Player();
  
};

#endif
