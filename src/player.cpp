/*
 * player.cpp
 *
 *  Created on: 4 mars 2018
 *      Author: robin
 */

#include <player.h>
#include <world.h>
#include <xlib3.h>
#include <chrono>

//#include <ncurses.h>

Player::Player(World* w) : Entity(w){
	this->graphic = Graphic(Vector2i(1,2));
	this->graphic[0][0] = Char('o');
	this->graphic[0][1] = Char('@');
	status = Status::standing;
}

void Player::update(){

	//TODO :
	//	when player changes direction, reset acc to 0
	//	more reactive
	//	more predictable





	if(inputs[X_R]){
		this->spawn(0, world->area);
	}

	react();
	std::chrono::duration<float> dtime = std::chrono::duration_cast<std::chrono::duration<float>>(world->ntime - world->time);
	vel=Vector2f(max_vel,max_vel).cwiseMin( ( acc*dtime.count() ) + vel).cwiseMax(Vector2f(-max_vel,-max_vel));
	//vel = vel + 0.05 * acc;
	collide(world->area);
	pos = pos + dtime.count() * vel;
	round_coords();
	Vector2i v = coords + Vector2i(0,-1);
	if(world->area.is_solid(v)){

		if(status == Status::falling){
			stand();
			//spawn(coords.x(), world->area);
		}

	}
	else{
		//if(!isongrnd(world->area) && status != Status::falling){
		if(status != Status::falling ){
			fall(0);
		}
	}
}

void Player::react(){

	switch(status){

	case Status::standing :
		standing();
		break;
	case Status::walking :
		walking();
		break;

	case Status::jumping :
		jumping();
		break;

	case Status::falling :
		falling();
		break;

	}
	/*
      if(input[X_LEFT])
        coords.x()--;
      if(inputs[X_RIGHT])
        coords.x()++;
      if(inputs[X_UP])
        coords.y()++;
      case KEY_DOWN :
        coords.y()--;
    }*/

}

void Player::standing(){


	if(inputs[X_LEFT])
		walk(-600);

	if(inputs[X_RIGHT])
		walk(600);

	if(inputs[X_UP])
		jump(0);

	if( !(inputs[X_UP]||inputs[X_LEFT]||inputs[X_RIGHT]) )
		stand();
}

void Player::walking(){


	if(inputs[X_LEFT])
		walk(-600);

	if(inputs[X_RIGHT])
		walk(600);

	if(inputs[X_UP])
		jump(0);

	if( !(inputs[X_UP]||inputs[X_LEFT]||inputs[X_RIGHT]) )
		stand();

}


void Player::jumping(){
	//falling();
	jump(0);
}


void Player::falling(){


	if(inputs[X_LEFT])
		fall(-300);

	if(inputs[X_RIGHT])
		fall(300);

	if( !(inputs[X_LEFT]||inputs[X_RIGHT]) )
		fall(0);

}

void Player::stand(){
	status = Status::standing;
	pos(1) = (float) coords.y();
	vel.setZero();
	acc.setZero();
}

void Player::walk(float dir){

	status = Status::walking;
	acc(0) = dir / this->mass;

}

void Player::jump(float dir){
	status = Status::jumping;
	//acc(0)/=4;
	vel += Vector2f(dir,5000) / mass;
}

void Player::fall(float dir){
	status = Status::falling;

	acc = ( Vector2f(0,-GRAVITY*60) + Vector2f(dir,0) ) / mass;

}
