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


class Date {
public:
    //谁调用这个成员函数，this指针就指向谁。
    void Print() {
        //这里为什么可以访问到_year等变量呢？是因为这里看起来没有传参数，但是编译器会帮我们传入调用对象作为参数
        // void Print（Date* this） ，这里叫做隐含的this指针。
        //std::cout << this->_year << "-" << this->_mouth << "-" << this->_day << std::endl;
        std::cout << _year << "-" << _mouth << "-" << _day << std::endl;
    }
    void Init (int year,int mouth ,int day){
        //void Init (Date* this，int year,int mouth ,int day)
        //this->_year = year;
        //this->_mouth = mouth;
        //this->_day = day;
        _year = year;
        _mouth = mouth;
        _day = day;
    }

    //构造函数->在对象构造时调用的函数，这个函数完成对象的初始化工作。
    //构造函数的特点：   1、函数名和类名相同。  2、没有返回值。   3、对象实例化时编译器自动调用对应的构造函数。  4、构造函数可以重载。
    Date(int year,int mouth,int day){
        _year=year;
        _mouth=mouth;
        _day=day;
    }

    //构造函数可以重载
    Date(){
        _year = 1996;
        _mouth = 10;
        _day = 14;
    }

private:
    int _year;
    int _mouth;
    int _day;
};

//构造函数
//5、如果类中没有显示定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，
//一旦用户显示定义了构造函数，编译器就不再默认生成。
class Time{
public:
    Time(){
        _hour = 0;
        _minute = 0;
        _second =0;
    }
private:
    int _hour;
    int _minute;
    int _second;
};

class Date2{
public:

    //在这里我们没有显示的定义构造函数，那么编译器会默认生成一个无参的构造函数。


    void Print(){
        std::cout << _year << "-" << _mouth << "-" << _day << std::endl;
    }

private:
    int _year;
    int _mouth;
    int _day;
    Time _t;
};



class Date3{
public:

    //无参的构造函数和全缺省的构造函数都称为默认构造函数，默认构造函数只能存在1个。
    //注意：无参构造函数，全缺省，编译器自动生成的构造函数，都可以是默认构造函数。

    //更好的方式->全缺省
    Date3(int year = 0,int mouth = 0, int day = 0){
        _year = year;
        _mouth = mouth;
        _day = day;
    }

    void Print(){
        std::cout << _year << "-" << _mouth << "-" << _day << std::endl;
    }


    //析构函数： 在对象生命周期结束时，会自动调用，完成清理工作，注意：不是完成销毁,是完成对象里面的资源清理
    //析构函数没有参数没有返回值，所以不构成重载，析构函数为～类名
    ~Date3(){
        std::cout << "~Date3()" <<std::endl;
    }

private:
    int _year;
    int _mouth;
    int _day;
};


//析构函数例子
class Stack2 {
public:
    //构造函数
    Stack2(int n = 10 ){
        _a = (int *)malloc(sizeof(int)*n);
        _size = 0;
        _capacity = n;
    }

    ~Stack2(){
        if (_a){
            std::cout << "free:" << _a << std::endl;
            free(_a);
            _a = nullptr;
            _size = _capacity = 0;
        }
    }
private:
    int* _a;
    int _size;
    int _capacity;
};


void Test22(){
    //Date d1;
    //d1.Init(2022,10,02);
    //d1.Init(&d1，2022,10,02);
    //d1.Print();
    //d1.Print(&d1);

    //构造函数->在对象构造时调用的函数，这个函数完成对象的初始化工作。
    //在对象构造时给参数就会自动调用构造函数。
    Date d1(2022,10,02);
    std::cout << "d1 : " ;
    d1.Print();

    //这里在构造时没有进行传参，那么根据重载他就回去找_z4Date,这个函数
    Date d2;
    std::cout<< "d2 : " ;
    d2.Print();

    //这里打印的是随机值，但是c++确实生成和调用了默认的构造函数。
    //我们在date2 李加入了一个时间类，写了一个构造函数，我们发现在对date2进行构造时，编译器会自动对date2的成员变量time进行构造
    //并且调用了time类的构造函数，这一点说明一个类在实例化时编译器会自动调用其构造函数，如果没有显示的构造函数，那么编译器会执行
    //默认生成的构造函数
    Date2 a1;
    a1.Print();

    //析构函数
    std::cout<< "d3 : " ;
    Date3 d3;
    d3.Print();
    std::cout<< "d33 : " ;
    Date3 d33(2022,10,2);
    d33.Print();

    std::cout<< "Stack2 : " <<std::endl ;
    Stack2 st1;
    Stack2 st2(20);
}