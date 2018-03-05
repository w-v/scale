#include <terrain.h>
#include <chunk.h>
#include <bloc.h>

Terrain::Terrain(){

}

void Terrain::load(Chunk& chunk){
	for(int i=0;i<chunk.size(0);i++){
		for(int j=0;j<chunk.size(1);j++){
			chunk.graphic[i][j] = Bloc('M');
		}
	}
}
