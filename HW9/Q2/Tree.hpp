//
//  Tree.hpp
//  BST
//
//  Created by Avi Soclof on 6/01/22.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <iostream>
#include "QueueVector.hpp"
#include "Queue.hpp"
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
    //--------------------------------------------------------
    //  inner class Node
    //      a single Node from a binary tree
    //--------------------------------------------------------
    class Node
    {
    public:
        Node* left;
        Node* right;
        T value;
        Node(T val) : value(val), left(NULL), right(NULL) {}
        Node(T val, Node* l, Node* r): value(val), left(l), right(r) {}
    };        //end of Node class

    //data member of tree
    Node* root;

public:
    Tree() { root = NULL; }     // initialize tree
    ~Tree();
    int isEmpty() const;
    void clear() { clear(root); root = NULL; }
    void preOrder() { preOrder(root); }
    void inOrder() { inOrder(root); }
    void postOrder() { postOrder(root); }

    virtual void process(T val) { cout << val << " "; }
    virtual void add(T val) = 0;
    virtual bool search(T val) = 0;
    virtual void remove(T val) = 0;
    
    //Personally added functions
    int height() {return height(root);}
    int height (Node*);
    
    void reflect(){reflect(root);}
    void reflect(Node*);
    
    void breadthScan();

private:
    //private function for not give acsses to user
    void  clear(Node* current);
    void  preOrder(Node* current);
    void  inOrder(Node* current);
    void  postOrder(Node* current);

};

//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
    if (root != NULL)
        clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
    if (current)
    {    // Release memory associated with children
        if (current->left)
            clear(current->left);
        if (current->right)
            clear(current->right);
        delete current;
    }
}

template <class T>
int Tree<T>::isEmpty() const
{
    return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
    if (current)
    {   // process current Node
        process(current->value);
        // then visit children
        preOrder(current->left);
        preOrder(current->right);
    }
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
    if (current)
    {
        inOrder(current->left);
        process(current->value);
        inOrder(current->right);
    }
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
    if (current)
    {
        postOrder(current->left);
        postOrder(current->right);
        process(current->value);
    }
}


//added functions


//returns the height of the tree
template<class T>
int Tree<T>::height (Node* current){
    
    //if node is empty , height = -1
    if (!current){
        return -1;
    }
    
    int traverseRight, traverseLeft;
    //traverses the right side of a given node
    traverseRight = height(current->right);
    //traverses the left side of a given node
    traverseLeft  = height(current->left);

    //the height of the right and the height of left of each node will be compared and the max of those two values will be returned
    return traverseRight > traverseLeft ? traverseRight + 1 : traverseLeft + 1;
}


//reflects the tree along its root
template <class T>
void Tree<T>::reflect(Node* current){
    
    if(current == nullptr){
        return;
    }
    //recursively itterate through the tree
    reflect(current->left);
    reflect(current->right);
    
    //Every parent node will swap its left node with its right node
    Node* temp = current->left;
    current->left = current->right;
    current->right = temp;
}


//using a queue, we will print each value using a breadthscan
template <class T>
void Tree<T>::breadthScan(){
    
    //base case
    if (this->isEmpty()){
        return;
    }
    
    //initalize a new Queue Vector of Nodes
    Queue<Node*>* Q = new QueueVector<Node*>;
    
    Node* current = root;
    
    //insert root into the Q
    Q->enqueue(current);
    
    //as long as the Q has values
    while(!(Q->isEmpty())){
        
        //dequques the first element and prints it using process function
        current = Q->dequeue();
        process(current->value);
        
        //insert left and right nodes to the Queue as long as aren't nullptrs
        if (current->left){
            Q->enqueue(current->left);
        }
        if (current->right){
            Q->enqueue(current->right);
        }
    }
    //deletes the Queue
    delete Q;
}




#endif /* Tree_hpp */

