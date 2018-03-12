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


	//mvprintw(5,0,"ch");
	getInput(inputs, world->time);
	//react_all(inputs);
	std::vector<input>::const_iterator it;

	/*for(it = inputs.begin(); it != inputs.end(); ++it){

		mvprintw(5,0,"ch: %c",(*it).ch);
		react(*it);

	}*/


	if(inputs[0].ch == 'r'){
		this->spawn(0, world->area);
	}
	//mvprintw(5,0,"sz: %d",inputs.size());
	for(int i=0; i<inputs.size()-1; i++){

		if(inputs[i].ch != -1){
			react(inputs[i]);
		}

	}

	if(inputs.size() == 1){
		react(inputs[0]);
	}

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

void Player::react(input in){

		switch(status){

			case Status::standing :
				standing(in.ch);
				break;
			case Status::walking :
				walking(in.ch);
				break;
			case Status::jumping :
				jumping(in.ch);
				break;
			case Status::falling :
				falling(in.ch);
				break;
		}
	/*
    switch(in){

      case KEY_LEFT :
        coords.x()--;
        break;
      case KEY_RIGHT :
        coords.x()++;
        break;
      case KEY_UP :
        coords.y()++;
        break;
      case KEY_DOWN :
        coords.y()--;
        break;

    }*/

}

void Player::standing(int in){
    switch(in){

      case KEY_LEFT :
      	walk(-0.080);
        break;
      case KEY_RIGHT :
      	walk(0.080);
        break;
      case KEY_UP :
      	jump(0);
        break;
    }
}

void Player::walking(int in){
    switch(in){

      case KEY_LEFT :
      	walk(-0.020);
        break;
      case KEY_RIGHT :
      	walk(0.020);
        break;
      case KEY_UP :
      	jump(0);
        break;
      default :
      	stand();
    }

}


void Player::jumping(int in){
	falling(in);
}


void Player::falling(int in){
    switch(in){

      case KEY_LEFT :
      	fall(-0.03);
        break;
      case KEY_RIGHT :
      	fall(0.03);
        break;
      default :
      	fall(0);
    }

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
		acc+= Vector2f(0,-0.008);

}
