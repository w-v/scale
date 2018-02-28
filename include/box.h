#ifndef SCALE_BOX
#define SCALE_BOX

#include <vec2.h>

template <class T>
class Box {
public:
  Vec2<T> orig;
  Vec2<T> size;

  Box(Vec2<T>,Vec2<T>);
  Box();

  //Vec2<T> operator+(Vec2<T>);
};

#endif
