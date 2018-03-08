#include <entity.h>
#include <area.h>


Entity::Entity(World* w)
	: pos(Vector2f(0.0,0.0)), max_vel(0.5), acc(Vector2f(0.0,0.0)), vel(Vector2f(0.0,0.0)), world(w)
{
	round_coords();
}

Entity::Entity(Vector2f v, World* w)
	: pos(v), max_vel(10), acc(Vector2f(0.0,0.0)), vel(Vector2f(0.0,0.0)), world(w)
{

	round_coords();

}


void Entity::round_coords(){

	coords = pos.array().round().matrix().cast<int>();			/* ugly */

}


void Entity::spawn(int x, Area& area){



	pos = area.get_spawnable(x).cast<float>();
	round_coords();

}


bool Entity::isongrnd(Area& area){
	return coords.y() == area.get_spawnable(coords.x()).y();
}
