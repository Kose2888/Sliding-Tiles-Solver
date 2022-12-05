#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H

#include <vector>
#include <iostream>
#include <string>
#include <queue>

#include "Board_Tile.h"
#include "BoardComparitor.h"

class Sliding_Solver
{
    std::priority_queue<Board_Tile, std::vector<Board_Tile>, BoardComparitor> tileQueue;
    Board_Tile goalConfig;

public:
    Sliding_Solver(std::string initialConfig, std::string goal);

    void Solve_Puzzle();
};

#endif // SLIDING_SOLVER_H