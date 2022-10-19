//
// Created by 姚远 on 2022/10/19.
//

#include "STL_List.h"



void testList1() {
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_front(0);
    l.push_front(-1);

    auto it = l.begin();
    while(it != l.end()){
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    for (auto e:l){
        std::cout<< e << " ";
    }
    std::cout << std::endl;


    auto rit = l.rbegin();
    while (rit != l.rend()){
        std::cout << *rit << " ";
        rit++;
    }
    std::cout << std::endl;

}