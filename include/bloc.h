#ifndef SCALE_BLOC
#define SCALE_BLOC

#include <vec2.h>
#include <displayable.h>

class Bloc : public Displayable {

  static const Vec2<int> size(2,1);
  char type;                                    
  //not necessary //Vec2<int> chpos;                              /* position in the chunk */
  Bloc(char c);

};

#endif
