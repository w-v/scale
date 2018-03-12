/*
 * player.cpp
 *
 *  Created on: 4 mars 2018
 *      Author: robin
 */

#include <player.h>
#include <world.h>

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





	if(inputs[KEY_R]){
		this->spawn(0, world->area);
	}

	react();

	vel=Vector2f(max_vel,max_vel).cwiseMin(acc+vel).cwiseMax(Vector2f(-max_vel,-max_vel));
	pos=collide(world->area);

	round_coords();
	Vector2i v = coords + Vector2i(0,-1);
	if(world->area.is_solid(v)){

		if(status == Status::falling){
			status = Status::standing;
			vel.setZero();
			acc.setZero();
			//spawn(coords.x(), world->area);
		}

	}
	else{
		//if(!isongrnd(world->area) && status != Status::falling){
		if(status != Status::falling){
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


      if(input[105])
        coords.x()--;

      if(inputs[106])
        coords.x()++;

      if(inputs[103])
        coords.y()++;

      case KEY_DOWN :
        coords.y()--;


    }*/

}

void Player::standing(){


	if(inputs[105])
		walk(-0.30);

	if(inputs[106])
		walk(0.30);

	if(inputs[103])
		jump(0);

}

void Player::walking(){


	if(inputs[105])
		walk(-0.30);

	if(inputs[106])
		walk(0.30);

	if(inputs[103])
		jump(0);

	if( !(inputs[103]&inputs[105]&inputs[106]) )
		stand();

}


void Player::jumping(){
	falling();
}


void Player::falling(){


	if(inputs[105])
		fall(-0.01);

	if(inputs[106])
		fall(0.01);

	if( !(inputs[105]&inputs[106]) )
		fall(0);

}

void Player::stand(){
	status = Status::standing;
	vel.setZero();
	acc.setZero();
}

void Player::walk(float dir){

	status = Status::walking;
	acc(0) += dir;

}

void Player::jump(float dir){
	status = Status::jumping;
	acc(0)/=4;
	vel+= Vector2f(dir,0.4);
}

void Player::fall(float dir){
	status = Status::falling;
	vel+= Vector2f(dir,0);
	acc= Vector2f(0,-0.03);

}
