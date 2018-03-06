#include <view.h>
#include <ncurses.h>



View::View(Entity& fol)
	: followed(fol)
{
	Vector2i win_size;
	getmaxyx(stdscr, win_size.y(), win_size.x());
	coords << (fol.coords - (win_size / 2)),
						(fol.coords + (win_size / 2));

	update_lim = Vector2i(5,5);

	y_down_transf = Vector2i(0,win_size.y());
}

void View::draw(World& world){

	this->draw(world.area);
	this->draw(world.player);
}

void View::draw(Area& area){

	for(int i = 0; i < area.size(); i++){


		draw(area[i]);

	}


}

void View::draw(Displayable& d){


	Vector2i dend = d.coords + d.graphic.size;


	Vector2i clip_orig = d.coords.cwiseMax(this->coords.col(0));
	Vector2i clip_end = dend.cwiseMin(this->coords.col(1));

	Vector2i vorig = clip_orig - this->coords.col(0);

	clip_orig = clip_orig - d.coords;
	clip_end = clip_end - d.coords;

	//mvprintw(1,0,"clip_orig : (%d,%d), clip_end : (%d,%d)",clip_orig.x(),clip_orig.y(),clip_end.x(), clip_end.y() );
	Vector2i proj = vorig;

	// TODO :
	//													 '=' is needed there for chunks to load top line of view, should not
	for(int i = clip_orig.y(); i <  clip_end.y(); i++){

		for(int j = clip_orig.x(); j < clip_end.x(); j++){

			display(d.graphic[j][i], proj);

			proj(0)= proj(0)+1;

		}

		proj(0) = vorig.x();
		proj(1) = proj(1)+1;

	}


}

void View::display(Char& c, Vector2i& v){
		// TODO : adjust to y down
    //mvprintw(2,0,"displaying %c at y : %d, x : %d", c.ch, v.y(), v.x());
    wmove(stdscr,y_down_transf.y()-v.y(),v.x());
    addch(c.ch);

}
void View::update(){
	Vector2i mov;

	Matrix2i a;
	a << update_lim,-update_lim;
	coords += a;

	mov = ( coords.col(1) - followed.coords.cwiseMax(coords.col(1)) )
			- ( coords.col(0) - followed.coords.cwiseMin(coords.col(0)) );

	a << -update_lim+mov, update_lim+mov;

	coords += a;
}

/*void View::clip(Displayable displ){

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

	Vec2<int> proj = this->box.orig - displ.coords;					*/	/* vector from view orig to bottom left bloc of chunk in Y up coords */
/*
	proj = Vec2<int>(this->box.size.y,0) - proj;							/* same in Y down (ncurses) coords */

/*
	for(int i = clip_orig.y; i < clip_end.y; i++){

		for(int j = clip_orig.x; j < clip_end.x; j++){

			displ.graphic[i][j].display(proj+Vec2<int>(i,j));

		}

	}


}
*/
