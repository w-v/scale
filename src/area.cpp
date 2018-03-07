#include <area.h>
#include <view.h>
#include <terrain.h>
#include <stdlib.h>

Area::Area(){

}

void Area::load(View& v, Terrain& t){

	clear();

	int orig = v.coords(0,0) / CHUNK_SIZE;
	int size = v.coords(0,1) / CHUNK_SIZE;

		for(int i = orig-1; i < size+1; i++){

			push_back( Chunk(Vector2i(i*16,0)) );


			t.load(this->back());

		}


}

bool Area::is_loaded(int x){

	int orig = this->front().coords.x();
	int end = this->back().coords.x();

	return x >= orig && x <= end+CHUNK_SIZE;

}
Vector2i Area::get_spawnable(int x){

	int orig = this->front().coords.x();

	orig = ( x - orig ) / CHUNK_SIZE;

	int offset = x % 16;

	Chunk& sp = this->at(orig);

	// TODO : make sure there is vertical  space to spawn ( if entity.graphic.size > (1,1) )
	return Vector2i(x,this->at(orig).ground_y(abs(offset)));
}
