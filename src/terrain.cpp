#include <terrain.h>
#include <chunk.h>
#include <bloc.h>

Terrain::Terrain(){

}

void Terrain::load(Chunk& chunk){
	for(int i=0;i<chunk.size(0);i++){
		for(int j=0;j<chunk.size(1);j++){
			if(j > 35){
				chunk.graphic[i][j] = Bloc(' ');
			}
			else {
				chunk.graphic[i][j] = Bloc(77+(i%2)*2);
			}
		}
	}
}
