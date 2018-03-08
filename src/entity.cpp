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

Vector2f Entity::collide(Area& area){

	Vector2i v = this->coords+Vector2i(1,0);

	if(area.is_solid(v)){
		acc(1) = fmin(acc(0),0);
		vel(0) = fmin(vel(0),0);
	}
	v = this->coords+Vector2i(-1,0);
	if(area.is_solid(v)){
		acc(0) = fmax(acc(0),0);
		//acc(1) = fmin(acc(1),0);
		vel(0) = fmax(vel(0),0);
		//vel(1) = fmin(vel(1),0);

	}
	v = this->coords+Vector2i(0,1);
	if(area.is_solid(v)){
		acc(1) = fmin(acc(1),0);
		vel(1) = fmin(vel(1),0);

	}
	v = this->coords+Vector2i(0,-1);
	if(area.is_solid(v)){
		acc(1) = fmax(acc(1),0);
		vel(1) = fmax(vel(1),0);
		//acc(0) = fmin(acc(0),0);
		//vel(0) = fmin(vel(0),0);

	}

	return pos+vel;
}
