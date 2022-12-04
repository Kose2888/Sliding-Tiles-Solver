#include "MinHeap.h"
#include <vector>
#include <string>

MinHeap::MinHeap(const std::vector<int> & initialItems) {
  size = 1;
  array.push_back(0); //empty first slot
  array.push_back(initialItems[0]); //First element
  for (int i = 1; i < initialItems.size(); i++) //for all other elements
    insert(i);
}

bool MinHeap::isEmpty() {
  return size <= 1;
}

void MinHeap::insert(const int key) {
  size++;
  int newPos = perculateUp(size, key);
  array[newPos] = key;
  }
}

int MinHeap:perculateUp(int hole, int key) {
  while (hole > 1 && val < array[hole/2]) {
    array[hole] = array[hole/2];
    hole /= 2;
  }
  return hole;
}

int MinHeap::deleteMin(){
  if (!isEmpty()) {
    int returnVal = array[1];
    size--;
    int newPos = perculateDown(1, array[size+1]);
    array[newPos] = array[size+1];
    return returnVal;
  }
  return 0;
}

int MinHeap::perculateDown(int hole, int val) {
  while(2*hole <= size) {
    int left = 2*hole;
    int right = left+1;
    int target;
    if (right <= size && array[right] < array[left])
      target = right;
    else
      target = left;
    
    if (array[target] < val) {
      array[hole] = array[target];
      hole = target;
    }
    else
      break;
  }
  return hole;
}
