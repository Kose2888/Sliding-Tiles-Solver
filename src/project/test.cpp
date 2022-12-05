#include <iostream>
#include <queue>

#include "Board_Tile.h"
#include "Sliding_Solver.h"
#include "BoardComparitor.h"

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

  std::priority_queue <Board_Tile, std::vector<Board_Tile>, BoardComparitor > pq;

  int c = 1;

  for (Board_Tile b : list) {
      b.setDST(c++);
      pq.push(b);
  }

  Board_Tile tile = pq.top();

  tile.displayBoard();

  pq.pop();

  return 0;
}
