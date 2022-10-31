//
// Created by 姚远 on 2022/10/29.
//

#include "BSTree_key_value.h"
#include <string>
void test_BSTree_key_value2(){
    BSTree<std::string,std::string> dict;
    dict.Insert("sort","排序");
    dict.Insert("string","字符串");
    dict.Insert("tree","树");
    dict.Insert("insert","插入");

    std::string str;
    while (std::cin >> str){
        BSTreeNode<std::string,std::string>* node = dict.Find(str);
        if (node){
            std::cout << node->_value << std::endl;
        }else{
            std::cout << "not found~" << std::endl;
        }
    }
}

void test_BSTree_key_value1(){
    BSTree<std::string,int> dict;
    std::string strArr[] = {"西瓜","苹果","香蕉","石榴","橘子","橙子","西瓜","石榴",
                          "西瓜","西瓜","苹果","苹果","石榴","西瓜","苹果","西瓜"};

    for (auto val:strArr){
        BSTreeNode<std::string,int>* node = dict.Find(val);
        if (node != nullptr){
            node->_value++;
        }else{
            dict.Insert(val,1);
        }
    }


    dict.InOrder();
}