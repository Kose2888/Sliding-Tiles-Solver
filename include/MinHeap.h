#ifndef MINHEAP_H
#define MINHEAP_H

#include <string>
#include <iostream>
#include <vector>
#include "Board_Tile.h"

class MinHeap {
 public:
  MinHeap(const std::vector<Board_Tile> & initialItems);
  
  void insert(const Board_Tile key);

  Board_Tile deleteMin();
  
  bool isEmpty();
  
 private:
  int size;
  std::vector<Board_Tile> array;
  
  int percolateUp(int hole, Board_Tile val);
  int percolateDown(int hole, Board_Tile val);
};
#endif //MINHEAP_H