#include <iostream>
#include "SegmentTree.h"

using namespace std;

int main(){
  // This calculates the Minimum of a range.
  SegmentTree<int, std::function<int (int, int)>> seg;
  int arr[] = {1,2,3,4,5};
  int s = 0;
  int e = 4;

  // Init Segment Tree.
  seg.InitSegmentTree(arr, s, e, [](int a,int b) -> int { return a<b ? a : b; });

  //Print the segment tree.
  std::cout << "Printing the segment Tree" << std::endl;
  seg.PrintSegmentTree();
  std::cout  << std::endl;

  // Find minimum in ranges.
  std::cout << "Range Queries" << std::endl;
  std::cout << seg.PrintComputedValue(0,4) << std::endl;
  std::cout << seg.PrintComputedValue(0,2) << std::endl;
  std::cout << seg.PrintComputedValue(1,1) << std::endl;
  std::cout << std::endl;

  // Update the value.
  seg.UpdateSegmentTree(0,10);
  seg.UpdateSegmentTree(4,15);

  // Find minimum in ranges.
  std::cout << "Range Queries" << std::endl;
  std::cout << seg.PrintComputedValue(0,4) << std::endl;
  std::cout << seg.PrintComputedValue(0,2) << std::endl;
  std::cout << seg.PrintComputedValue(1,1) << std::endl;
  std::cout << std::endl;

  //Print the segment tree.
  std::cout << "Printing the segment Tree" << std::endl;
  seg.PrintSegmentTree();
  std::cout << std::endl;

  return 0;
}
