/*
 * player.cpp
 *
 *  Created on: 4 mars 2018
 *      Author: robin
 */

#include <player.h>

Player::Player(){
	this->graphic = Graphic(Vector2i(1,1));
	this->graphic[0][0] = Char('o');
}

