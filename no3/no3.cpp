//
// Created by 姚远 on 2022/10/2.
//

#include "no3.h"

//如果一个类中什么成员都没有，简称空类，空类中什么都没有吗？并不是，任何一个类在我们不写的情况下，都会自动生成下面6个成员函数
//1、初始化和清理： 构造函数、析构函数
class Date31{
public:
    //构造函数一般写他，全缺省的
    Date31(int year=0,int mouth=1,int day=1){
        _year = year;
        _mouth = mouth;
        _day = day;
        std::cout << "date" << this << std::endl;
    }
    //析构函数
    ~Date31(){
        std::cout << "~date: " << this <<std::endl;
    }
private:
    //编译器不会对类中的内置类型做处理，内置类型：int char 。。。。。
    //而是会对类中成员为自定义类型的成员调用他的构造函数初始化
    int _year;
    int _mouth;
    int _day;
};



class Date32{
public:
    Date32(int year =0 ,int mouth=1,int day=1){
        _year = year;
        _mouth = mouth;
        _day = day;
    }

    //拷贝构造函数,注意：拷贝构造函数的参数只能写引用，
    // 要是写成值拷贝的话，就会形成形参要去拷贝实参，就又形成了一个拷贝构造，而这里面又要形参拷贝实参，就无穷无尽了。
    Date32(Date32& d) {
        _year = d._year;
        _mouth = d._mouth;
        _day = d._day;
    }

    void Print(){
        std::cout << _year << "-" << _mouth << "-" << _day << std::endl;
    }

private:
    int _year;
    int _mouth;
    int _day;
};

void Test32(){
    Date32 d1(2022,10,2);
    //如果我想创建一个和d1相同的实例怎么办呢？
    Date32 d2(d1);  //拷贝构造

    d1.Print();
    d2.Print();

}


void Test31(){
//    Date31 d1;
//    Date31 d2;
}

