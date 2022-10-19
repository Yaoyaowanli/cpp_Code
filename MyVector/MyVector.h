//
// Created by 姚远 on 2022/10/18.
//

#ifndef CPP_CODE_MYVECTOR_H
#define CPP_CODE_MYVECTOR_H

#endif //CPP_CODE_MYVECTOR_H

#include <iostream>
#include <string>

namespace yaoYuan{
    template <class T>
    class vector{
    public:
        typedef T* iterator;

        typedef const T* const_iterator;

        vector():_start(nullptr),_finish(nullptr),_end_of_storage(nullptr){}

        ~vector();

        vector<T>& operator= (vector<T> v);

        iterator begin();

        iterator end();

        const_iterator begin()const;

        const_iterator end()const;

        void push_back(const T& x);

        size_t size();

        size_t capacity();

        size_t size()const;

        size_t capacity()const;

        void reserve(size_t n);

        void pop_back();

        void insert(iterator pos,const T& x);

        iterator erase(iterator pos);

        void resize(size_t n,const T& val = T());

        T& operator[] (size_t i);

        const T& operator[] (size_t i)const;

        void print_vector(const vector<T>& v);

        vector(const vector<T>& v);

        void swap(vector<T>& v);

    private:
        iterator _start;  //数据开始处指针
        iterator _finish; //数据结束处指针
        iterator _end_of_storage;  //存储空间的结束位置
    };
}




void test_my_vector1();
void test_my_vector2();
void test_my_vector3();
void test_my_vector4();
void test_my_vector5();