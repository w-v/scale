#ifndef SCALE_DISPLAYABLE
#define SCALE_DISPLAYABLE

#include <vec2.h>
#include <graphic.h>

class Displayable {
public:
  Graphic *graph;
  Vec2<float> *pos;
  void display() const;
  Displayable(Vec2<float> *p = new Vec2<float>(.0,.0));
  Displayable(Graphic *g, Vec2<float> *p = new Vec2<float>(.0,.0));
};

#endif
