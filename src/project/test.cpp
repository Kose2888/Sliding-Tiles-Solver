#include <iostream>
#include <queue>

#include "Board_Tile.h"
#include "Sliding_Solver.h"
#include "BoardComparitor.h"

int main()
{
  char answer;
  do
  {
    std::string str = "";
    std::string gconfig = "";

    std::cout
        << "Enter board configuration(3x3): ";
    std::cin >> str;

    std::cout << "Enter goal configuration: ";
    std::cin >> gconfig;
    std::cout << std::endl;

    Sliding_Solver s(str, gconfig);

    s.Solve_Puzzle();

    std::cout << "\nAgain(Y/N)? ";
    std::cin >> answer;

  } while (answer == 'Y' || answer == 'y');

  return 0;
}
