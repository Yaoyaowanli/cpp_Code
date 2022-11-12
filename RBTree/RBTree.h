//
// Created by 姚远 on 2022/11/12.
//

#ifndef CPP_CODE_RBTREE_H
#define CPP_CODE_RBTREE_H

#endif //CPP_CODE_RBTREE_H

#pragma once
#include <iostream>


// Red Black Tree

enum Colour {
    BLACK,
    RED,
};

template<class K,class V>
struct RBTreeNode{
    RBTreeNode<K,V>* _left;
    RBTreeNode<K,V>* _right;
    RBTreeNode<K,V>* _parent;

    std::pair<K,V> _kv;
    Colour _col;
};

template<class K,class V>
class RBTree{
    typedef RBTreeNode<K,V> Node;

private:
    Node* _root;
};