//
// Created by 姚远 on 2022/10/8.
//

#include "no5.h"


//1、在构造函数中尽量去使用初始化列表
//注意: 初始化列表在初始化时是按照成员变量声明的顺序来的，不是按照初始化列表的顺序。
//建议声明和定义的顺序写成一样
class no5Date{
public:
    //必须在初始化列表初始化的：1、const成员 2、引用成员变量  3、没有默认构造函数的自定义成员变量
    no5Date(int year,int month,int day)
    :_year(year),   //可以理解为成员变量的定义
    _month(month),
    _day(day)
    {}


private:
    //成员变量的声明
    int _year;
    int _month;
    int _day;
    //no5Date& _d;
    //const int _n;
    //没有默认构造函数的自定义成员变量
};


//2、explicit 关键字，禁止构造函数的隐式类型转换。
class no5Date2{
public:
    //Clang-Tidy:使用单个参数可调用的构造函数必须标记为显式的，以避免无意的隐式转换
    explicit no5Date2(int year=0,int month=1,int day=1)
    :_year(year),
    _month(month),
    _day(day)
    {}

private:
    int _year;
    int _month;
    int _day;
};


void TestNo5Date2(){
    no5Date2 d1(1,2,3);
    //以下是隐式类型转换，他们都会先构造一个临时变量，再赋值过去。

    //no5Date2 d2 = 1;                        //C++98
    //no5Date2 d4 = {1,2,3}; //C++11
}


//求1+2+3+。。。+n，要求不能使用乘除法、for、while、if、else、switch、case、递归等关键字以及三目
class sum{
public:
    sum(){
        _sum += _i;
        _i++;
    }
    static int GetSum(){
        return _sum;
    }

private:
    static int _i;
    static int _sum;
};
int sum::_i = 1;
int sum::_sum = 0;


class Solution{
public:
    int sum_Solution(int n){
        sum a[n];
        return sum::GetSum();
    }
};

int Sum(int n){
    int sum = 0;
    while (n){
        sum += n;
        n--;
    }
    return sum;
}

void TestSum(){
    Solution a;
    int sum = a.sum_Solution(5);
    int sum2 = Sum(5);
    std::cout << "Sum(100) return sum : " << sum2 << std::endl;
    std::cout << "sum_Solution(100) return sum : " << sum << std::endl;
}