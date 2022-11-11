//
// Created by 姚远 on 2022/11/9.
//

#ifndef CPP_CODE_AVLTREE_H
#define CPP_CODE_AVLTREE_H

#endif //CPP_CODE_AVLTREE_H
#pragma once
#include <iostream>


template<class K,class V>
struct AVLTreeNode{
    AVLTreeNode<K,V>* _left;
    AVLTreeNode<K,V>* _right;
    AVLTreeNode<K,V>* _parent;
    int _bf;                        //balance factor 平衡因子
    std::pair<K,V> _kv;
    AVLTreeNode(const std::pair<K,V>& kv);
};

template<class K,class V>
class AVLTree{
    typedef AVLTreeNode<K,V> Node;
public:
    bool insert(const std::pair<K,V>& kv);
    bool isBalance();
    bool erase(const K& key);
    V* find(const K& key);

private:
    Node* _root = nullptr;
    void rotateL (Node* parent);
    void rotateR (Node* parent);
    void rotateRL (Node* parent);
    void rotateLR (Node* parent);
    bool _isBalance(Node* root);
    int Height(Node* root);
    Node* _find(const K& key);
};

template<class K,class V>
AVLTreeNode<K,V>::AVLTreeNode(const std::pair<K, V> &kv)
        :_kv(kv),
        _parent(nullptr),
        _right(nullptr),
        _left(nullptr),
        _bf(0)
        {}

template<class K,class V>
bool AVLTree<K,V>::insert(const std::pair<K, V> &kv) {
    //1、先按照搜索树的规则插入
    // 根为空
    if (_root == nullptr){
        _root = new Node(kv);
        return true;
    }
    //根不为空
    Node* parent = nullptr;
    Node* cur = _root;
    while(cur){
        if (cur->_kv.first > kv.first){
            parent = cur;
            cur = cur->_left;
        }else if(cur->_kv.first < kv.first){
            parent = cur;
            cur = cur->_right;
        }else{
            return false;
        }
    }

    cur = new Node(kv);
    if (parent->_kv.first > kv.first){
        parent->_left = cur;
        cur->_parent = parent;
    }else{
        parent->_right = cur;
        cur->_parent = parent;
    }

    //2、更新平衡因子
    while(parent){
        if (cur == parent->_right){
            //因为是右树高度减去左树高度，所以右树增加了节点就让parent的bf+1
            parent->_bf++;
        }else{
            //左边-1
            parent->_bf--;
        }

        //如果parent的bf==0了就说明增加的节点把原来树矮的那一边给填上了，对再上边的父节点不构成bf因子的影响（也就是再上边的父节点bf无需修改）
        if (parent->_bf == 0){
            break;
        }else if (parent->_bf == 1 || parent->_bf == -1){
            //当更新完parent的bf为1或-1时，说明原来这个parent的bf为0（也就是原来parent的左右子树是平衡的）需要继续向上更新
            cur = parent;
            parent=parent->_parent;
        }else if (parent->_bf == 2 || parent->_bf == -2){
            //当更新完bf为2或-2时，就说明当前parent的树不平衡了，需要旋转处理
            if (parent->_bf == -2){
                if (cur->_bf == -1){
                    rotateR(parent);
                }else if (cur->_bf == 1){
                    //...
                    rotateLR(parent);
                }
            }else if(parent->_bf == 2){
                if (cur->_bf == 1){
                    rotateL(parent);
                }else if (cur->_bf == -1){
                    //...
                    rotateRL(parent);
                }
            }
            //旋转完成后子树的高度恢复到了插入节点前的高度，对再上一部分没有影响，就可以跳出循环了
            break;
        }
    }

    return true;
}

template<class K,class V>
void AVLTree<K,V>::rotateL(Node *parent) {
    //左单旋
    Node* ppNode = parent->_parent;     //提前保存parent的父节点，有可能是null
    Node* subR = parent->_right;
    Node* subRL = subR->_left;
    //首先让parent的right(原本指向的是subR)指向subR的左边（也就是subRL）
    parent->_right = subRL;
    //这里subRL有可能是nullptr
    if (subRL){
        //如果不为空，就让subRL的父指向parent
        subRL->_parent = parent;
    }
    subR->_left = parent;
    parent->_parent = subR;
    //到这里已经完成了问题子树的旋转。但是问题子树不代表整颗AVL树，上面可能还有节点
    //有两种情况
    //1、parent就是整颗AVL树的root节点，旋转完成后subR应该成为新的root节点
    if (_root == parent){
        _root = subR;
        subR->_parent = nullptr;
    }else{
        //2、parent不是整棵树的root，那么subR就应该指向最开始parent-》parent，且parent-》parent 应该指向subR
        if (ppNode->_left == parent){
            ppNode->_left = subR;
        }else{
            ppNode->_right = subR;
        }
        subR->_parent = ppNode;
    }
    //重置平衡因子
    parent->_bf = subR->_bf = 0;
}

template<class K,class V>
void AVLTree<K,V>::rotateR(Node *parent) {
    //右单旋
    Node* ppNode = parent->_parent;
    Node* subL = parent->_left;
    Node* subLR = subL->_right;

    parent->_left = subLR;
    if (subLR){
        subLR->_parent = parent;
    }
    subL->_right = parent;
    parent->_parent = subL;

    if (_root == parent){
        _root = subL;
        subL->_parent = nullptr;
    }else{
        if (ppNode->_left == parent){
            ppNode->_left = subL;
        }else{
            ppNode->_right = subL;
        }
        subL->_parent = ppNode;
    }
    parent->_bf = subL->_bf = 0;
}

template<class K,class V>
void AVLTree<K,V>::rotateRL(Node *parent) {
    Node* subR = parent->_right;
    Node* subRL = subR->_left;
    int bf = subRL->_bf;

    rotateR(parent->_right);
    rotateL(parent);

    if (bf == -1){
        parent->_bf = 0;
        subR->_bf = 1;
        subRL->_bf = 0;
    }else if (bf == 1){
        parent->_bf = -1;
        subR->_bf = 0;
        subRL->_bf = 0;
    }else if (bf == 0){
        parent->_bf = 0;
        subR->_bf = 0;
        subRL->_bf = 0;
    }
}

template<class K,class V>
void AVLTree<K,V>::rotateLR(Node *parent) {
    Node* subL = parent->_left;
    Node* subLR = subL->_right;
    int bf = subLR->_bf;
    rotateL(parent->_left);
    rotateR(parent);
    if (bf == 1){
        parent->_bf = 0;
        subL->_bf = -1;
        subLR->_bf = 0;
    } else if(bf == -1){
        parent->_bf = 1;
        subL->_bf = 0;
        subLR->_bf = 0;
    } else if (bf == 0){
        parent->_bf = 0;
        subL->_bf = 0;
        subLR->_bf = 0;
    }
}

template<class K,class V>
bool AVLTree<K,V>::isBalance() {
    return _isBalance(_root);
}

template<class K,class V>
bool AVLTree<K,V>::_isBalance(Node *root) {
    if (root == nullptr){
        return true;
    }

    int leftHeight = Height(root->_left);
    int rightHeight = Height(root->_right);

    return abs(leftHeight-rightHeight) < 2
    && _isBalance(root->_left)
    && _isBalance(root->_right);
}

template<class K,class V>
int AVLTree<K,V>::Height(Node *root) {
   if (root == nullptr){
       return 0;
   }
    int leftHeight = Height(root->_left);
    int rightHeight = Height(root->_right);

    return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
}

template<class K,class V>
AVLTreeNode<K,V>* AVLTree<K,V>::_find(const K& key) {
    Node* cur = _root;
    while (cur){
        if (cur->_kv.first > key){
            cur = cur->_left;
        }else if (cur->_kv.first < key){
            cur = cur->_right;
        }else if (cur->_kv.first == key){
            return cur;
        }
    }
    return nullptr;
}

template<class K,class V>
V* AVLTree<K,V>::find(const K &key) {
    Node* ret = _find(key);
    if (ret == nullptr){
        return nullptr;
    }
    return ret->_kv.second;
}

/*
template<class K,class V>
bool AVLTree<K,V>::erase(const K &key) {
    Node* cur = _find(key);
    if (cur == nullptr){
        return false;
    }
    Node* rightMin = nullptr;
    Node* parent = cur->_parent;
    //判断3种情况，要删除的节点左边为空树，要删除的节点右边为空树，要删除的节点两边都不为空树
    if(cur->_left == nullptr){
        if (_root == cur){
            _root = cur->_right;
        }else{
            if (parent->_left == cur){
                parent->_left = cur->_right;
            }else{
                parent->_right = cur->_right;
            }
            if (cur->_right != nullptr){
                cur->_right->_parent = parent;
            }
            //删除节点
        }
    }else if (cur->_right == nullptr){
        if(_root == cur){
            _root = cur->_left;
        }else{
            if (parent->_left == cur){
                parent->_left = cur->_left;
            }else{
                parent->_right = cur->_left;
            }

            if(cur->_left != nullptr){
                cur->_left->_parent = parent;
            }
        }
        //删除节点
    }else{
        //两边都不为空，可以使用左树的最大节点（最右节点），或右树的最小节点（最左节点）来替代
        rightMin = cur->_right;
        while(rightMin->_left){
            rightMin = rightMin->_left;
        }
        //替代删除
        std::swap(cur->_kv,rightMin->_kv);
        //转换为删除rightMin
        if (rightMin->_right != nullptr){
            rightMin->_right->_parent = rightMin->_parent;
        }else if (rightMin->_left != nullptr){
            rightMin->_left->_parent = rightMin->_parent;
        }
    }

    if (rightMin != nullptr){
        parent = rightMin->_parent;
        cur = rightMin;
    }
    Node* erase_cur = cur;
    Node* erase_rightMin = rightMin;


    while(parent){
        if (cur == parent->_right){
            //因为是右树高度减去左树高度，所以右树增加了节点就让parent的bf+1
            parent->_bf++;
        }else{
            //左边-1
            parent->_bf--;
        }

        //如果parent的bf==0了就说明增加的节点把原来树矮的那一边给填上了，对再上边的父节点不构成bf因子的影响（也就是再上边的父节点bf无需修改）
        if (parent->_bf == 0){
            break;
        }else if (parent->_bf == 1 || parent->_bf == -1){
            //当更新完parent的bf为1或-1时，说明原来这个parent的bf为0（也就是原来parent的左右子树是平衡的）需要继续向上更新
            cur = parent;
            parent=parent->_parent;
        }else if (parent->_bf == 2 || parent->_bf == -2){
            //当更新完bf为2或-2时，就说明当前parent的树不平衡了，需要旋转处理
            if (parent->_bf == -2){
                if (cur->_bf == -1){
                    rotateR(parent);
                }else if (cur->_bf == 1){
                    //...
                    rotateLR(parent);
                }
            }else if(parent->_bf == 2){
                if (cur->_bf == 1){
                    rotateL(parent);
                }else if (cur->_bf == -1){
                    //...
                    rotateRL(parent);
                }
            }
            //旋转完成后子树的高度恢复到了插入节点前的高度，对再上一部分没有影响，就可以跳出循环了
            break;
        }
    }

    if(erase_rightMin != nullptr){
        delete erase_rightMin;
        return true;
    }
    delete erase_cur;
    return true;
}*/
