//
// Created by 姚远 on 2022/10/27.
//

#ifndef CPP_CODE_BSTREE_H
#define CPP_CODE_BSTREE_H

#endif //CPP_CODE_BSTREE_H
#pragma once
#include <iostream>

//binary search tree node
template<class K>
struct BSTreeNode{
    BSTreeNode<K>* _left;
    BSTreeNode<K>* _right;
    K _key;
    BSTreeNode(const K& key);
};


//binary search tree
template<class K>
class BSTree{
    typedef BSTreeNode<K> Node;
    void _InOrder(Node* root);

public:
    bool Insert(const K& key);
    void InOrder();
    bool Find(const K& key);
    bool Erase(const K& key);

private:
    Node* _root = nullptr;
};




template<class K>
BSTreeNode<K>::BSTreeNode(const K& key)
:_key(key),
_left(nullptr),
_right(nullptr)
{}


template<class K>
bool BSTree<K>::Insert(const K &key) {
    //空树
    if (_root == nullptr){
        _root = new BSTree<K>::Node(key);
        return true;
    }
    //非空
    BSTree<K>::Node *cur = _root;
    BSTree<K>::Node *parent = nullptr;
    //循环找，如果key小于节点的值，走左子树；如果key大于节点的值，走右子树；相等说明存在了，返回false
    //当cur为空的时候插入key值的节点
    while(cur) {
        if (cur->_key < key){
            parent = cur;
            cur = cur->_right;
        }else if(cur->_key > key){
            parent = cur;
            cur = cur->_left;
        }else{
            return false;
        }
    }

    cur = new BSTree<K>::Node(key);
    if (parent->_key < key){
        parent->_right = cur;
    }else{
        parent->_left = cur;
    }
    return true;
}

template<class K>
void BSTree<K>::InOrder() {
    _InOrder(_root);
    std::cout << std::endl;
}

template<class K>
void BSTree<K>::_InOrder(Node *root) {
    if (root == nullptr){
        return;
    }
    _InOrder(root->_left);
    std::cout << root->_key << " ";
    _InOrder(root->_right);
}

template<class K>
bool BSTree<K>::Find(const K &key) {
    Node* cur = _root;
    while (cur){
        if (cur->_key > key){
            cur = cur->_left;
        }else if(cur->_key < key){
            cur = cur->_right;
        }else{
            return true;
        }
    }

    return false;
}

template<class K>
bool BSTree<K>::Erase(const K &key) {
    Node* parent = nullptr;
    Node* cur = _root;
    while (cur){
        if (cur->_key < key){
            parent = cur;
            cur = cur->_right;
        }else if(cur->_key > key){
            parent = cur;
            cur = cur->_left;
        }else{
            //找到了，开始删除
            //3种情况，要删除的节点左边为空树，要删除的节点右边为空树，两边都不为空树
            if(cur->_left == nullptr){
                if(cur == _root){
                    _root=_root->_right;
                }else{
                    //1、cur左边为空，就去看看parent是左子树指向cur还是右子树指向cur
                    if(parent->_right == cur){
                        //已经确定了cur->_left 是空的，故应该让parent->_right -> cur->_right
                        parent->_right = cur->_right;
                    }else{
                        //已经确定了cur->_left 是空的，故应该让parent->_left -> cur->_right
                        parent->_left = cur->_right;
                    }
                }
                delete cur;
                return true;
            }else if (cur->_right == nullptr){
                if(cur == _root){
                    _root = _root->_left;
                }else{
                    //3种情况，要删除的节点左边为空树，要删除的节点右边为空树，两边都不为空树
                    if (parent->_left == cur){
                        parent->_left = cur->_left;
                    }else{
                        parent->_right = cur->_left;
                    }
                }
                delete cur;
                return true;
            }else{
                //两边都不为空，可以使用左树的最大节点（最右节点），或右树的最小节点（最左节点）来替代
                Node* rightMinParent = cur;
                Node* rightMin = cur->_right;
                while(rightMin->_left){
                    rightMinParent = rightMin;
                    rightMin = rightMin->_left;
                }
                //替代删除
                cur->_key = rightMin->_key;
                //转换为删除rightMin
                //这里预防右树找左时根就是最左的情况
                if (rightMinParent == cur){ //处理上面while没进去，没有迭代
                    rightMinParent->_right = rightMin->_right;
                }else{
                    rightMinParent->_left = rightMin->_right;
                }
                delete rightMin;
                return true;
            }
        }
    }
    return false;
}


//                    5
//               3         7
//            1     4    6   8
//         0     2              9
//
//


void test_BSTree_1();