#include <displayable.h>

Displayable::Displayable(Vector2i v)
	: coords(v), graphic(Graphic(Vector2i(0,0)))
{}


Displayable::Displayable(Vector2i v, Vector2i s)
	: coords(v), graphic(Graphic(s))
{}
