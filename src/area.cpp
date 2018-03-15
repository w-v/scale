#include <area.h>
#include <view.h>
#include <terrain.h>
#include <stdlib.h>
#include <unistd.h>
#include <bloc.h>

Area::Area(){

}

void Area::load(View& v, Terrain& t){

	if(this->empty()){
		int orig = v.coords(0,0) / CHUNK_SIZE;
		int size = v.coords(0,1) / CHUNK_SIZE;

		for(int i = orig-2; i <= size+2; i++){

			push_back( Chunk(Vector2i(i*16,0)) );


			t.load(this->back());

		}

	}
	else{

		int orig = v.coords(0,0) - ( v.coords(0,0) % CHUNK_SIZE );
		int size = v.coords(0,1) - ( v.coords(0,1) % CHUNK_SIZE );


		//fprintf(stderr,"s: %d o: %d",size + CHUNK_SIZE *2, orig - CHUNK_SIZE *2);
		while(this->front().coords.x() != (orig - CHUNK_SIZE *2) ){

			//fprintf(stderr,"%d a) %d, %d",v.followed.world->time,this->front().coords.x(),orig - CHUNK_SIZE *2);
  	//usleep(1000000);

			if( this->front().coords.x() > (orig - CHUNK_SIZE *2) ){
				push_front( Chunk(Vector2i(this->front().coords.x() - CHUNK_SIZE  ,0)) );
				t.load(this->front());
			}
			else {
				pop_front();
			}


		}

		while(this->back().coords.x() != (size + CHUNK_SIZE *2) ){

			//fprintf(stderr,"b) %d, %d",this->back().coords.x(),(size + CHUNK_SIZE *2) );
  	//usleep(1000000);
			if( this->back().coords.x() < (size + CHUNK_SIZE *2) ){
				push_back( Chunk(Vector2i(this->back().coords.x() + CHUNK_SIZE ,0)) );
				t.load(this->back());
			}
			else {
				pop_back();
			}


		}
	}

}

bool Area::is_loaded(int x){

	int orig = this->front().coords.x();
	int end = this->back().coords.x();

	return x >= orig && x <= end+CHUNK_SIZE;

}
Vector2i Area::get_spawnable(int x){

	int orig = this->front().coords.x();

	orig = abs( x - orig ) / CHUNK_SIZE;

	int offset = x % CHUNK_SIZE;

	Chunk& sp = this->at(orig);

	// TODO : make sure there is vertical  space to spawn ( if entity.graphic.size > (1,1) )
	return Vector2i(x,this->at(orig).ground_y(abs(offset)));
}

bool Area::is_solid(Vector2i& v){
	if(!is_loaded(v.x()))
		return false;

	int orig = this->front().coords.x();

	orig = abs( orig - v.x());

	int offset = orig % CHUNK_SIZE;

	orig/= CHUNK_SIZE;

	return this->at(orig).graphic[abs(offset)][v.y()].ch != ' ';
}


Bloc Area::break_block(Vector2i& v){

	if(is_loaded(v.x())){

	int orig = this->front().coords.x();

	orig = abs( v.x() - orig );

	int offset = orig % CHUNK_SIZE;
	orig/= CHUNK_SIZE;

		Bloc broken = this->at(orig).graphic[abs(offset)][v.y()].clone();
		this->at(orig).graphic[abs(offset)][v.y()] = Bloc(' ');


		return broken;

	}

}



// TODO : make a get_chunk and a get_block function
