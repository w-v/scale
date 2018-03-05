#include <entity.h>

Entity::Entity()
	: pos(Vector2f(0.0,0.0)), max_vel(10), acc(Vector2f(0.0,0.0)), vel(Vector2f(0.0,0.0))
{}

Entity::Entity(Vector2f v)
	: pos(v), max_vel(10), acc(Vector2f(0.0,0.0)), vel(Vector2f(0.0,0.0))
{

	spawn(v);
	round_coords();

}


void Entity::round_coords(){

	//coords = pos.array().round().matrix().cast<int>();			/* ugly */

}


void Entity::spawn(Vector2f v){

	pos = Vector2f(0.0,0.0);

}



