#include <iostream>
#include <string>

#include "Board_Tile.h"

Board_Tile::Board_Tile(const std::string &s)
{
    if (s.size() != 9)
        std::cout << "Invalid Input, must enter a tile of size 9" << std::endl;
    else
        config = s;
    movesFromStart = "";
}

std::string Board_Tile::getConfig()
{
    return config;
}

void Board_Tile::displayBoard()
{
    int k = -1;
    for (int i = 0; i < 3; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < 3; j++)
        {
            k++;
            std::cout << config[k] << " ";
        }
    }
}

std::vector<Board_Tile> Board_Tile::nextConfigs()
{
    std::vector<Board_Tile> vec = {};
    std::size_t found = config.find('0');
    char atFound = config[found];

    if (found >= 3 && found <= 8) //  Move Up
    {
        std::string configUp = config;
        char temp = configUp[found - 3];

        configUp.replace((found - 3), 1, 1, atFound);
        configUp.replace(found, 1, 1, temp);

        Board_Tile boardMUp(configUp);
        boardMUp.movesFromStart.append("U");
        vec.push_back(boardMUp);
    }
    if (found >= 0 && found <= 5) //  Move Down
    {
        std::string configDown = config;
        char temp = configDown[found + 3];

        configDown.replace((found + 3), 1, 1, atFound);
        configDown.replace(found, 1, 1, temp);

        Board_Tile boardMDown(configDown);
        boardMDown.movesFromStart.append("D");
        vec.push_back(boardMDown);
    }
    if (found != 0 && found != 3 && found != 6) //  Move Left
    {
        std::string configLeft = config;
        char temp = configLeft[found - 1];

        configLeft.replace((found - 1), 1, 1, atFound);
        configLeft.replace(found, 1, 1, temp);

        Board_Tile boardMLeft(configLeft);
        boardMLeft.movesFromStart.append("L");
        vec.push_back(boardMLeft);
    }
    if (found != 2 && found != 5 && found != 8) //  Move Right
    {
        std::string configRight = config;
        char temp = configRight[found + 1];

        configRight.replace((found + 1), 1, 1, atFound);
        configRight.replace(found, 1, 1, temp);

        Board_Tile boardMRight(configRight);
        boardMRight.movesFromStart.append("R");
        vec.push_back(boardMRight);
    }
    return vec;
}

int Board_Tile::getDST()
{
    return DST;
}

int Board_Tile::numMoves()
{
    return movesFromStart.length();
}

int Board_Tile::Manhattan_Distance(const Board_Tile &goalconfig)
{
    int d = 0;
    for (int i = 0; i < config.length(); i++)
    {
        if (this->config[i] != goalconfig.config[i])
            d += 1;
    }
    return d - 1;
}

void Board_Tile::operator=(const Board_Tile & in) {
    this->config = in.config;
    this->movesFromStart = in.movesFromStart;
}

std::string Board_Tile::getMoves() {
    return movesFromStart;
}

bool Board_Tile::operator==(const Board_Tile & comp) {
    return this->config.compare(comp.config);
}