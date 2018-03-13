/*
 * controllable.cpp
 *
 *  Created on: 6 mars 2018
 *      Author: robin
 */

#include <controllable.h>
#include <ncurses.h>

#include "../include/xlib3.h"
#include <pthread.h>

Controllable::Controllable(){

	for(int i = 0; i < 128; i++)
		inputs[i] = 0;
	pthread_t pid;
	pthread_create(&pid, NULL, read_kbd, (void*) inputs);

}
