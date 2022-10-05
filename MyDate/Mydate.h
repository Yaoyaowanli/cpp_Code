//
// Created by 姚远 on 2022/10/4.
//

#ifndef CPP_CODE_MYDATE_H
#define CPP_CODE_MYDATE_H

#endif //CPP_CODE_MYDATE_H

#include <iostream>


class myDate{

public:
    //默认成员函数1：构造函数，构造函数用于类实例的初始化，我们不写构造函数的话，编译器会默认生成一个，该函数对类中的内置类型成员不做任何动作
    //但是会对类中的自定义类型调用他的构造函数。
    //构造函数的特点有： 1、函数名和类名相同。 2、在类创建时自动调用。 3、可以构成重载。 4、无返回值
    myDate(int year=0 , int month=1 , int day=1);

    //2、默认成员函数2：析构函数,析构函数会在对象实例的生命周期结束时调用，其主要完成实例中的资源清理，如free malloc的空间等
    //如果我们不写，编译器会自动生成一个，他对内置类型同样不做动作，对实例中的自定义成员则会去调用他的析构函数。
    //析构函数的特点：1、析构函数名是（～类名） 2、无参数无返回值。 3、一个类只有一个析构函数，如果没写编译器自动生成默认的。
    //4、对象的实例生命周期结束时自动调用析构函数。
    ~myDate();

    //3、默认成员函数3：拷贝构造，是用一个对象实例去构造一个新的对象，这里必须传引用，因为传值的话会造成让形参再去构造实参，就会形成递归。
    //所以需要传引用，编译器默认的拷贝构造会按照字节拷贝。
    myDate(const myDate& d);

    //4、默认成员函数4：赋值重载，拷贝构造是去用一个已有对象实例的值去构造一个新的对象实例，而赋值重载是用一个已有对象的实例去把他的值
    // 赋值给另一个已有实例。所以赋值重载要返回的是一个已有对象的引用。这个函数也是默认成员函数之一，我们不写编译器也会自动生成一个，
    //编译器生成的是按字节拷贝赋值到已有的对象实例中。
    myDate& operator= (const myDate& d1);

    //操作符重载 : 自定义类型是不能用运算符的，如果要用就需要去重载，实现他的逻辑
    //                                 这里的const修饰的是this指针，因为如果实例是一个常量，这里不修饰this指针就可以修改常量的值
    //                                 就会造成权限破坏，所以我们需要将this修饰一下，因为this本来是一个常量指针，我们要修饰他为
    //                                 常量指针常量，即指向常量的常量指针。
    bool operator== (const myDate& d1) const;

    bool operator!= (const myDate& d1) const;

    bool operator>(const myDate& d1)const;

    bool operator<(const myDate& d1)const;

    bool operator>=(const myDate& d1)const;

    bool operator<=(const myDate& d1)const;

    myDate operator+(int day)const;

    myDate& operator+=(int day);

    myDate& operator-=(int day);

    myDate operator-(int day)const;

    myDate& operator++();

    myDate operator++(int);

    myDate& operator--();

    myDate operator--(int);

    int operator-(const myDate& d1)const;


        //形参的常量限定只在函数的常量定义中起作用，声明中参数列表可以不写const，在定义的参数列表加上const就行了
    static int GetMonthDay(int year,int month);
    void Print();



private:
    int _year;
    int _month;
    int _day;
};





void TestMyDate();