#ifndef MINHEAP_H
#define MINHEAP_H

#include <string>
#include <iostream>
#include <vector>
#include "Board_Tile.h"

class MinHeap {
 public:
  MinHeap(const std::vector<int> & initialItems);
  
  void insert(const int key);
  
  int deleteMin();
  
  bool isEmpty();
  
 private:
  int size;
  std::vector<int> array;
  
  int percolateUp(int hole, int val);
  int percolateDown(int hole, int val);
};
#endif //MINHEAP_H