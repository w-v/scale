#ifndef SCALE_BLOC
#define SCALE_BLOC

#include <vec2.h>
#include <displayable.h>

class Bloc : public Displayable {

  char type;                                    
  Bloc(char c);

  void display(Vec2<int> vcoords);
};

#endif
