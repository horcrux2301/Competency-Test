#include <iostream>
#include "SegmentTree.h"

int main(){

  // A Integer Segment Tree
  SegmentTree<float, std::function<float (float, float)>> seg;
  float arr[] = {1.39f,2.11f,3.08f,4.0f,8.50f};
  int s = 0;
  int e = 4;
  seg.InitSegmentTree(arr, s, e, [](float a,float b) -> float {return (a+b);});

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
