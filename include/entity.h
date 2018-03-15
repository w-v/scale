#ifndef SCALE_ENTITY
#define SCALE_ENTITY

/* Forward declarations */
class Area;
class World;

#include <displayable.h>
#include <Eigen/Dense>

#include <holding.h>

using namespace Eigen;


enum Direction : short {left, right, down, up};

class Entity : public Displayable<Char>
{

public:

Vector2f acc;
Vector2f vel;
Vector2f pos;								/* Position in float precision */
														/* gets rounded to make the Vector2i coords inherited from Displayable */

float max_vel;							/* in char per sec */

unsigned short int mass;

Holding holding;

Direction dir = right;

World* world;

void move(Vector2f);
void update_pos();
void round_coords();

Entity(Vector2f, World*);
Entity(World*);

void spawn(int, Area&);

bool isongrnd(Area&);

void collide(Area&);


};

#endif

