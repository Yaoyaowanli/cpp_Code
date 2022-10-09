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

    static void Init(){
        _i = 1;
        _sum = 0;
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
        sum::Init();
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
    int sum = a.sum_Solution(100);
    int sum2 = Sum(100);
    std::cout << "Sum(100) return sum : " << sum2 << std::endl;
    std::cout << "sum_Solution(100) return sum : " << sum << std::endl;
}

class no5Date3{
public:
    void Print(){
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }

private:
    //C++11
    // 非静态成员变量，可以在声明时给缺省值
    int _year = 0;
    int _month = 1;
    int _day = 1;
    //static int _n = 0;    不行，静态成员必须在类外初始化，不能在类中赋予缺省值。
};

void TestNo5Date3(){
    no5Date3 n1;
    n1.Print();
}


//      友元  friend
// 友元分为友元函数和友元类
//友元提供了一种突破封装的方式，有时候提供了便利，但是友元会增加耦合度，破坏了封装，所以不宜多用。

class no5Date4{

    friend void func(no5Date4& d);  //友元函数
    friend std::ostream& operator<<(std::ostream& out,const no5Date4& d1);
    friend std::istream& operator>>(std::istream& in,no5Date4& d1);


public:
    void Print() const{
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }

    no5Date4(int year,int month,int day)
    :_year(year),
    _month(month),
    _day(day)
    {}

    //这里由于类中操作符重载类变成了隐含的this指针，默认他是第一个参数，就变成了左操作数，在调用时会变成：n1.operator<<(std::cout);
    //  n1 << std::cout;  很别扭，所以这里要想办法将this指针放到第二个参数上去，这是就用到友元函数了。
   /* void operator<<(std::ostream& out) const{
        out << _year << "/" << _month << "/" << _day << std::endl;
    }*/

private:
    int _year=0;
    int _month=1;
    int _day = 1;
};


void func(no5Date4& d){
    //假设现在类外有函数想访问类中保护的变量
    d._year = 10;
}

//这里不是类中所以没有默认的this指针，我们自己可以交换参数位置了，重载后将这个函数声明为友元函数。
//就可以做到调用：std::cout << n1;
std::ostream& operator<<(std::ostream& out,const no5Date4& d1){
    out << d1._year << "/" << d1._month << "/" << d1._day << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in,no5Date4& d1){
    in >> d1._year >> d1._month >> d1._day;
    return in;
}

void TestNo5Date4(){
    no5Date4 n1(2022,10,9);
    no5Date4 n2(2022,10,14);
    n1.Print();
    func(n1);
    n1.Print();

    std::cout << n1;
    std::cout << n1 << n2;
    std::cout << "请输入：" << std::endl;
    std::cin >> n1 >> n2;

    std::cout <<"over:" << std::endl << n1 << n2 << std::endl;
    //n1.operator<<(std::cout);
    //n1 << std::cout;
}

//  友元类

class Time51{

    friend class Date51;

public:
    Time51(int hour=0,int minute=0,int second=0)
    :_hour(hour),
    _minute(minute),
    _second(second)
    {}

private:
    int _hour;
    int _minute;
    int _second;
};

class Date51{
public:
    Date51(int year,int month,int day)
    :_year(year),
    _month(month),
    _day(day)
    {}


    void SetTime51(int hour,int minute,int second){
        //Date51是Time51的友元类，我们可以突破类域在Date中访问修改Time51的保护成员变量。
        this->_t1._hour = hour;
        this->_t1._minute = minute;
        this->_t1._second = second;
    }

private:
    int _year;
    int _month;
    int _day;
    Time51 _t1;
};



//匿名对象


class Solution2{
public:

    Solution2(){
        std::cout << "Solution2()" << std::endl;
    }

    ~Solution2(){
        std::cout << "~Solution2()" << std::endl;
    }

    int sum_Solution2(int n){
        return n;
    }
};


void TestSolution2(){
    Solution2 s1;   //s1的生命周期在main函数里
    s1.sum_Solution2(5);

    //也可以匿名创建对象
    Solution2();  //匿名对象
    //使用匿名对象调动方法
    Solution2().sum_Solution2(10);    //这个对象的生命周期在这一行
}


// C++中处于不同地方的类的实例构造和析构的顺序
class Ano5{
public:
    Ano5(){
        std::cout << "Ano5()" << std::endl;
    }
    ~Ano5(){
        std::cout << "~Ano5()" << std::endl;
    }
};
class Bno5{
public:
    Bno5(){
        std::cout << "Bno5()" << std::endl;
    }
    ~Bno5(){
        std::cout << "~Bno5()" << std::endl;
    }
};

class Cno5{
public:
    Cno5(){
        std::cout << "Cno5()" << std::endl;
    }
    ~Cno5(){
        std::cout << "~Cno5()" << std::endl;
    }
};
class Dno5{
public:
    Dno5(){
        std::cout << "Dno5()" << std::endl;
    }
    ~Dno5(){
        std::cout << "~Dno5()" << std::endl;
    }
};

//Cno5 c;
void TestABCD(){
    Ano5 a;
    Bno5 b;
    static Dno5 d;
}
//结论：  构造：C A B D     析构： B A D C
