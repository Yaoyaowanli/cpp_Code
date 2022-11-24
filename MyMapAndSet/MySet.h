//
// Created by 遥远 on 2022/11/24.
//

#ifndef CPP_CODE_MYSET_H
#define CPP_CODE_MYSET_H

#endif //CPP_CODE_MYSET_H
#pragma once
#include <iostream>
#include "rb_tree.h"


namespace yao{
    template<class K>
    class set{
    public:
        //这里是一个仿函数，实现map需要key，value，所以这里重载（），在红黑树中创建一个MapKeyOrT变量，传入的是pair就取出pair中的first
        //如果是set，就取出k本身
        struct SetOfT{
            const K& operator() (const K& k){
                return k;
            }
        };
    private:
        RBTree<K,K,SetOfT> _t;
    };
}
