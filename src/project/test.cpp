#include <iostream>

#include "Board_Tile.h"
#include "Sliding_Solver.h"

int main()
{
  std::string str = "";
  std::string gconfig = "";

  std::cout
      << "Enter board configuration(3x3): ";
  std::cin >> str;
  Board_Tile board(str);

  std::cout << "Enter goal configuration: ";
  std::cin >> gconfig;
  Board_Tile goalBoard(gconfig);

  board.displayBoard();
  std::cout << "\n";

  std::vector<Board_Tile> list = board.nextConfigs();

  for (int i = 0; i < list.size(); i++)
  {
    list[i].displayBoard();
    std::cout << "\n"
              << list[i].Manhattan_Distance(goalBoard);
    std::cout << "\n";
  }

  return 0;
}
