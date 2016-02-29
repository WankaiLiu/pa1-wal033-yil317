#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <utility> // for std::pair

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or nullptr if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;


public:

  /** iterator is an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0)  {
  }


  /** Default destructor.
   *  It is virtual, to allow appropriate destruction of subclass objects.
   *  Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
    this -> clear(); // Call function clear in the same class.
  }

  /** Insert a Data item in the BST.
   *  Return a pair, with the pair's first member set to an
   *  iterator pointing to either the newly inserted element
   *  or to the equivalent element already in the set.
   *  The pair's second element is set to true
   *  if a new element was inserted or false if an
   *  equivalent element already existed.
   */ // TODO
  virtual std::pair<iterator,bool> insert(const Data& item) {
    BSTNode<Data>*  cur;     // Pointer to the current node in BST.
    BSTNode<Data>*  cur2;    // Pointer to the new node in BST.
    bool second;             // The second returning value.(1 means successful inserting and 0 means not.)
    second = 1;
    cur2 = new BSTNode<Data>(item);                  // Create a new node with data equal to item.
    if (this->root == nullptr && second == 1)        // If the root is null, assign cur2 to root.
      this->root = cur2; 
    else{ 	
      cur = this-> root;
      while (1) {                                    // Find the proper postion for cur2.
	if (cur -> data == item){                    // If the value is already in the tree, return false.
	  second = 0;
	  break;
	}
	else if (cur -> data > item){      // Execute when the item is less than the data of current node.
	  if (cur -> left != nullptr){     // If its left child is not null, then current node move to its left child.			
	    cur = cur -> left;}           
	  else {                           // If its left child is null, then insert the new node to the left child of current node.	
	    cur -> left = cur2;           
	    cur2 -> parent = cur;
	    break; 
	  }
	}
	else {
	  if (cur -> right != nullptr){	   // Execute when the item is greater than the data of current node.		
	    cur = cur -> right;}           // If its right child is not null, then current node move to its right child.	
	  else {
	    cur -> right = cur2;           // If its right child is null, then insert the new node to the right child of current node.
	    cur2 -> parent = cur;
	    break; 
	  }
	}
      }
    }
    if (second == 1){   // If the new node is inserted successfully, iszie is increased by 1.
      isize++;
    }
    std::pair<iterator,bool> pair1 (typename BST<Data>::iterator(cur2),second);
    return pair1;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ // TODO
  iterator find(const Data& item) const {
    BSTNode<Data>* cur;
    if (this -> root == nullptr)           // If the root is a nullpointer, return a nullpointer.
      return iterator(nullptr);
    cur = this->root;                      // Otherwise, root is assigned for the current node.
    while (cur -> data != item) {
      if (cur -> data > item){             // If item is less than the data of current node, then check the left child of current node.
	if (cur -> left == nullptr) {
	  return iterator(nullptr);
	}
	cur = cur -> left;
      }
      else {
	if (cur -> right == nullptr) {    // If item is greater than the data of current node,then check the right child of current node.
	  return iterator(nullptr);
	}
	cur = cur -> right;
      }
    }
    return typename BST<Data>::iterator(cur);// Retrun current node with iterator type.
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
    return isize;
  }

  /** Remove all elements from this BST, and destroy them,
   *  leaving this BST with a size of 0.
   */ // TODO
  void clear() {
    this->deletenode(root);                //Call the delte function below.
  }
  void deletenode(BSTNode<Data>* cur){     //Recursively use detenode function to delet the nodes in BST.
    if (cur == nullptr){
      return;
    }
    deletenode(cur->left);
    deletenode(cur->right);
    delete cur;
    isize--;
  }	  

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
    if ( this -> root == nullptr){
      return 1;
    }
    else {
      return 0;
    }
  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO
  iterator begin() const {                // Find the first element in the BST.
    BSTNode<Data>* cur;
    cur = this-> root;
    while (cur -> left != nullptr) 
      cur = cur -> left;
    return typename BST<Data>::iterator(cur);
  }	

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(nullptr);// Find the final element in the BST.
  }

  

};


#endif //BST_HPP
