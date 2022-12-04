#include <iostream>

#include "Board_Tile.h"
#include "Sliding_Solver.h"

int main()
{
  std::string str = "";

  std::cout << "Enter board configuration(3x3): ";
  std::cin >> str;
  Board_Tile board(str);

  board.displayBoard();
  std::cout << "\n";

  std::vector<Board_Tile> list = board.nextConfigs();

  for (int i = 0; i < list.size(); i++)
  {
    list[i].displayBoard();
    std::cout << "\n";
  }

  return 0;
}
