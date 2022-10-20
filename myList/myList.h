//
// Created by 姚远 on 2022/10/20.
//

#ifndef CPP_CODE_MYLIST_H
#define CPP_CODE_MYLIST_H

#endif //CPP_CODE_MYLIST_H

#pragma once
#include <iostream>

namespace yao{
    template<class T>
    struct __list_node{                 //链表节点
        __list_node(const T& x=T());

        __list_node<T>* _next;          //前后节点指针
        __list_node<T>* _prev;
        T _data;                        //数据
    };

    template<class T,class Ref,class Ptr>
    struct __list_iterator{
        typedef __list_node<T> Node;
        Node* _node;

        //构造迭代器
        __list_iterator(Node* node):_node(node){}

        //通过重载操作符来让迭代器可以类似于指针运算的操作
        T& operator*();

        __list_iterator<T>& operator++();

        __list_iterator<T> operator++(int);

        __list_iterator<T>& operator--();

        __list_iterator<T> operator--(int);

        bool operator!= (const __list_iterator<T>& it);

        bool operator== (const __list_iterator<T>& it);

        T* operator-> ();

    };

    template <class T>
    class list{                         //带头双向循环链表
        typedef __list_node<T> Node;    //node 就是 __list_node
    public:
        typedef __list_iterator<T,T&,T*> iterator;
        typedef __list_iterator<T,const T&,const T*> const_iterator;
        //构造函数，new一个node，让其前后都指向自己
        list();

        ~list();

        void push_back(const T& x);

        void clear();

        void pop_back();

        void push_front(const T& x);

        void pop_front();

        void insert(iterator pos,const T& x);

        void erase(iterator pos);

        iterator begin();

        iterator end();

    private:
        Node* _head;
    };
}




void test_my_list1();
