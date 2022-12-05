#include <vector>
#include <iostream>
#include <string>
#include <queue>

#include "Board_Tile.h"
#include "BoardComparitor.h"
#include "Sliding_Solver.h"

Sliding_Solver::Sliding_Solver(std::string initialConfig, std::string goal) : goalConfig(goal) {
    tileQueue.push(Board_Tile(initialConfig));
}

void Sliding_Solver::Solve_Puzzle() {
    bool solved = false;

    Board_Tile check = tileQueue.top();

    if (check.Manhattan_Distance(goalConfig) == -1)
        solved = true;

    while(!solved) {
        std::vector<Board_Tile> list = check.nextConfigs();
        for (Board_Tile b : list) {
            int DST = b.Manhattan_Distance(goalConfig) + b.numMoves();
            b.setDST(DST);
            tileQueue.push(b);
        }

        check = tileQueue.top();

        if(check.Manhattan_Distance(goalConfig) == -1)
            solved = true;
    }

    check.displayBoard();

    std::cout << std::endl;

    std::cout << check.getMoves() << std::endl;
}