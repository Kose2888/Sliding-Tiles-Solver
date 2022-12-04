#ifndef MINHEAP_H
#define MINHEAP_H

#include <string>
#include <iostream>
#include <vector>
#inlcude "Board_Tile.h"

class MinHeap {
 public:
  MinHeap(const std::vector<int> & initialItems);
  
  void insert(Board_Tile key);
  
  std::string deleteMin();
  
  bool isEmpty();
  
 private:
  int size;
  int array;
  
  void perculateUp(int hole, int val);
  void perculateDown(int hole, int val);
};
#endif //MINHEAP_H
