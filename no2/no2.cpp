//
// Created by 姚远 on 2022/9/28.
//

#include "no2.h"

//面向对象


//类里面可以定义：1、成员变量  2、成员方法
/*
class Person{

    void Print(){

    }

    char _name[10];
    int _age;
    //...
};*/

//c++中：class和struct都可以用来定义类
//struct 的默认限定符是公有的，如果没有指定，默认为公有
//class 的默认限定符是私有的，如果类中没有指定限定符，那么默认为私有
/*
class Student{

    void ShowInfo(){
        std::cout << _name << std::endl;
        std::cout << _age << std::endl;
        std::cout << _stuId << std::endl;
    }

public:
    void Print(){}
    int GetAge(){
        return _age;
    }

//一般情况下成员变量都是比较隐私的，都会定义成私有的
private:
    char _name[20];
    int _age;
    int _stuId;
};


void Test21(){
    Student s1;

}*/




//2、在类外面定义成员函数
bool Stack::Empty() {
    //...
}


//class大小遵循内存对齐原则，类中只计算成员变量大小，不计算方法
//      结构体内存对齐规则：
//  1、第一个成员在与结构体偏移量为0的地址处。
//  2、其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。注意：对齐数=编译器默认的一个对齐数与该成员大小的较小值，vs中默认为8。
//  3、结构体总大小为：最大对齐数（所有变量类型最大者与默认对齐参数取最小）的整数倍。
//  4、如果嵌套了结构体，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。

//A1为8个字节
class A1{
    int _a;
    char _ch;
};

//无成员变量的类大小为1字节，这一字节是为了占位表示此实例存在
class A2{
    void Hello();
};

class A3{

};

//计算类的大小
void Test21(){
    Stack s1;
    //s1.Push(1);

    std::cout << sizeof(s1) << std::endl;
    std::cout << sizeof(A1) << std::endl;
    std::cout << sizeof(A2) << std::endl;
    std::cout << sizeof(A3) << std::endl;

}