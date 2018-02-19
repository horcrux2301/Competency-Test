// This is an example implementation for finding the range sum

#include <iostream>
#include "SegmentTree.h"

int main(){

  // A Integer Segment Tree
  SegmentTree<int, std::function<int (int, int)> > seg;
  int arr[] = {4,9,11,4,5,4,10,3};
  int s = 0;
  int e = 7;
  seg.InitSegmentTree(arr, s, e, [] (int a,int b) -> int {return (a+b);});

  //Print the segment tree.
  std::cout << "Printing the segment Tree" << std::endl;
  seg.PrintSegmentTree();
  std::cout << std::endl;

  // Find sum of ranges.
  std::cout << "Range Queries" << std::endl;
  std::cout << "Sum of range between indexes 0-4 is " << seg.PrintComputedValue(0, 4) << std::endl;
  std::cout << "Sum of range between indexes 0-2 is " << seg.PrintComputedValue(0, 2) << std::endl;
  std::cout << "Sum of range between indexes 3-3 is " << seg.PrintComputedValue(3, 3) << std::endl;
  std::cout << "Sum of range between indexes 2-4 is " << seg.PrintComputedValue(2, 4) << std::endl;
  std::cout << "Sum of range between indexes 0-1 is " << seg.PrintComputedValue(0, 1) << std::endl;
  std::cout << std::endl;

  // Update the value.
  seg.UpdateSegmentTree(0,10);
  seg.UpdateSegmentTree(4,15);

  std::cout << std::endl << "Updating value at index 0 to 10 and at index 4 to 15" << std::endl;

  std::cout << "Printing the segment Tree" << std::endl;
  seg.PrintSegmentTree();
  std::cout << std::endl;

  // Find sum of ranges.
  std::cout << std::endl << "Range Queriesa after updating values" << std::endl;
  std::cout << "Sum of range between indexes 0-4 is " << seg.PrintComputedValue(0, 4) << std::endl;
  std::cout << "Sum of range between indexes 0-2 is " << seg.PrintComputedValue(0, 2) << std::endl;
  std::cout << "Sum of range between indexes 3-3 is " << seg.PrintComputedValue(3, 3) << std::endl;
  std::cout << "Sum of range between indexes 2-4 is " << seg.PrintComputedValue(2, 4) << std::endl;
  std::cout << "Sum of range between indexes 0-1 is " << seg.PrintComputedValue(0, 1) << std::endl;
  std::cout << std::endl;


  return 0;
}
