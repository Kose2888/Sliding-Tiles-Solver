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

    std::string getMoves();

    void displayBoard();

    std::vector<Board_Tile> nextConfigs();

    int getDST();

    void setDST(int i) { DST = i; }

    int numMoves();

    int Manhattan_Distance(const Board_Tile &goalconfig);

    void operator=(const Board_Tile & in);

    bool operator==(const Board_Tile & comp);

private:
    std::string config, movesFromStart;
    int DST;
};

#endif