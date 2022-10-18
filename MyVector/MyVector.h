//
// Created by 姚远 on 2022/10/18.
//

#ifndef CPP_CODE_MYVECTOR_H
#define CPP_CODE_MYVECTOR_H

#endif //CPP_CODE_MYVECTOR_H

#include <iostream>

namespace yaoYuan{
    template <class T>
    class vector{
    public:
        typedef T* iterator;

        vector():_start(nullptr),_finish(nullptr),_end_of_storage(nullptr){}

        iterator begin();

        iterator end();

        void push_back(const T& x);

        size_t size();

        size_t capacity();

        void reserve(size_t n);

        void pop_back();

        void insert(iterator pos,const T& x);

        iterator erase(iterator pos);

    private:
        iterator _start;  //数据开始处指针
        iterator _finish; //数据结束处指针
        iterator _end_of_storage;  //存储空间的结束位置
    };
}




void test_my_vector1();