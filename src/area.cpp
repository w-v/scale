#include <area.h>
#include <view.h>
#include <terrain.h>

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
