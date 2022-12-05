#ifndef SLIDING_TILES_SOLVER_BOARDCOMPARITOR_H
#define SLIDING_TILES_SOLVER_BOARDCOMPARITOR_H

#include "Board_Tile.h"

class BoardComparitor {
 public:
  int operator() (Board_Tile & b1, Board_Tile & b2) {
    return b1.getDST() > b2.getDST();
  }
};

#endif //SLIDING_TILES_SOLVER_BOARDCOMPARITOR_H
