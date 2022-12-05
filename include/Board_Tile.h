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

    void setDST(int i) {DST = i;}

private:
    std::string config, movesFromStart;
    int DST;
};

#endif