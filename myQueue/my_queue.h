//
// Created by 姚远 on 2022/10/22.
//

#ifndef CPP_CODE_MY_QUEUE_H
#define CPP_CODE_MY_QUEUE_H

#endif //CPP_CODE_MY_QUEUE_H
#pragma once
#include <iostream>
#include <list>
#include <vector>

namespace yao{
    template<class T,class Container>
    class queue{
    public:
        void push(const T& x);

        void pop();

        T& front();

        size_t size();

        bool empty();

        T& back();

    private:
        Container _con;
    };

}



void test_my_queue1();
