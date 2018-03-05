#include <area.h>
/*void Area::loadWith(Terrain t){

}*/

Area::Area(){

}

void Area::load(View& v){

	this->chunks.clear();
/*
	Vec2<int> orig = view.orig / CHUNK_SIZE;
	Vec2<int> size = (view.size + view.orig) / CHUNK_SIZE;

	for(int i = orig.y; i < size.y; i++){

		for(int j = orig.x; j < size.x; j++){

			this->chunks[i][j] = new Chunk(j, i);

			this->terrain.load(this->chunks[i][j]);

		}

	}
*/

}
