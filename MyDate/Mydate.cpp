//
// Created by 姚远 on 2022/10/4.
//

#include "Mydate.h"

void myDate::Print(){
    std::cout << _year << " - " << _month << " - " << _day << std::endl;
}

int myDate::GetMonthDay(const int year,const int month){
    static int monthDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    //闰年
    if (month==2 && ((year%4==0 && year%100!=0) || year%400==0)){
        return 29;
    }
    return monthDays[month];
}


//构造函数
myDate::myDate(int year , int month , int day){
    if (year>=0 && month <13 && month > 0 && day > 0 && day < GetMonthDay(year,month)){
        _year = year;
        _month = month;
        _day = day;
        std::cout << "构造函数" << this <<std::endl;
    }else{
        std::cout << "非法日期"<<std::endl;
    }
}

//析构函数
myDate::~myDate(){
    std::cout << "资源清理~" << this <<std::endl;
}

//拷贝构造
myDate::myDate(const myDate& d){
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

//赋值重载
myDate& myDate::operator= (const myDate& d1){
    if (this != &d1){
        _year = d1._year;
        _month = d1._month;
        _day = d1._day;
        return *this;
    }

}



//操作符重载
inline bool myDate::operator== (const myDate& d1) const{
    return _year==d1._year && _month==d1._month && _day==d1._day;
}

bool myDate::operator!= (const myDate& d1) const{
    return !(*this == d1);
}

inline bool myDate::operator>(const myDate& d1)const{
    if(_year > d1._year){
        return true;
    }else if (_year == d1._year && _month > d1._month){
        return true;
    }else if (_year == d1._year && _month == d1._month && _day > d1._day){
        return true;
    }

    return false;
}

bool myDate::operator<(const myDate& d1)const{
    return !(*this > d1);
}

bool myDate::operator>=(const myDate& d1)const{
    return !(*this < d1);
}


bool myDate::operator<=(const myDate& d1)const{
    return !(*this > d1);
}

myDate myDate::operator+(const int day)const{
    myDate ret = *this;
    ret._day += day;
    //判断day是否合法，是否需要向上进位
    while (ret._day> GetMonthDay(ret._year,ret._month)){
        ret._day -= GetMonthDay(ret._year,ret._month);
        ret._month++;

        //处理年进位
        if (ret._month == 13){
            ret._year++;
            ret._month = 1;
        }
    }
    //这里的ret出了函数就会被销毁，所以要传拷贝
    return ret;
}

myDate& myDate::operator+=(int day){
    if (day < 0){
        return *this-= -day;
    }
    _day+=day;
    while(_day > GetMonthDay(_year,_month)){
        _day -= GetMonthDay(_year,_month);
        _month++;

        if (_month == 13){
            _year++;
            _month = 1;
        }
    }

    return *this;
}

myDate& myDate::operator-=(int day){
    if (day < 0){
        return *this += -day;
    }
    _day -= day;
    while (_day < 1){
        _month--;
        if (_month == 0){
            _year--;
            _month=12;
        }
        _day += GetMonthDay(_year,_month);
    }
    return *this;
}

myDate myDate::operator-(int day)const{
    myDate ret = *this;
    ret-=day;
    return ret;
}

//前置++
myDate& myDate::operator++(){
    return *this+=1;
}

//后置++,约定加一个int区分,后置++返回的是++以前的值，这个值就不能再被修改了.
myDate myDate::operator++(int){
    myDate ret = *this;
    *this += 1;
    return  ret;
}

//前置--
myDate& myDate::operator--(){
    return *this-=1;
}

//后置--
myDate myDate::operator--(int){
    myDate ret = *this;
    *this-=1;
    return ret;
}

int myDate::operator-(const myDate& d1)const{
    int flag = 1;
    myDate max = *this;
    myDate min = d1;
    if (*this < d1){
        min = *this;
        max = d1;
        //如果发生交换了，就说明外面是在用一个小的年减去大的年，要返回负数，所以把flag置为-1，在结束时让他*count。
        flag = -1;
    }
    int count = 0;
    while (min != max){
        ++min;
        count++;
    }
    return count * flag;
}



void TestMyDate(){
   /* std::cout << "test 构造函数" << std::endl;
    myDate m1(2022,10,14);
    m1.Print();
    myDate m2;
    m2.Print();

    myDate m3(m1);
    myDate m4 = m3;
    m3.Print();
    m4.Print();
*/

   /*myDate m1(2022,10,14);
   //(m1+100).Print();
    myDate m3;
    m3 = m1;*/

   /*myDate m1(2022,10,14);
   m1-=10;
   m1.Print();
   myDate m2;
   m2 = m1 - 1;
   m2.Print();
   m1.Print();*/

   myDate m1(2022,10,14);
   m1 += -100;
   m1.Print();

}