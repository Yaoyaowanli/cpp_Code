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

}