
#ifndef SearchTree_hpp
#define SearchTree_hpp
#include "Tree.hpp"
#include <iostream>
using namespace std;


template <class T>
class SearchTree : public Tree<T>
{
public:
	// protocol for search trees
	void add(T value)override;
	bool  search(T value)override 
	{
		return search(Tree<T>::root, value);
	}
	T Successor(T val){	return Successor(findValue(Tree<T>::root, val))->value;};
	void deleteDuplicates() { deleteDuplicates(Tree<T>::root); }
    void remove(T val){	remove(findValue(Tree<T>::root,val));}



private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val)const;
    typename Tree<T>::Node* findValue(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* minValue(typename Tree<T>::Node* current);


	void remove(typename Tree<T>::Node* current);
	typename Tree<T>::Node* Successor(typename Tree<T>::Node* current);
	typename Tree<T>::Node* parent(typename Tree<T>::Node* current);
	void deleteDuplicates(typename Tree<T>::Node*& current);
};


template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)const
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)
		// add to right subtree
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else
		// add to left subtree
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

//my added functions

template <class T>
void SearchTree<T>::remove(typename Tree<T>::Node* current)
{
    //base case will return
	if (!current)
	{
		return;
	}

	typename Tree<T>::Node* nodeToDelete;
    typename Tree<T>::Node* nodeToSwitch;
    typename Tree<T>::Node* p;

    //No children
	if (!current->left || !current->right)
	{
		nodeToDelete = current;
	}
    //at least one child
	else
	{
		nodeToDelete = Successor(current);
	}


    //if one child 
    //if intendended deleted value has a right, successor is set to right 
	if (!nodeToDelete->left)
	{
		nodeToSwitch = nodeToDelete->right;
	}
//    //if intendended deleted value has a left, successor is set to left 

	else
	{
		nodeToSwitch = nodeToDelete->left;
	}

    //find parent of the value intended to delete - we have to point it to its new child
	p = parent(nodeToDelete);

    //if parent is null, we are dealing with the root
	if (!p)
	{
		Tree<T>::root = nodeToSwitch;
	}
    

    //if deleted value is a left child  - left will be set to successor 
	else if (p->left == nodeToDelete)
	{
		p->left = nodeToSwitch;
	}

    //if deleted value is a right child - left will be set to successor
	else
	{
		p->right = nodeToSwitch;
	}

    //value is swapped from sucessor
	if (current != nodeToDelete)
	{
		current->value = nodeToDelete->value;
	}

    //the node is deleted
	delete nodeToDelete;
}

//returns the minimum value of a given subtree
template <class T>
typename Tree<T>::Node* SearchTree<T>::minValue(typename Tree<T>::Node* current)
{
    //base case-> the left most is a nullptr
    if (!current->left)
	{
		return current;
	}

	//recursively itterates the left most node - which is the minimum value

	return minValue(current->left);
}




//succcessor which recieves a node pointer
template <class T>
typename Tree<T>::Node* SearchTree<T>::Successor(typename Tree<T>::Node* child)
{

    //if passed node is nullptr then it does not have a successor 
	if (!child)
	{
		throw "no successor";
	}


    //if there are duplicate values, then it will be found on the left side of the node and it will become the successor 
	if (child->left)
	{
		if ((child->value) == (child->left->value))
		{
			return child->left;
		}
	}

	//if there is a right subtree, successor is the minimum value of the right subtree
    if (child->right)
	{
		return minValue(child->right);
	}

	typename Tree<T>::Node* p= parent (child);

    //looking for the successor as a ancestor
    //itterate upwards through the tree to find a parent node whose right node is not equal to the child
		while (p && child==p->right)
		{
			child = p;
			p = parent(child);
		}

        //if parent is nullptr, there is no successor
		if (!p)
		{
			throw "no successor";
		}

		//return p as the successor for the last case
		return p;
	

}


//finds a value within the tree and retuns its address
template <class T> 
typename Tree<T>::Node* SearchTree<T>::findValue(typename Tree<T>::Node* current, T val)
{

    //if value is found then address is returned
    //if value is not found a nullptr is returned
	if (!current||current->value == val)
	{
		return current;
	}
	
    //we check the value compared to the value of the current node and itterate through the tree 
	if (val > current->value)
	{
		return findValue(current->right, val);
	}
	return findValue(current->left, val);
}

//returns the parent node to the node passed in the parameter
template <class T>
typename Tree<T>::Node* SearchTree<T>::parent(typename Tree<T>::Node* child)
{
    //the root has no parent
	if (child == Tree<T>::root)
	{
		return nullptr;
	}

    
	typename Tree<T>::Node* p = Tree<T>::root;

    //while the parent right and left nodes do not equal the child 
	while (p->right != child && p->left != child)
	{
        // compare values and itterate appropriately
		if (child->value  > p->value)
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}
	}

    //return p as the parent
	return p;

}

//deletes all duplicate values from the tree

template <class T>
void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node*& current)
{
    //base case
	if (!current)
	{
		return;
	}

	//if the current value exists in the subtree, it is removed
	if(search(current->left,current->value))
	{
		remove(current);

        //recursively checks and deletes if current appears more times in the tree
		deleteDuplicates(current);
		return;
	}
   
    //itterate through each value of the tree
	deleteDuplicates(current->left);
	deleteDuplicates(current->right);

}

#endif