#include <chunk.h>



Eigen::Vector2i Chunk::size = Vector2i(CHUNK_SIZE,MAX_HEIGHT);

int Chunk::ground_y(int x){

	int y = 0;

	while (this->graphic[x][y].ch != ' '){
		y++;
	}
	return y;

}
