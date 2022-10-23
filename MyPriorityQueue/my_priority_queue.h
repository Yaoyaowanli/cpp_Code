//
// Created by 姚远 on 2022/10/23.
//

#ifndef CPP_CODE_MY_PRIORITY_QUEUE_H
#define CPP_CODE_MY_PRIORITY_QUEUE_H

#endif //CPP_CODE_MY_PRIORITY_QUEUE_H
#pragma once
#include <iostream>
#include <vector>

namespace yao{

    //适配器 优先级队列 其实是使用仿函数来控制AdjustUp、AdjustDown中的父子节点比较的。
    //如果需要大堆，比较时就控制 父节点 < 子节点，满足就交换，继续调整。
    //如果需要小堆，比较时就控制 父节点 > 子节点，满足就交换，继续调整。
    template<class T>
    struct less{
        bool operator() (const T& x1,const T& x2){
            return x1 < x2;
        }
    };

    template<class T>
    struct greater{
        bool operator() (const T& x1,const T& x2){
            return x1 > x2;
        }
    };


    //优先级队列 其实内部就是一个堆，这个适配器有3个参数，1、数据类型。2、容器（需要支持随机访问）3、比较规则（控制队列优先级）
    template<class T,class Container = std::vector<T>,class Compare = less<T>>
    class priority_queue{
    public:
        void push(const T& x);

        void pop();

        T& top();

        size_t size();

        bool empty();

        void AdjustUp(size_t child);

        void AdjustDown(int root = 0);
    private:
        Container _con;
    };
}


//仿函数（functor）是通过重载()运算符模拟函数形式的类
//仿函数不是函数，是个类
//反函数重载了()运算符，使得它可以像函数一样调用
/*
  struct less{
    bool operator()(int x1,int x2){
        return x1 > x2;
    }
};
 */
/*//仿函数-> 函数对象:他的对象可以像函数一样去使用
template<class T>
struct less{
    bool operator()(const T& x1,const T& x2){
        return x1 < x2;
    }
};

void test_less1(){
    less<int> lessFunc;
    std::cout << lessFunc(1,2) << std::endl;
    实际上调用的是 lessFunc.operator()(1,2);
 }*/

void test_my_priority_queue1();
