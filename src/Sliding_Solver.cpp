#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <iomanip>

#include "Board_Tile.h"
#include "BoardComparitor.h"
#include "Sliding_Solver.h"

Sliding_Solver::Sliding_Solver(std::string initialConfig, std::string goal) : goalConfig(goal)
{
    tileQueue.push(Board_Tile(initialConfig));
}

void Sliding_Solver::Solve_Puzzle()
{
    bool solved = false;

    Board_Tile check = tileQueue.top();
    Board_Tile display = tileQueue.top();

    if (check.Manhattan_Distance(goalConfig) == -1)
        solved = true;

    while (!solved)
    {
        std::vector<Board_Tile> list = check.nextConfigs();
        for (Board_Tile b : list)
        {
            int DST = b.Manhattan_Distance(goalConfig) + b.numMoves();
            b.setDST(DST);
            tileQueue.push(b);
        }

        check = tileQueue.top();
        tileQueue.pop();

        if (check.Manhattan_Distance(goalConfig) == -1)
            solved = true;
    }

    std::cout << std::setfill(' ');
    std::cout << std::left << std::setw(15) << "Start Board"
              << std::left << std::setw(15) << "Goal Board"
              << std::left << std::setw(20) << "Number of Moves"
              << std::right << std::setw(10) << "Solution\n"
              << std::endl;

    std::cout << std::left << std::setw(15) << display.getConfig()
              << std::left << std::setw(15) << check.getConfig()
              << std::left << std::setw(21) << check.numMoves()
              << std::left << std::setw(10) << check.getMoves()
              << std::endl;
}