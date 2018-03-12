#include <terrain.h>
#include <chunk.h>
#include <bloc.h>
#include <math.h>

Terrain::Terrain(){

}

void Terrain::load(Chunk& chunk){
	for(int i=0;i<chunk.size(0);i++){
		for(int j=0;j<chunk.size(1);j++){
			if(j > (sin(((double)(i+chunk.coords.x()))/75)*10) + (sin(((double)(i+chunk.coords.x()))/15)*3)+30 ){
				chunk.graphic[i][j] = Bloc(' ');
			}
			else {
				chunk.graphic[i][j] = Bloc(77+(i%2)*2);
			}
		}
	}
}
