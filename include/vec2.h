#ifndef SCALE_VEC2
#define SCALE_VEC2

template <class T>
class Vec2 {
public:
  Vec2(T,T);
  Vec2();
  T x;
  T y;
};

template <class T>
Vec2<T>::Vec2(T x, T y){
  this->x = x;
  this->y = y;
}

#endif

