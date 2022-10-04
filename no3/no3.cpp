//
// Created by 姚远 on 2022/10/2.
//

#include "no3.h"

//如果一个类中什么成员都没有，简称空类，空类中什么都没有吗？并不是，任何一个类在我们不写的情况下，都会自动生成下面6个成员函数
//1、初始化和清理： 构造函数、析构函数
//2、拷贝构造和operator=   ：这两个默认成员函数会按一个一个字节的值拷贝（浅拷贝）
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


//3、拷贝构造函数,注意：拷贝构造函数的参数只能写引用，
class Date32{
public:
    Date32(int year =0 ,int mouth=1,int day=1){
        _year = year;
        _mouth = mouth;
        _day = day;
    }

    //拷贝构造函数,注意：拷贝构造函数的参数只能写引用，
    // 要是写成值拷贝的话，就会形成形参要去拷贝实参，就又形成了一个拷贝构造，而这里面又要形参拷贝实参，就无穷无尽了。
    Date32(const Date32& d) {
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


//运算符重载
//C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有其返回值类型、函数名字以及参数列表，其返回值类型与参数列表
//与普通函数类似。
//函数名字为：关键字operator后面接需要重载的运算符符号。
//函数原型 ：  返回值类型 operator操作符 （参数列表）
//有5个操作符不能重载 ： 1、" .* " 2、" :: " 3、" sizeof " " ?: " " . "
class Date33 {
public:

    //这里有2个参数，还有一个参数是隐含的this指针
    bool operator== (const Date33& d) {     //bool operator==(Date33* this,const Date& d)
        return this->_year == d._year
        && this->_mouth == d._mouth
        && this->_day == d._day;
    }

    bool operator> (const Date33& d){
        if(this->_year > d._year){
            return true;
        }else if (this->_year < d._year){
            return false;
        }else{
            if (this->_mouth > d._mouth){
                return true;
            }else if (this->_mouth < d._mouth){
                return false;
            }else{
                if(this->_day > d._day){
                    return true;
                }else if (this->_day < d._day){
                    return false;
                }else{
                    return false;
                }
            }
        }
    }

    Date33(int year=0, int mouth=1, int day=1){
        _year = year;
        _mouth = mouth;
        _day = day;
    }

    Date33(Date33& d){
        _year = d._year;
        _mouth = d._mouth;
        _day = d._day;
    }

    //这里参数要设置为引用，不然的话会发生拷贝构造
    bool IsDateEqual (const Date33& d1,const Date33& d2){
        //......
    }

private:
    int _year;
    int _mouth;
    int _day;
};

//
/*bool operator== (const Date33& d1 , const Date33& d2){
    return d1._year==d2._year
           && d1._mouth == d2._mouth
           && d1._day == d2._day;
}*/


void Test33(){
    Date33 d1(2022,10,5);
    Date33 d2(2022,10,5);
    //假设我们要比较两个日期实例是否相等，该如何做？
    //这里==是运算符重载，编译器在这里会把d1==d2 -> operator==(d1,d2)
    bool a = d1==d2;
    std::cout << "重载运算符== ：" << a << std::endl;
    //我们也可以直接调用运算符重载函数。但是一般不用。
    //bool b = operator==(d1,d2);
    //std::cout << "operator==(d1,d2) :" << b << std::endl;
    bool b = d1>d2;
    std::cout << "重载 d1>d2 :" << b << std::endl;

}


//实现一个完善的日期类
class MyDate{
public:

    //操作符重载
    bool operator==(const MyDate& date){
        return this->_year == date._year
        && this->_month == date._month
        && this->_day == date._day;
    }

    bool operator!=(const MyDate& date){
        return !(*this == date);
    }

    bool operator>(const MyDate& date){
        if (this->_year > date._year){
            return true;
        }else if (this->_year == date._year && this->_month > date._month){
            return true;
        }else if (this->_year == date._year && this->_month == date._month && this->_day > date._day){
            return true;
        }

        return false;
    }

    bool operator>= (const MyDate& date){
        return *this == date || *this > date;
    }

    bool operator< (const MyDate& date){
        return !(*this >= date);
    }

    bool operator<= (const MyDate& date){
        return !(*this > date);
    }

    //重载+ 日期+天数
    MyDate operator+ (int day){
        //拷贝构造一个调用者
        MyDate ret = *this;
        ret._day += day;
        //while判断day的值是否合法
        while(ret._day > GetMonthDay(ret._year,ret._month) ){
            //不合法，需要进位
            //在这里day减掉当月的天数，然后month进位
            ret._day -= GetMonthDay(ret._year,ret._month);
            ret._month++;

            //处理月满年进位问题
            if (ret._month == 13){
                ret._year++;
                ret._month = 1;
            }
        }
        return ret;
    }

    //重载+=
    MyDate& operator+= (int day){
        this->_day += day;
        while (this->_day > GetMonthDay(this->_year, this->_month)){
            this->_day -= GetMonthDay(this->_year,this->_month);
            this->_month++;

            if(this->_month == 13){
                this->_year++;
                this->_month = 1;
            }
        }

        return *this;
    }

    //重载=操作符
    MyDate& operator= (const MyDate& d){
        if(this != &d){
            this->_year = d._year;
            this->_month = d._month;
            this->_day = d._day;
        }

        return *this;
    }

    MyDate& operator-= (int day){
        this->_day -= day;
        while (this->_day < 1){
            this->_month--;
            if(this->_month < 1){
                this->_year--;
                this->_month = 12;
            }
            this->_day += GetMonthDay(this->_year, this->_month);
        }

        return *this;
    }

    MyDate operator-(int day){
        MyDate ret = *this;
        ret-=day;
        return ret;
    }



    int operator- (const MyDate& d){
        MyDate max = *this;
    }

    int GetMonthDay(int year, int month){
        static int monthDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        //是2月且年可以被4整除并且不能被100整除，或者可以被400整除
        if (month==2 && ((year%4==0 && year%100 != 0) || year%400 ==0)){
            return 29;
        }

        return monthDays[month];
    }
    //构造函数
    MyDate(int year=0,int month= 1,int day = 1){
        if (year>=0 && month>=1 && month <= 12 && day>=1 && day <= GetMonthDay(year,month)){
            this->_year = year;
            this->_month = month;
            this->_day = day;
        }else{
            std::cout << "日期非法" << std::endl;
        }
    }
    //拷贝构造
    MyDate(MyDate& date){
        this->_year = date._year;
        this->_month = date._month;
        this->_day = date._day;
    }

    void Print(){
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    };


private:
    int _year;
    int _month;
    int _day;
};


void Test34(){
    //构造和拷贝构造
    MyDate date1(2022,10,31);
    date1.Print();
    MyDate date2(date1);
    date2.Print();
    //重载操作符test
    MyDate date3(2022,10,14);
    MyDate date4(2022,10,14);
    std::cout<< "date3 == date4 ? " << (date3 == date4) << std::endl;
    MyDate date5(2022,11,14);
    MyDate date6(2022,10,14);
    std::cout<< "date5 > date6 ? " << (date5>date6) << std::endl;
    std::cout<< "date5 < date6 ? " << (date5<date6) << std::endl;

    std::cout<< "date5 <= date6 ? " << (date5<=date6) << std::endl;
    std::cout<< "date5 >= date6 ? " << (date5>=date6) << std::endl;
    MyDate date9;
    date9 = (date6+100);
    std::cout << "date6 + 10day =" ;
    date9.Print();
    std::cout << std::endl;

    MyDate date7(2022,10,14);
    date7+=10;
    std::cout << "date7+=10 = ";
    date7.Print();
    std::cout << std::endl;

    //赋值重载
    MyDate m1(2022,10,14);
    MyDate m2;
    m2 = m1;
    m1.Print();


    MyDate m3(2022,10,14);
    MyDate m4(2022,1,4);
    m4 = m3;
    m3.Print();
    m4.Print();
}


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


class mydate{

public:
    void Print(){
        std::cout << _year << " - " << _month << " - " << _day << std::endl;
    }
    //构造函数
    mydate(int year=0,int month=1,int day=1){
        _year = year;
        _month = month;
        _day = day;
    }
    //拷贝构造
    mydate(const mydate& d){
        _year = d._year;
        _month = d._month;
        _day = d._day;

        std::cout << "我是拷贝构造～" << std::endl;
    }
    //赋值操作符重载
    mydate& operator= (const mydate& d){
        if (this != &d){
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        std::cout << "我是赋值重载～" << std::endl;
        return  *this;
    }
private:
    int _year;
    int _month;
    int _day;
};

void Test35(){
    //构造
    mydate m1(2022,10,11);
    mydate m2(2022,10,14);
    //赋值重载
    m1 = m2;
    std::cout << "m1:";
    m1.Print();
    std::cout << std::endl;

    std::cout << "m2:";
    m2.Print();
    std::cout << std::endl;

    //拷贝构造
    mydate m3(m1);
    //拷贝构造
    mydate m4 = m1;
    std::cout << "m3:";
    m3.Print();
    std::cout << std::endl;

    std::cout << "m4:";
    m4.Print();
    std::cout << std::endl;

}