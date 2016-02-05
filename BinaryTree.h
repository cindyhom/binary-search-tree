//
//  BinaryTree.h
//  BinaryTree
//
//  Created by Cindy Hom on 11/20/15.
//  Copyright © 2015 Cindy Hom. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <new>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "BNode.h"


using std::string;
using std::cout;
using std::endl;

/****************************************************************************
 *                                                                          *
 *                   struct INT declaration                                 *
 *                                                                          *
 ****************************************************************************/
struct INT{
    //overloaded insertion operator
    friend std::ostream& operator<<(std::ostream &os, const INT &i);
    int *_data;
    
    //constructor
    INT();
    
    //constructor with parameters
    INT(int data);
    
    //copy constructor
    INT(INT &rhsObj);
    
    //destructor
    ~INT();
    
    //overloaded assignment and inequality operators
    INT& operator=(const INT &a);
    bool operator==(const INT &a) const;
    bool operator<(const INT &a) const;
    bool operator>(const INT &a) const;
};



/****************************************************************************
 *                                                                          *
 *                   struct INT implementation                              *
 *                                                                          *
 ****************************************************************************/
std::ostream& operator<<(std::ostream &os, const INT &i)
{
    //insert contents of the pointer to the ostream obj
    os << *(i._data);
    
    return os;
}


INT::INT()
{
    _data = NULL;
}

INT::INT(int data)
{
   _data = new int(data);
}


INT::INT(INT &rhsObj)
{
    _data = new int(*(rhsObj._data));
}


INT::~INT()
{
    delete _data;
}


INT& INT::operator=(const INT &a)
{
    if(this != &a)
    {
        //not self-assignment
        *_data = *(a._data);
    }
    return *this;
}


bool INT::operator==(const INT &a) const
{
    //if lhsObj is equal to rhsObj then it's true
    if(*_data == *(a._data))
        return true;
    else
        return false;
}


bool INT::operator<(const INT &a) const
{
    //if lhsObj is less than rhsObj then it's true
    if (*_data < *(a._data))
        return true;
    else
        return false;
}

bool INT::operator>(const INT &a) const
{
    //if lhsObj is greater than rhsObj then it's true
    if (*_data > *(a._data))
        return true;
    else
        return false;
}


//==============================================================================================



/****************************************************************************
 *                                                                          *
 *                   struct CHAR declaration                                *
 *                                                                          *
 ****************************************************************************/

struct CHAR{
    //overloaded insertion operator
    friend std::ostream& operator<<(std::ostream &os, const CHAR &ch);
    char *_data;
    
    //constructor
    CHAR();
    
    //constructor with parameters
    CHAR(char data);
    
    //copy constructor
    CHAR(CHAR &rhsObj);
    
    //destructor
    ~CHAR();
    
    //overloaded assignment and inequality operators
    CHAR& operator=(const CHAR &a);
    bool operator==(const CHAR &a) const;
    bool operator<(const CHAR &a) const;
    bool operator>(const CHAR &a) const;
};



/****************************************************************************
 *                                                                          *
 *                   struct CHAR implementation                             *
 *                                                                          *
 ****************************************************************************/
std::ostream& operator<<(std::ostream &os, const CHAR &ch)
{
    //insert contents of pointer to ostream obj
    os << *(ch._data);
    
    return os;
}


CHAR::CHAR()
{
    _data = NULL;
}

CHAR::CHAR(char data)
{
    _data = new char(data);
}


CHAR::CHAR(CHAR &rhsObj)
{
    _data = new char(*(rhsObj._data));
}


CHAR::~CHAR()
{
    delete _data;
}


CHAR& CHAR::operator=(const CHAR &a)
{
    if(this != &a)
    {
        //not self-assignment
        *_data = *(a._data);
    }
    return *this;
}



bool CHAR::operator==(const CHAR &a) const
{
    if(*_data == *(a._data))
        return true;
    else
        return false;
}


bool CHAR::operator<(const CHAR &a) const
{
    if (*_data < *(a._data))
        return true;
    else
        return false;
}


bool CHAR::operator>(const CHAR &a) const
{
    if (*_data > *(a._data))
        return true;
    else
        return false;
}



//=============================================================================================




/****************************************************************************
 *                                                                          *
 *                   class BinaryTree declaration                           *
 *                                                                          *
 ****************************************************************************/
template <typename T>
class BinaryTree
{
private:
    BNode<T> *_root;
    int nodeCount;
    
    //private functions
    void _insert(BNode<T> *&tree, T val);
    void _destroySubtree(BNode<T> *tree);
    void _remove(BNode<T> *&tree, T val);
    void _makeDeletion(BNode<T> *&tree);
    void _displayInOrder(BNode<T> *tree) const;
    void _displayPreOrder(BNode<T> *tree) const;
    void _displayPostOrder(BNode<T> *tree) const;
    int _height(BNode<T> *tree);
    
public:
    //public functions
    BinaryTree(){_root = NULL; nodeCount = 0;}
    ~BinaryTree(){_destroySubtree(_root);}
    bool find(T val);
    void insert(T val){_insert(_root, val);}
    void remove(T val){_remove(_root, val);}
    void deleteAll();
    int height(){_height(_root);}
    void printInOrder() const{_displayInOrder(_root);}
    void printPreOrder() const{_displayPreOrder(_root);}
    void printPostOrder() const{_displayPostOrder(_root);}
};



template <typename T>
void BinaryTree<T>::_insert(BNode<T> *&tree, T val)
{
    if(!tree)
    {
        //tree was empty so make a new node
        tree =  new BNode<T>(val);
        return;
    }
    
    if(*(tree->_node) == val)
    {
        //value already in tree
        cout << "Value is already in tree.\n";
        return;
    }

    
    if(val < *(tree->_node))
    {
        //value is less then so go left
         _insert(tree->_left, val);
    }
    
    else if (val > *(tree->_node))
    {
        //value is greater than so go right
        _insert(tree->_right, val);
    }
    
    else
    {
        //if not <, >, or == then something is wrong
        cout << "what" << endl;
    }
    nodeCount++;

}



template <typename T>
void BinaryTree<T>::_displayInOrder(BNode<T> *tree) const
{
    if(tree)
    {
        //left, visit, right
        _displayInOrder(tree->_left);
        cout << *(tree->_node->_data) << " ";
        _displayInOrder(tree->_right);
        
    }
}


template <typename T>
void BinaryTree<T>::_displayPreOrder(BNode<T> *tree) const
{
    if(tree)
    {
        //visit, left, right
        cout << *(tree->_node->_data) << " ";
        _displayPreOrder(tree->_left);
        _displayPreOrder(tree->_right);
    }
}


template <typename T>
void BinaryTree<T>::_displayPostOrder(BNode<T> *tree) const
{
    if(tree)
    {
        //left, right, visit
        _displayPostOrder(tree->_left);
        _displayPostOrder(tree->_right);
        cout << *(tree->_node->_data) << " ";
    }
}



template <typename T>
void BinaryTree<T>::_makeDeletion(BNode<T> *&tree)
{
    BNode<T> *nodeToDelete = tree;
    BNode<T> *attachPoint;
    
    if(tree->_right == NULL)
    {
        //right is null so go left -- only 1 child
        tree = tree->_left;
    }
    else if(tree->_left == NULL)
    {
        //left is null so go right -- only 1 child
        tree = tree->_right;
    }
    else
    {
        //must be 2 children
        attachPoint = tree->_right;
        
        while(attachPoint->_left != NULL)
            {attachPoint = attachPoint->_left;}
        attachPoint->_left = tree->_left;
        tree = tree->_right;
    }
    
    delete nodeToDelete;
    nodeCount--;
    
}




template <typename T>
void BinaryTree<T>::_remove(BNode<T> *&tree, T val)
{
    if(tree == NULL)
    {
        //nothing in tree
        cout << "Tree is empty. No values to remove.\n";
        return;
    }

    //if value less than go left
    if(val < *(tree->_node))
        _remove(tree->_left, val);
    
    //if value is greater than go right
    else if (val > *(tree->_node))
        _remove(tree->_right, val);
    else
    {
        //delete item
        _makeDeletion(tree);
        cout << "Item has been deleted.\n";
    }
}



template <typename T>
void BinaryTree<T>::_destroySubtree(BNode<T> *tree)
{
    //empty tree
    if(!tree)
        return;
    //go left
    _destroySubtree(tree->_left);
    //go right
    _destroySubtree(tree->_right);
    delete tree;
    nodeCount = 0;
}




template <typename T>
bool BinaryTree<T>::find(T val)
{
    BNode<T> *tree = _root;
    
    while(tree)
    {
        //found the item
        if(*(tree->_node) == val)
            return true;
        
        //val is less then so look left
        else if(val < *(tree->_node))
            tree = tree->_left;
        
        //val is greater than so look right
        else
            tree = tree->_right;
    }
    return false;
}


template <typename T>
void BinaryTree<T>::deleteAll()
{
    _destroySubtree(_root);
}

template <typename T>
int BinaryTree<T>::_height(BNode<T> *tree)
{
    //tree is empty so heightis -1
    if(tree == NULL)
        return -1;
    
    //height of left side & right side
    int left = _height(tree->_left);
    int right = _height(tree->_right);
    
    //find the max height of left and right and add one for actual height
    if(left > right)
        return (left + 1);
    else
        return (right + 1);
}

#endif /* BinaryTree_h */
