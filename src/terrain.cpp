#include <terrain.h>


Terrain::Terrain(){

}

void Terrain::moveload(Chunk chunk, Vec2<int> coords){
	chunk.coords = coords;
	load(chunk);

}
