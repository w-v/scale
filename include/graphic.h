#ifndef SCALE_GRAPHIC
#define SCALE_GRAPHIC

#include <vector>

using namespace std;

class Graphic {
public:
  Vec2<int> size;
  //char chars[size.y][size.x];
  
  vector<vector<int>> chars;
};

#endif
