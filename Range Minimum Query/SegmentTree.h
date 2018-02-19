#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#include <iostream>

template<class T>
struct node{
  T data; // data in the segment tree
  node* left; // pointer to the left node
  node* right; // pointer to the right node
  int index; // index in the generic array description of the segment tree
};

template<class T,class Comparator>
class SegmentTree{
private:

  // pointer to the top node of the segment tree
  node<T>* HeadNode;
  int startIndex;
  int endIndex;
  Comparator ComparisonFunction; // The comparsion function on the basis of which nodes are merged.

  // function to create the segment tree.
  node<T>* CreateTree(T arr[],int s,int e, int index){
    if(s==e){
      // Reached the leaf node.
      node<T>* temp = new node<T>;
      temp->left = NULL;
      temp->right = NULL;
      temp->data = arr[s];
      temp->index = index;
      return temp;
    }
    int mid = (s+e)/2;
    node<T>* temp = new node<T>;
    // Recur for the left.
    node<T>* left =  CreateTree(arr, s, mid,2*index+1);
    // Recur for the right.
    node<T>* right = CreateTree(arr, mid+1, e, 2*index+2);
    // Add value at the node on the basis of the comparison function.
    temp->data = ComparisonFunction(left->data,right->data);
    temp->left = left;
    temp->right = right;
    temp->index = index;
    return temp;
  }

  // function to check if the tree is correctly built
  void PrintTree(node<T>* start){
    if(start->right!=NULL)
      PrintTree(start->right);
    if(start->left!=NULL)
      PrintTree(start->left);
    std::cout << start->index << ' ' << start->data << std::endl;
  }


  T ComputeValue(node<T>* start, int s,int e,int l,int r){
    // If out of range return 0.
    if(r<s || e<l) {
      return 1e6;
    }
    // If in range return data at node.
    if(l<=s && e<=r){
      return start->data;
    }
    // Recur for both the sides.
    int mid = (s+e)/2;
    T p1 = ComputeValue(start->left, s, mid, l, r);
    T p2 = ComputeValue(start->right, mid+1, e, l, r);
    return ComparisonFunction(p1,p2);
  };

  void UpdateValue(node<T>* start,int s,int e,int newIndex,int val){
    // If at leaf node update the value.
    if(s==e) {
      start->data = val;
    }
    else {
      int mid = (s + e)/2;
      // Recur for left if newIndex is in left range else go for right.
      if(s <= newIndex and newIndex <= mid) {
            UpdateValue(start->left, s, mid, newIndex, val);
        }
        else {
            UpdateValue(start->right, mid+1, e, newIndex, val);
        }
        start->data = ComparisonFunction(start->left->data,start->right->data);
    }
  }

public:
  void InitSegmentTree(T arr[], int s, int e, Comparator compareFunction);
  void PrintSegmentTree();
  T PrintComputedValue(int l,int r);
  void UpdateSegmentTree(int index,int val);
};

template<class T,class Comparator>
void SegmentTree<T, Comparator> :: InitSegmentTree(T arr[], int s,int e, Comparator compareFunction){
  startIndex = s;
  endIndex = e;
  ComparisonFunction = compareFunction;
  HeadNode = CreateTree(arr, s , e, 0);
}

template<class T,class Comparator>
void SegmentTree<T, Comparator> :: PrintSegmentTree(){
  PrintTree(HeadNode);
}

template<class T,class Comparator>
T SegmentTree<T, Comparator> :: PrintComputedValue(int l,int r){
  return ComputeValue(HeadNode, startIndex, endIndex, l, r);
}

template<class T,class Comparator>
void SegmentTree<T, Comparator> :: UpdateSegmentTree(int index,int val){
  UpdateValue(HeadNode, startIndex, endIndex, index, val);
}

#endif
