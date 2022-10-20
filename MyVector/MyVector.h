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
        //迭代器
        typedef T* iterator;
        //const 迭代器
        typedef const T* const_iterator;
        //构造
        vector():_start(nullptr),_finish(nullptr),_end_of_storage(nullptr){}
        //拷贝构造
        vector(const vector<T>& v);
        //析构
        ~vector();
        //赋值重载
        vector<T>& operator= (vector<T> v);
        //begin返回一个迭代器，指向数据的起始位置
        iterator begin();
        //end返回一个迭代器，指向最后一个数据数据的下一个
        iterator end();
        //返回起始位置的const迭代器
        const_iterator begin()const;
        //返回结束位置的const迭代器
        const_iterator end()const;
        //尾部插入：在_finish位置插入数据,如果容量不足的话会调用reserve增容。
        void push_back(const T& x);
        //返回数据长度
        size_t size();
        //返回容量
        size_t capacity();

        size_t size()const;

        size_t capacity()const;
        //增容
        void reserve(size_t n);

        void pop_back();

        void insert(iterator pos,const T& x);

        iterator erase(iterator pos);

        void resize(size_t n,const T& val = T());

        T& operator[] (size_t i);

        const T& operator[] (size_t i)const;

        void print_vector(const vector<T>& v);

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