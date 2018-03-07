#ifndef SCALE_BLOC
#define SCALE_BLOC

#include <displayable.h>

class Bloc : public Char {

	public:

	Bloc(char c): Char(c) {}

	// TODO : make Displayable have a variable type, that way chunk can be a displayable<Bloc>
	// while player is a Displayable<Char>
	// that way you can use Bloc functions inside of Chunk
	//bool isAir();
};

#endif
