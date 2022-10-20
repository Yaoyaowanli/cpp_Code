//
// Created by 姚远 on 2022/10/19.
//

#include "STL_List.h"



void print_list(const std::list<int>& l){
    std::list<int>::const_iterator cit = l.begin();
    std::cout << "l.size : " << l.size() << std::endl;
    while (cit != l.end()){
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;
}

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
    //只要一个容器支持迭代器，就能使用范围for
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


//迭代器的划分
//从支持的操作接口的角度划分迭代器的类型有：单向迭代器（forward_list）、双向迭代器(list)、随机迭代器(vector)
//从使用场景的角度来划分迭代器的类型有： （正向迭代器、反向迭代器）、const迭代器

void testList2(){
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    //list的4种迭代器
    //1、可读写的正向迭代器
    std::list<int>::iterator it = l.begin();
    while (it != l.end()){
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    //2、可读写的反向迭代器
    std::list<int>::reverse_iterator rit = l.rbegin();
    while (rit != l.rend()){
        std::cout << *rit << " ";
        rit++;
    }
    std::cout << std::endl;

    //3、只读的正向迭代器
    std::list<int>::const_iterator cit = l.cbegin();
    while (cit != l.cend()){
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    //4、只读的反向迭代器
    std::list<int>::const_reverse_iterator crit = l.crbegin();
    while (crit != l.crend()){
        std::cout << *crit << " ";
        ++crit;
    }
    std::cout << std::endl;

}



void testList3() {
    //list任意位置的插入删除
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    auto pos = std::find(l.begin(),l.end(),4);
    if (pos != l.end()){
        l.insert(pos,9999);
    }

    for (auto val:l){
        std::cout << val << " ";
    }
    std::cout << std::endl;
}


void testList4() {
    //list迭代器失效
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    std::list<int>::iterator it = l.begin();
    while (it != l.end()){
        if (*it %2 ==0){
            //erase会删除节点，再对其it进行操作会造成越界访问
            //所以需要通过erase的返回值来重置it，他返回的就是下一个节点
            it = l.erase(it);
        }else{
            ++it;
        }
    }
    print_list(l);
}