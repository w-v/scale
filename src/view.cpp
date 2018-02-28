#include <view.h>

void View::draw(World world){

	this->draw(world.area);
}

void View::draw(Area area){


	for(int i = 0 ; i < area.chunks.size() ; i++){

		for(int j = 0 ; j < area.chunks.size() ; j++){

			clip(area.chunks[i][j]);

		}

	}


}

void View::clip(Displayable displ){

	Vec2<int> clip_orig = this->box.orig ;

	if(clip_orig.x <= displ.coords.x){
		clip_orig.x = Vec2<int>(0,0);
	}
	else{
		clip_orig.x = clip_orig.x - displ.coords.x;
	}
	if(clip_orig.y <= displ.coords.y){
		clip_orig.y = Vec2<int>(0,0);
	}
	else{
		clip_orig.y = clip_orig.y - displ.coords.y;
	}

	Vec2<int> clip_end = this->box.orig+this->box.size;
	Vec2<int> chunk_end = displ.coords + displ.graphic.size;

	if(clip_end.x >= chunk_end.x){
		clip_end.x = displ.graphic.size;
	}
	else{
		clip_end.x = clip_end.x - displ.coords.x;
	}
	if(clip_end.y >= chunk_end.y){
		clip_end.y = displ.graphic.size;
	}
	else{
		clip_end.y = clip_end.y - displ.coords.y;
	}

	Vec2<int> proj = this->box.orig - displ.coords;						/* vector from view orig to bottom left bloc of chunk in Y up coords */

	proj = Vec2<int>(this->box.size.y,0) - proj;							/* same in Y down (ncurses) coords */


	for(int i = clip_orig.y; i < clip_end.y; i++){

		for(int j = clip_orig.x; j < clip_end.x; j++){

			displ.graphic[i][j].display(proj+Vec2<int>(i,j));

		}

	}


}
