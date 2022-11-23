//
// Created by 姚远 on 2022/11/12.
//

#include "RBTree.h"


void test_rbTree1(){
    RBTree<int,int> rbt;
    int arr[] = {4,2,6,1,3,5,15,7,16,14};
    for (auto e:arr){
        rbt.Insert(std::make_pair(e,e));
    }

    rbt.InOrder();
    if (!rbt.IsValidRBTree()){
        std::cout << "false"<<std::endl;
    }else{
        std::cout << "true"<<std::endl;
    }
}