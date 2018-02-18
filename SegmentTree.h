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

template<class T>
class SegmentTree{
private:

  // pointer to the top node of the segment tree
  node<T>* HeadNode;
  int startIndex;
  int endIndex;

  // function to create the segment tree.
  node<T>* CreateTree(T arr[],int s,int e, int index){
    if(s==e){
      node<T>* temp = new node<T>;
      temp->left = NULL;
      temp->right = NULL;
      temp->data = arr[s];
      temp->index = index;
      return temp;
    }
    int mid = (s+e)/2;
    node<T>* temp = new node<T>;
    node<T>* left =  CreateTree(arr, s, mid,2*index+1);
    node<T>* right = CreateTree(arr, mid+1, e, 2*index+2);
    temp->data = left->data + right->data;
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


  T RangeSum(node<T>* start, int s,int e,int l,int r){
    if(r<s || e<l) {
      return 0;
    }
    if(l<=s && e<=r){
      return start->data;
    }
    int mid = (s+e)/2;
    T p1 = RangeSum(start->left, s, mid, l, r);
    T p2 = RangeSum(start->right, mid+1, e, l, r);
    return p1+p2;
  };

  void UpdateValue(node<T>* start,int s,int e,int newIndex,int val){
    if(s==e) {
      start->data = val;
    }
    else {
      int mid = (s + e)/2;
      if(s <= newIndex and newIndex <= mid) {
            UpdateValue(start->left, s, mid, newIndex, val);
        }
        else {
            UpdateValue(start->right, mid+1, e, newIndex, val);
        }
        start->data = start->left->data + start->right->data;
    }
  }

public:
  void InitSegmentTree(T arr[], int s, int e);
  void PrintSegmentTree();
  T PrintRangeSum(int l,int r);
  void UpdateSegmentTree(int index,int val);
};

template<class T>
void SegmentTree<T> :: InitSegmentTree(T arr[], int s,int e){
  startIndex = s;
  endIndex = e;
  HeadNode = CreateTree(arr, s , e, 0);
}

template<class T>
void SegmentTree<T> :: PrintSegmentTree(){
  PrintTree(HeadNode);
}

template<class T>
T SegmentTree<T> :: PrintRangeSum(int l,int r){
  return RangeSum(HeadNode, startIndex, endIndex, l, r);
}

template<class T>
void SegmentTree<T> :: UpdateSegmentTree(int index,int val){
  UpdateValue(HeadNode, startIndex, endIndex, index, val);
  return ;
}

#endif
