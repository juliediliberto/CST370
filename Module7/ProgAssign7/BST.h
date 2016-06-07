#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void inorder(ostream & out) const;
  void preorder(ostream & out) const;
  int nodeCount();

  
 private:

  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };// end of class BinNode declaration

  // Used to recursively search a binary search tree
  bool searchAux (BinNode * subtreeRoot, const int & item)const;

  // Used to recursively traverse a binary search tree in order

  void inorderAux(ostream & out, BinNode * subtreeRoot) const;

  // Used to recursively traverse a binary search tree in preorder

  void preorderAux(ostream & out, BinNode * subtreeRoot)const;

  // Used to recursively traverse a binary search tree to count the nodes

  int nodeCountAux(BinNode * subtreeRoot, int count);


  
  /***** Data Members *****/
  BinNode * myRoot; 

}; // end of class declaration

#endif