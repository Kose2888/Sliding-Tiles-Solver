#include <iostream>
#include <string>
#include <vector>

#ifndef BOARD_TILE_H
#define BOARD_TILE_H

class Board_Tile
{
public:
    Board_Tile(const std::string &);

    std::string getConfig();

    void displayBoard();

    std::vector<Board_Tile> nextConfigs();

    int getDST();

    void setDST(int i) { DST = i; }

    int numMoves();

    int Manhattan_Distance(const Board_Tile &goalconfig);

private:
    std::string config, goalconfig, movesFromStart;
    int DST;
};

#endif