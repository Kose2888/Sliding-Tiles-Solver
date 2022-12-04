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

private:
    std::string config, movesFromStart;
};

#endif