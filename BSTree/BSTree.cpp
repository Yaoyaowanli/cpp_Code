//
// Created by 姚远 on 2022/10/27.
//

#include "BSTree.h"


void test_BSTree_1(){
    BSTree<int> t;
    int arr[] = {5,3,4,1,7,8,2,6,0,9};
    for (auto e:arr){
        t.Insert(e);
    }
    t.InOrder();
    //t.Erase(7);
    //t.InOrder();

    for (auto e:arr){
        t.Erase(e);
        t.InOrder();
    }
    t.InOrder();
}