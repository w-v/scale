#include <view.h>

void View::draw(World world){


}

void View::draw(Area area){


	for(int i = 0 ; i < area.chunks.size() ; i++){

		for(int j = 0 ; j < area.chunks.size() ; j++){

			draw(area.chunks[i][j]);

		}

	}


}

void View::draw(Chunk chunk){

	Vec2<int> clip_orig = this->orig ;

	if(clip_orig.x <= chunk.coords.x){
		clip_orig.x = Vec2<int>(0,0);
	}
	else{
		clip_orig.x = clip_orig.x - chunk.coords.x;
	}
	if(clip_orig.y <= chunk.coords.y){
		clip_orig.y = Vec2<int>(0,0);
	}
	else{
		clip_orig.y = clip_orig.y - chunk.coords.y;
	}

	Vec2<int> clip_end = this->orig+this->size;
	Vec2<int> chunk_end = chunk.coords + chunk.chunk_size;

	if(clip_end.x >= chunk_end.x){
		clip_end.x = chunk.chunk_size;
	}
	else{
		clip_end.x = clip_end.x - chunk.coords.x;
	}
	if(clip_end.y >= chunk_end.y){
		clip_end.y = chunk.chunk_size;
	}
	else{
		clip_end.y = clip_end.y - chunk.coords.y;
	}

	Vec2<int> proj = this->orig + clip_orig;


}
