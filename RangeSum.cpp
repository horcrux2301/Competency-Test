#include <iostream>
#include "SegmentTree.h"

int main(){

  // A Integer Segment Tree
  SegmentTree<int, std::function<int (int, int)> > seg;
  int arr[] = {1,2,3,4,5};
  int s = 0;
  int e = 4;
  seg.InitSegmentTree(arr, s, e, [] (int a,int b) -> int {return (a+b);});

  //Print the segment tree.
  std::cout << "Printing the segment Tree" << std::endl;
  seg.PrintSegmentTree();
  std::cout << std::endl;

  // Find sum of ranges.
  std::cout << "Range Queries" << std::endl;
  std::cout << seg.PrintComputedValue(0, 4) << std::endl;
  std::cout << seg.PrintComputedValue(0, 2) << std::endl;
  std::cout << seg.PrintComputedValue(3, 3) << std::endl;
  std::cout << seg.PrintComputedValue(2, 4) << std::endl;
  std::cout << seg.PrintComputedValue(0, 1) << std::endl;
  std::cout << std::endl;

  // Update the value.
  seg.UpdateSegmentTree(0,10);
  seg.UpdateSegmentTree(4,15);

  // Find sum of ranges.
  std::cout << "Range Queries" << std::endl;
  std::cout << seg.PrintComputedValue(0, 4) << std::endl;
  std::cout << seg.PrintComputedValue(0, 2) << std::endl;
  std::cout << seg.PrintComputedValue(3, 3) << std::endl;
  std::cout << seg.PrintComputedValue(2, 4) << std::endl;
  std::cout << seg.PrintComputedValue(0, 1) << std::endl;
  std::cout << std::endl;


  return 0;
}
