#include <iostream>
#include "SegmentTree.h"

int main(){

  // A Integer Segment Tree
  SegmentTree<int> seg;
  int arr[] = {1,2,3,4,5};
  int s = 0;
  int e = 4;
  seg.InitSegmentTree(arr, s, e);
  std::cout << "Printing the segment Tree" << std::endl;
  seg.PrintSegmentTree();
  std::cout << std::endl;
  std::cout << seg.PrintRangeSum(0, 4) << std::endl;
  std::cout << seg.PrintRangeSum(1, 2) << std::endl;
  std::cout << seg.PrintRangeSum(3, 3) << std::endl;
  std::cout << seg.PrintRangeSum(2, 4) << std::endl;
  std::cout << seg.PrintRangeSum(0, 1) << std::endl;
  std::cout << std::endl;
  // int index=2;
  // int val = 100;
  seg.UpdateSegmentTree(2, 10);
  seg.UpdateSegmentTree(4,30);
  std::cout << seg.PrintRangeSum(0, 4) << std::endl;
  std::cout << seg.PrintRangeSum(0, 1) << std::endl;
  std::cout << seg.PrintRangeSum(2, 4) << std::endl;
  //Integer endl

  // A float segment Tree

  SegmentTree<float> segf;
  float arrf[] = {0.3f,1.2f,3.4f,9.9f,100.1f};
  segf.InitSegmentTree(arrf, s, e);
  std::cout << "Printing the segment Tree" << std::endl;
  segf.PrintSegmentTree();
  std::cout << std::endl;
  std::cout << segf.PrintRangeSum(0, 4) << std::endl;
  std::cout << segf.PrintRangeSum(1, 2) << std::endl;
  std::cout << segf.PrintRangeSum(3, 3) << std::endl;
  std::cout << segf.PrintRangeSum(2, 4) << std::endl;
  std::cout << segf.PrintRangeSum(0, 1) << std::endl;
  std::cout << std::endl;
  return 0;
}
