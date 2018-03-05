#ifndef SCALE_CHUNK
#define SCALE_CHUNK

#include <Eigen/Dense>
#include <displayable.h>

#define MAX_HEIGHT	256
#define CHUNK_SIZE 16

using namespace Eigen;

class Chunk : public Displayable {

public:

  static Vector2i size;


};

#endif

