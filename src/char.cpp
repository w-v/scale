/*
 * char.cpp
 *
 *  Created on: 5 mars 2018
 *      Author: robin
 */

#include <char.h>

Char::Char(char c)
	: ch(c), color(0), bcolor(0), under(false), bold(false)
{}



Char::Char()
	: ch(' '), color(0), bcolor(0), under(false), bold(false)
{}
