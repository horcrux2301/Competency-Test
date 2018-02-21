#define BOOST_TEST_MODULE test
#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include <boost/lexical_cast.hpp>
#include "SegmentTree.h"
#include <vector>
#include <algorithm>
using namespace std;

BOOST_AUTO_TEST_CASE(RangeSumTestCase)
{
  // Create a segment tree
  SegmentTree<long, std::function<long (long, long)> > seg;
  long arr[] = {4,9,11,4,5,4,10,3};
  long s = 0;
  long e = 7;
  seg.InitSegmentTree(arr, s, e, [] (long a,long b) -> long {return (a*b);});

  // Test cases
  vector<pair<long,long> > v;
  v.push_back(make_pair(0,4));
  v.push_back(make_pair(1,3));
  v.push_back(make_pair(5,7));
  v.push_back(make_pair(7,7));
  v.push_back(make_pair(3,7));

  // Checking test cases

  for(int i=0;i<v.size();i++){
    long ComputedValue = seg.PrintComputedValue(v[i].first, v[i].second);
    long tempValue = arr[v[i].first];
    for(int j=v[i].first+1;j<v[i].second+1;j++){
      tempValue*=arr[j];
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
  SegmentTree<long, std::function<long (long, long)> > seg;
  long arr[] = {4,9,11,4,5,4,10,3};
  long s = 0;
  long e = 7;
  seg.InitSegmentTree(arr, s, e, [] (long a,long b) -> long {return (a*b);});


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
  vector<pair<long,long> > v;
  v.push_back(make_pair(0,4));
  v.push_back(make_pair(1,3));
  v.push_back(make_pair(5,7));
  v.push_back(make_pair(7,7));
  v.push_back(make_pair(3,7));

  // Checking test cases

  for(int i=0;i<v.size();i++){
    long ComputedValue = seg.PrintComputedValue(v[i].first, v[i].second);
    long tempValue = arr[v[i].first];
    for(int j=v[i].first+1;j<v[i].second+1;j++){
      tempValue*=arr[j];
    }
    if( ComputedValue != tempValue ){
      std::string error = "Range Test Case Failed on Test Case " + boost::lexical_cast<std::string>(i);
      BOOST_ERROR(error);
    }
  }

}
