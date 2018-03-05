#ifndef SCALE_ENTITY
#define SCALE_ENTITY

#include <displayable.h>
#include <Eigen/Dense>

using namespace Eigen;

class Entity : public Displayable
{

public:

Vector2f acc;
Vector2f vel;
Vector2f pos;								/* Position in float precision */
														/* gets rounded to make the Vector2i coords inherited from Displayable */

float max_vel;							/* in char per sec */

void move(Vector2f);
void update_pos();
void round_coords();

Entity(Vector2f);
Entity();

void spawn(Vector2f);

};

#endif

