#include <iostream>
#include "SegmentTree.h"

using namespace std;

int main(){
  // This calculates the Minimum of a range.
  SegmentTree<int, std::function<int (int, int)>> seg;
  int arr[] = {3,6,11,23,55,23,0,12};
  int s = 0;
  int e = 7;

  // Init Segment Tree.
  seg.InitSegmentTree(arr, s, e, [](int a,int b) -> int { return a<b ? a : b; });

  //Print the segment tree.
  std::cout << "Printing the segment Tree" << std::endl;
  seg.PrintSegmentTree();
  std::cout  << std::endl;

  // Find minimum in ranges.
  std::cout << "Range Queries" << std::endl;
  std::cout << "Minimum value in the range 0-4 is " << seg.PrintComputedValue(0,4) << std::endl;
  std::cout << "Minimum value in the range 0-2 is " << seg.PrintComputedValue(0,2) << std::endl;
  std::cout << "Minimum value in the range 1-1 is " << seg.PrintComputedValue(1,1) << std::endl;
  std::cout << "Minimum value in the range 1-7 is " << seg.PrintComputedValue(1,7) << std::endl;
  std::cout << "Minimum value in the range 3-6 is " << seg.PrintComputedValue(3,6) << std::endl;
  std::cout << "Minimum value in the range 2-5 is " << seg.PrintComputedValue(2,5) << std::endl;
  std::cout << std::endl;

  // Update the value.
  seg.UpdateSegmentTree(0,-2);
  seg.UpdateSegmentTree(4,8);

  std::cout << "Updating the value at node 0 to 10 and at node 4 to 15" << std::endl;

  //Print the segment tree.
  std::cout << std::endl << "Printing the segment Tree" << std::endl;
  seg.PrintSegmentTree();
  std::cout  << std::endl;

  // Find minimum in ranges.
  std::cout << std::endl << "Range Queries" << std::endl;
  std::cout << "Minimum value in the range 0-4 is " << seg.PrintComputedValue(0,4) << std::endl;
  std::cout << "Minimum value in the range 0-2 is " << seg.PrintComputedValue(0,2) << std::endl;
  std::cout << "Minimum value in the range 1-1 is " << seg.PrintComputedValue(1,1) << std::endl;
  std::cout << "Minimum value in the range 1-7 is " << seg.PrintComputedValue(1,7) << std::endl;
  std::cout << "Minimum value in the range 3-6 is " << seg.PrintComputedValue(3,6) << std::endl;
  std::cout << "Minimum value in the range 2-5 is " << seg.PrintComputedValue(2,5) << std::endl;
  std::cout << std::endl;

  return 0;
}
