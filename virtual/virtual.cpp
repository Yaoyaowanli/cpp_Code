//
// Created by 姚远 on 2022/10/25.
//

#include "virtual.h"



//多态
//多态的两个条件：
//1、虚函数的重写
//2、基类对象的指针或引用去调用虚函数

//满足多态：跟调用对象的类型无关，执行的是指向或引用的那个类型的虚函数
//不满足多态 ： 和调用的类型有关，执行的是该类型的函数/虚函数

class person_virtual{
public:
    virtual void Buy_ticket(){
        cout << "买票->全价" << endl;
    }
};


class student_virtual : public person_virtual{
    virtual void Buy_ticket() {
        cout << "买票->半价" << endl;
    }
};


void Func1(person_virtual& p){
    p.Buy_ticket();
}

void test_virtual_1(){
    person_virtual p1;
    student_virtual s1;
    Func1(p1);
    Func1(s1);
}



//经典问题
//      类的析构函数应该重写吗？

class person_test1{
public:
    virtual ~person_test1(){
        cout << "~person_test1()" << endl;
    }
};

class student_test1 : public person_test1 {
public:
    ~student_test1(){
        cout << "~student_test1()" << endl;
    }
};

void test_virtual_2(){
    //  我们来观察不重写析构函数的情况：
    person_test1* p1 = new person_test1;
    person_test1* p2 = new student_test1;   //注意：这里的p2是构成切割的，p2指针能访问的只有person的内容
    delete p1;  //~person_test1()
    delete p2;  //~person_test1()
    //  我们发现这里的p2析构时只析构了基类person，student没有被析构，如果子类中有资源的化，会造成内存泄漏。
    // 结论：  所以类中只要有继承关系，我们都应该重写其析构函数

    // 问题：person_test1* p2 = new student_test1，他切割后的权限只有person，为什么可以调用student的析构呢？
    // 因为重写destructor函数后就构成多态了，虚函数的调用和他的类型无关，执行的是其指向的对象的类型的虚函数。
}