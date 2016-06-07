#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


/*bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}*/

bool BST::search (const int & item) const
{
	return searchAux(myRoot, item);
}

bool BST::searchAux(BinNode * subtreeRoot, const int & item) const
{
	if (subtreeRoot == 0)
		return false; // no subtree here
	else if (item < subtreeRoot->data) //look in left subtree
		return searchAux(subtreeRoot->left, item);
	else if (item > subtreeRoot->data) //look in right subtree
		return searchAux(subtreeRoot->right, item);
	else //item is found in subtree Root
		return true;
}

void BST::inorder(ostream & out) const {
	inorderAux(out, myRoot);
	out << "\n";
}

void BST::inorderAux(ostream & out, BinNode * subtreeRoot) const {
	
	if (subtreeRoot !=0)
	{	
		inorderAux(out, subtreeRoot->left);
		out << subtreeRoot->data<< " ";
		inorderAux(out, subtreeRoot->right);
	}
}

void BST::preorder(ostream & out) const {
	preorderAux(out, myRoot);
	out << "\n";
}

void BST::preorderAux(ostream & out, BinNode * subtreeRoot) const {
	
	if (subtreeRoot !=0)
	{	
		out << subtreeRoot->data<< " ";
		preorderAux(out, subtreeRoot->left);	
		preorderAux(out, subtreeRoot->right);	
	}
}

int BST::nodeCount(){
	return nodeCountAux(myRoot, 0);
}

int BST::nodeCountAux(BinNode * subtreeRoot, int count) {

	if (subtreeRoot !=0){
		count++;//count current root node
		count=nodeCountAux(subtreeRoot->left, count); //count left subtree nodes
		count=nodeCountAux(subtreeRoot->right, count); //count right subtree nodes
	}
	return count;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}