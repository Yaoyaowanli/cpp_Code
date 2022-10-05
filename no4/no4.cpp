//
// Created by 姚远 on 2022/10/5.
//

#include "no4.h"

class no4Date{

public:
    //构造函数:函数体内赋值
   /* no4Date(int year=0, int month=1 , int day = 1){
        _year = year;
        _month = month;
        _day = day;
    }*/
   no4Date(int year=0, int month=1, int day=1)
   :_year(year),_month(month),_day(day)
   {
       //初始化列表
   }


    void f(const no4Date& d){
        //这里报错了，d无法调用Print（）函数，为什么？
        d.Print();
    }
    //因为方法f的参数类型是const no4Date& ，说明他是一个const修饰的引用。而print的参数是隐含的 *this，没有const，会造成权限的放大
    //所以才会报错，给no4Date* this加上const修饰就好了。
    //那么no4Date* this 是隐含的，我们怎么给他加上const修饰呢？
    //修饰隐含的this指针需要把const加在参数列表后面
    // void Print() ->  void Print()const
    //编译器编译
    // void Print(no4Date* this) -> void Print(const no4Date* this)
    void Print()const{
        std::cout << _year << " - " << _month << " - " << _day << std::endl;
    }
    //const Date* p1  -> 指向的对象是const的  指向常量的指针
    //Date const * p2 -> 指向的对象是const的  指向常量的指针
    //Date* const p3 -> 指针是const的       常指针
    //const Date* const p4 -> 常指针常量，指向常量的常指针

private:
    int _year;
    int _month;
    int _day;
};



class A{
public:
    A(int a)
    :_a(a)
    {   }

private:
    int _a;
};

class B{
public:
    B(int a,int ref)
    : _aobj(a),
    _ref(ref),
    _n(10)
    {   }
//成员变量在初始化列表初始化时，是按照在类中声明的先后顺序来进行初始化的，与其在初始化列表中的顺序无关。

private:        //有些成员必须在初始化列表初始化
    A  _aobj;   // 1、没有默认构造函数的
    int& _ref;  // 2、引用
    const int _n;   //3、const
};

//explicit 关键字
class no41Date {

public:
    //这里加上explicit 下面就不会发生隐士类型转换了
    explicit no41Date(int year=0, int month=1, int day=1)
    :_year(year),
    _month(month),
    _day(day)
    { }

private:
    int _year;
    int _month;
    int _day;
};


void TestNo41Date(){
    no41Date m1(2022,10,14);  //构造函数
    //类型'no41Date'的非const左值引用不能绑定到'int'类型的临时对象
    //no41Date& m2 = 2022;  //隐士类型转换，他会先构造出一个临时的tmp，再用tmp构造m2， 但是这里编译器直接优化成直接构造m2了
    //const no41Date& m2 = 2022;
    //这里会产生一个临时的tmp，具有常性，所以需要+const 才能引用，他引用的是中间产生的临时变量
    no41Date m3 = m1;  //拷贝构造
}

// static 成员
//声明为static的类成员称为类的静态成员，用static修饰的成员变量，称为静态成员变量，用static修饰的函数，称为静态成员函数，
//静态的成员变量一定要在类外面进行初始化。

//设计一个类，可以计算这个类总计产生了多少对象

class D {
public:
    D(){
        ++n;
    }
    D(const D& a){
        ++n;
    }

    static int GetN(){  //没有this指针，函数中不能访问非静态的成员
        return n;
    }

private:
    static int n;   //这里声明不是属于某个对象，而是属于该类的所有对象。
};

int D::n = 0;

D f2(D a){
    return a;
}

void TestNo4A(){
    D a1;
    D a2;
    f2(a1);
    f2(a2);

    std::cout<< a1.GetN() << a2.GetN() << D::GetN() << std::endl;

}


