#include <terrain.h>


Terrain::Terrain(){

}

void Terrain::moveload(Chunk chunk, Vec2<int> coords){
	chunk.coords = coords;
	load(chunk);

}
void Terrain::loadAround(Vec2<int> chunk_coords) {									/* chunk_coords is in world coords */
	Vec2<int> *ldmid = new Vec2<int>(DRAW_DISTANCE,DRAW_DISTANCE);		/* center of loaded chunks (in that struct coords) */
	Chunk mid_chunk = ldchunks[ldmid->x][ldmid->y];										/* center chunk of loaded chunks */
	moveload(mid_chunk,chunk_coords);

	Vec2<int> *mv = new Vec2<int>(0,0);
	for(int dist=0;dist<DRAW_DISTANCE;dist++){												/* loads every chunk at dist < DRAW_DISTANCE */
		for(int i=0;i<dist;i++){
			mv->x = dist - i;
			mv->y = 0 + i;
			moveload(ldchunks[mv->x+ldmid->x][mv->y+ldmid->y],*mv+chunk_coords);
			moveload(mid_chunk,chunk_coords);
			moveload(mid_chunk,chunk_coords);
			moveload(mid_chunk,chunk_coords);

		}
	}
}
