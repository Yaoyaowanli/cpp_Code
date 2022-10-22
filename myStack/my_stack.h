//
// Created by 姚远 on 2022/10/22.
//

#ifndef CPP_CODE_MY_STACK_H
#define CPP_CODE_MY_STACK_H

#endif //CPP_CODE_MY_STACK_H
#pragma once
#include <iostream>
#include <vector>
#include <list>

namespace yao{

    //适配器模式：
    //在这里我们定义了两个参数T和Container，T作为数据类型，Container是容器类型，只要实现了我们接口中的功能，就都可以当作一个stack使用。

    template<class T,class Container>
    class stack{
    public:

        void push(const T& x);

        void pop();

        size_t size();

        T& top();

        bool empty();

    private:
        Container _con;
    };

}




void test_my_stack1();
