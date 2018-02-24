#include <displayable.h>
#include <vec2.h>

Displayable::Displayable(Vec2<float> *p) : 
  pos(p)
{}

Displayable::Displayable(Graphic *g, Vec2<float> *p) : 
  graph(g),
  pos(p)
{}

