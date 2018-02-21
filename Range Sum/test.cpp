#define BOOST_TEST_MODULE test
#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include <boost/lexical_cast.hpp>
#include "SegmentTree.h"
#include <vector>
#include <algorithm>

BOOST_AUTO_TEST_CASE(RangeSumTestCase)
{
  // Create a segment tree
  SegmentTree<int, std::function<int (int, int)> > seg;
  int arr[] = {4,9,11,4,5,4,10,3};
  int s = 0;
  int e = 7;
  seg.InitSegmentTree(arr, s, e, [] (int a,int b) -> int {return (a+b);});

  // Test cases
  std::vector<std::pair<int,int> > v;
  v.push_back(std::make_pair(0,4));
  v.push_back(std::make_pair(1,3));
  v.push_back(std::make_pair(5,7));
  v.push_back(std::make_pair(7,7));
  v.push_back(std::make_pair(3,7));

  // Checking test cases

  for(int i=0;i<v.size();i++){
    int ComputedValue = seg.PrintComputedValue(v[i].first, v[i].second);
    int tempValue = 0;
    for(int j=v[i].first;j<v[i].second+1;j++){
      tempValue+=arr[j];
    }
    if( ComputedValue != tempValue ){
      std::string error = "Range Test Case Failed on Test Case " + boost::lexical_cast<std::string>(i);
      BOOST_ERROR(error);
    }
  }
}


BOOST_AUTO_TEST_CASE(RangeSumTestCaseAfterUpdate)
{
  // Create a segment tree
  SegmentTree<int, std::function<int (int, int)> > seg;
  int arr[] = {4,9,11,4,5,4,10,3};
  int s = 0;
  int e = 7;
  seg.InitSegmentTree(arr, s, e, [] (int a,int b) -> int {return (a+b);});


  //Updated the values
  seg.UpdateSegmentTree(0,-4);
  seg.UpdateSegmentTree(4,15);
  seg.UpdateSegmentTree(7,91);

  // Updating the array. If you comment the lines below
  // errors will be shown on all the test cases below.
  arr[0]=-4;
  arr[4]=15;
  arr[7]=91;

  // Test cases
  std::vector<std::pair<int,int> > v;
  v.push_back(std::make_pair(0,4));
  v.push_back(std::make_pair(1,3));
  v.push_back(std::make_pair(5,7));
  v.push_back(std::make_pair(7,7));
  v.push_back(std::make_pair(3,7));

  // Checking test cases

  for(int i=0;i<v.size();i++){
    int ComputedValue = seg.PrintComputedValue(v[i].first, v[i].second);
    int tempValue = 0;
    for(int j=v[i].first;j<v[i].second+1;j++){
      tempValue+=arr[j];
    }
    if( ComputedValue != tempValue ){
      std::string error = "Range Test Case Failed on Test Case " + boost::lexical_cast<std::string>(i);
      BOOST_ERROR(error);
    }
  }

}
