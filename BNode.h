//
//  BNode.h
//  BinaryTree
//
//  Created by Cindy Hom on 11/24/15.
//  Copyright © 2015 Cindy Hom. All rights reserved.
//

#ifndef BNode_h
#define BNode_h

#include <iostream>

/****************************************************************************
 *                                                                          *
 *                   class BNode declaration                                *
 *                                                                          *
 ****************************************************************************/
template <typename T> class BinaryTree;
template <typename T>
class BNode
{
    friend class BinaryTree<T>;
private:
    T *_node;
    BNode<T> *_left;
    BNode<T> *_right;
    
public:
    //constructor
    BNode(T a = NULL, BNode<T> *_left1 = NULL, BNode<T> *_right1 = NULL);
    
    //copy constructor
    BNode(BNode<T> &b);
    
    //destructor
    ~BNode();
    
    
    //overloaded assignment and inequality operators
    T& operator=(const T &a);
    bool operator==(const T&a) const;
    bool operator<(const T &a) const;
    bool operator>(const T &a) const;
    
    
};


/****************************************************************************
 *                                                                          *
 *                   class BNode implementation                             *
 *                                                                          *
 ****************************************************************************/
template <typename T>
BNode<T>::BNode(T a, BNode<T> *_left1, BNode<T> *_right1)
{
    _node = new T(a);
    _left = _left1;
    _right = _right1;
}

template <typename T>
BNode<T>::BNode(BNode &b)
{
    _node = new T(*(b._node));
    _left = b._left;
    _right = b._right;
}

template <typename T>
BNode<T>::~BNode()
{
    delete _node;
    _left = NULL;
    _right = NULL;
}


template <typename T>
T& BNode<T>::operator=(const T &a)
{
    if(this != a)
    {
        //NOT self-assignment
        _node = a._node;
        _left = a._left;
        _right = a._right;
        
    }
    return *this;
}


template <typename T>
bool BNode<T>::operator==(const T &a) const
{
    //if they are equal return true
    if (*_node == *(a._node))
        return true;
    else
        return false;
}


template <typename T>
bool BNode<T>::operator<(const T &a) const
{
    //if lhsObj < rhsObj return true
    if(*_node < *(a._node))
        return true;
    else
        return false;
    
}


template <typename T>
bool BNode<T>::operator>(const T &a) const
{
    //if not equal to and not < then must be greater than
    if((!operator==(a) && !operator<(a)))
        return true;
    else
        return false;
}

#endif /* BNode_h */
