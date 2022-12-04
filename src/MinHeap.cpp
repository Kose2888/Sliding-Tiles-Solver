#include "MinHeap.h"
#include <vector>
#include <string>

MinHeap::MinHeap(const std::vector<Board_Tile> & initialItems) {
  size = 1;
  array.push_back(Board_Tile("000000000")); //empty first slot
  array.push_back(initialItems[0]); //First element
  if (initialItems.size() > 1)
    for (int i = 1; i < initialItems.size(); i++) //for all other elements
      insert(initialItems[i]);
}

bool MinHeap::isEmpty() {
  return size < 1;
}

void MinHeap::insert(const Board_Tile key) {
  size++;
  int newPos = percolateUp(size, key);
  array[newPos] = key;
}

int MinHeap::percolateUp(int hole, Board_Tile val) {
  while (hole > 1 && val.getDST() < array[hole/2].getDST()) {
    array[hole] = array[hole/2];
    hole /= 2;
  }
  return hole;
}

Board_Tile MinHeap::deleteMin(){
  if (!isEmpty()) {
    Board_Tile returnVal = array[1];
    size--;
    int newPos = percolateDown(1, array[size+1]);
    array[newPos] = array[size+1];
    return returnVal;
  }
  return Board_Tile("000000000");
}

int MinHeap::percolateDown(int hole, Board_Tile val) {
  while(2*hole <= size) {
    int left = 2*hole;
    int right = left+1;
    int target;
    if (right <= size && array[right].getDST() < array[left].getDST())
      target = right;
    else
      target = left;
    
    if (array[target].getDST() < val.getDST()) {
      array[hole] = array[target];
      hole = target;
    }
    else
      break;
  }
  return hole;
}
