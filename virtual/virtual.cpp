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



//多态的原理
//问题：sizeof（base）是多少？
class base1{
public:
    virtual void Func1(){
        cout << "Func1()" << endl;
    }
private:
    int _b = 1 ;
};

void test_virtual_3(){
    base1 b1;
    cout << sizeof(b1) << endl;

    //我们发现这里是16个字节，因为base除了他的数据_b 4字节还存了一个叫做 _vftptr(virtual function table pointer)
    //即虚函数表指针，我是x64 指针8字节，内存对齐后为16字节
    //那么什么是虚函数表指针呢？
    //虚函数表指针其实就是一个指向虚函数的指针数组
}





//遍历虚函数表，打印
class base{
public:
    virtual void func1(){ cout << "base::func1() " << endl;}
    virtual void func2(){ cout << "base::func2() " << endl; }
private:
    int _a;
};

class derive : public base {
public:
    virtual void func1(){ cout << "derive::func1() " << endl; }
    virtual void func3(){ cout << "derive::func3() " << endl; }
    virtual void func4(){ cout << "derive::func4() " << endl; }
private:
    int _b;
};

//typedef 了函数指针
typedef void(*VF_PTR)();

void PrintVFTable(VF_PTR *pTable){
    for(size_t i=0; pTable[i]!= 0 ;i++){
        printf("virtual function table[%d]: %p->",i,pTable[i]);
        VF_PTR p = pTable[i];
        p();
    }
    cout << endl;
}

void test_virtual_4() {
    base b1;
    derive d1;
    cout << sizeof(void*) << endl;

    PrintVFTable((VF_PTR*)(*(long long*)&d1));
    PrintVFTable((VF_PTR*)(*(long long*)&b1));

}