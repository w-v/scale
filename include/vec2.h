#ifndef SCALE_VEC2
#define SCALE_VEC2

template <class T>
class Vec2 {
public:
  T x;
  T y;

  Vec2(T,T);
  Vec2();

  Vec2<T> operator+(Vec2<T>);
};

template <class T>
Vec2<T>::Vec2(T x, T y){
  this->x = x;
  this->y = y;
}

template <class T>
Vec2<T> operator+(Vec2<T> a,Vec2<T> b){
	Vec2<T> c;
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	return c;
}
#endif

