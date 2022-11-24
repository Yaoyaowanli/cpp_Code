//
// Created by 遥远 on 2022/11/24.
//

#ifndef CPP_CODE_MYMAP_H
#define CPP_CODE_MYMAP_H

#endif //CPP_CODE_MYMAP_H
#pragma once
#include <iostream>
#include "rb_tree.h"


namespace yao{
    template<class K,class V>
    class map{
    public:
        //这里是一个仿函数，实现map需要key，value，所以这里重载（），在红黑树中创建一个MapKeyOrT变量，传入的是pair就取出pair中的first
        struct MapKeyOrT{
            const K& operator() (const std::pair<K,V>& kv){
                return kv.first;
            }
        };
        bool Insert(const std::pair<K,V>& kv);
    private:
        RBTree<K,std::pair<K,V>,MapKeyOrT> _t;
    };
}

template<class K,class V>
bool yao::map<K,V>::Insert(const std::pair<K, V> &kv) {
    return _t.Insert(kv);
}



void test_my_map();

