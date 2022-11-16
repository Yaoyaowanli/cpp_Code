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

    std::pair<K,V> _kv;         //kv键值对
    Colour _col;
    RBTreeNode(const std::pair<K,V>& kv);
};

template<class K,class V>
class RBTree{
    typedef RBTreeNode<K,V> Node;
public:
    bool insert(const std::pair<K,V>& kv);
private:
    Node* _root = nullptr;
};

template<class K,class V>
RBTreeNode<K,V>::RBTreeNode(const std::pair<K,V>& kv)
:_right(nullptr),
_parent(nullptr),
_left(nullptr),
_kv(kv),
_col(BLACK)
{}

template<class K,class V>
bool RBTree<K, V>::insert(const std::pair<K, V> &kv) {
    //1、按照二叉搜索树的规则插入
    //1.1、如果当前红黑树为空树，构造节点为root
    if (_root == nullptr){
        _root = new Node(kv);
        return true;
    }
    //1.1、如果不为空，则通过比较pair.first的键来确定最终插入的位置
    Node* cur = _root;
    Node* parent = nullptr;
    while (cur){
        if (cur->_kv.first == kv.first){
            return false;
        }
        if (cur->_kv.first > kv.first){
            parent = cur;
            cur = cur->_left;
        }
        if (cur->_kv.first < kv.first){
            parent = cur;
            cur = cur->_right;
        }
    }
    //1.2、cur已经找到了空位置,判断cur应该插入在parent的左边还是右边.
    cur = new Node(kv);
    if (parent->_kv.first > kv.first){
        cur ->_parent = parent;
        parent->_left = cur;
    }else{
        cur->_parent = parent;
        parent->_right = cur;
    }
    //新插入的节点默认为红色，因为默认为黑色的话会改变路径上黑色节点的数量，不好控制
    cur->_col = RED;
    //如果新插入节点cur的parent是红色，那么他的grandfather一定是黑色，这个时候我们通过变色来保持红黑树

    while (parent && parent->_col == RED){
        //红黑树的调节关键看uncle
        Node* grandfather = parent->_parent;
        if (grandfather->_left == parent){
            Node* uncle = grandfather->_right;
            //情况1：uncle存在且为红，就将parent和uncle变黑，grandfather变红
            if (uncle && uncle->_col == RED){
                parent->_col = BLACK;
                uncle->_col = BLACK;
                grandfather->_col = RED;
                //迭代
                cur = grandfather;
                parent = grandfather->_parent;
            }else{
                //情况2 or 情况3 ： uncle不存在 ｜｜ uncle存在且为黑
                //情况3：双旋->变为单旋
                if (cur == parent->_right){
                    RotateL(parent);
                    std::swap(parent,cur);
                }

                //第二种情况（有可能是第三种情况变过来的）
                RotateR(grandfather);
                grandfather->_col = RED;
                parent->_col = BLACK;
                break;
            }
        }else{

        }
    }

        //反方向

    _root->_col = BLACK;
}