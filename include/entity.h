#ifndef SCALE_ENTITY
#define SCALE_ENTITY

#include <vec2.h>
#include <displayable.h>

class Entity : public Displayable
{

public:

Vec2<float> vel;
Vec2<float> acc;

float max_vel;

void move(Vec2<float>);
void update_pos();

};

#endif

