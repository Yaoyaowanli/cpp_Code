//
// Created by 姚远 on 2022/9/28.
//

#ifndef CPP_CODE_NO2_H
#define CPP_CODE_NO2_H

#endif //CPP_CODE_NO2_H

#include <iostream>

//如何定义一个类
//封装性
//1、将数据和方法定义到一起
//2、把想给你看到的数据定义成公开，不想给你看的封装起来，->访问限定符.

/*class Stack{
    //1、成员函数
public:
    void Push(int x);
    void Pop();
    bool Empty();
    //...

    //2、成员变量
private:
    int* _a;
    int size;
    int capacity;
};*/

//1、C语言中struct是用来定义结构体的
//2、C++中，兼容C的struct定义结构体的用法，但同时也支持struct用来定义类
//3、C++中使用class和struct定义类的区别：默认的访问限定符
struct ListNode_C {
    int _val;
    struct ListNode_C* _next;
    struct ListNode_C* _prev;
};

struct ListNode_CPP{  //struct默认是共有的
//class ListNode_CPP{     //class默认是私有的
    int _val;
    struct ListNode_CPP* _next; //兼容c的用法
    ListNode_CPP* _prev;

    //还可以定义函数->成员函数
    ListNode_CPP* CreatNode(int val);
};



class Stack{
    //1、成员函数
public:
    //这里是函数的声明，并没有函数的定义，想要定义函数，有两种方法：1、在类中声明时就定义。2、在外部定义
    void Push(int x);
    void Pop(){
        //...
    }
    bool Empty();
    //...

    //2、成员变量
private:
    int* _a;
    int _size;
    int _capacity;
};








void Test21();
