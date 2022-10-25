//
// Created by 姚远 on 2022/10/24.
//

#ifndef CPP_CODE_INHERITANCE_H
#define CPP_CODE_INHERITANCE_H

#endif //CPP_CODE_INHERITANCE_H
#pragma once
#include <iostream>
#include <string>
using namespace std;
//继承

/*//父类、基类
class person{
public:
    void print(){
        cout << "name: " << _name << endl;
        cout << "age: " << _age << endl;
    }

    void set(const string& s,const int& x){
        _name = s;
        _age = x;
    }

protected:
    string _name = "yaoYuan";
    int _age = 18;
};

//子类、派生类
class student : public person {
//student 类 public继承了 person 类，他拥有person类的所以成员以及函数，
// person 类中protected限定的成员和函数何以在student里面进行访问，
// 但是private限定的成员以及函数在类中或类外均不可见。（但是student类还是会继承person中private的成员以及函数）
protected:
    int _stuId = 1;
};

class teacher : public person{
protected:
    int _jobId = 99;
};*/





class person{
public:
    virtual void print(){
        cout << "name: " << _name << endl;
        cout << "age: " << _age << endl;
    }

    void set(const string& s,const int& x){
        _name = s;
        _age = x;
    }

protected:
    string _name = "yaoYuan";
    int _age = 18;
};


class student : public person{
//student 继承了 person 他们中有一个_age变量同名了，此时stu类就会屏蔽person类中的_age这个行为叫隐藏，直接_age访问的就是子类的age
//如果想要访问基类的_age需要指定作用域,函数只要同名就会发生隐藏
public:
    //子类print函数
void print(){
        //基类print函数
    person::print();
        //第一个为子类_age
    cout << _age << endl;
        //第二个为基类_age
    cout << person::_age << endl;
}
protected:
    int _age = 99;
};




//派生类的默认成员函数
//基类
class person2{
public:
    person2(const char* name = "peter")
    :_name(name)
    {
        cout << "person2()" << endl;
    }
    person2(const person2& p) :_name(p._name) {
        cout << "person2(const person2&)" << endl;
    }
    person2& operator= (const person2& p){
        cout << "operator= (const person2& p)" << endl;
        if (this != &p){
            _name = p._name;
        }
        return *this;
    }
    ~person2(){
        cout << "~person2()" << endl;
    }
protected:
    string _name;
};


//子类
class student2 : public person2{
public:
    //1、构造函数
    //派生类的构造函数必须调用基类的构造函数来初始化基类的那一部分成员，且要保证先初始化基类，在初始化派生类.
    //如果基类没有默认的构造函数，则需要在派生类构造函数的初始化列表中调用基类的构造函数。
    student2(const char* name,int num) : person2(name),_num(num){
        cout << "student2()" << endl;
    }

    //2、拷贝构造
    //派生类对象的拷贝构造函数要先调用基类的拷贝构造来完成基类那部分的拷贝构造
    student2(const student2& s)
    //这里的s为什么可以传给person2的构造函数呢？
    //因为person2拷贝构造函数的person2(const person2& p)
    //在传参数时发生了切片、切割，子类可以赋值给父类/父类指针/父类引用。
    : person2(s),
    _num(s._num)
    {
        cout << "student2(const student2& s)" << endl;
    }

    //3、operator=
    //派生类的operator=必须先调用基类的operator=来完成对基类部分的赋值
    student2& operator= (const student2& s){
        cout << "operator= (const student2& s)" << endl;
        if (this != &s){
            //这里发生了类中函数的隐藏，父子函数只要同名就会发生隐藏，通过函数名访问到的只有子类的函数
            //要想访问父类的该名函数，就需要指定域
            person2::operator=(s);
            _num = s._num;
        }
        return *this;
    }

    //4、析构函数
    //派生类对象的析构必须先调用派生类的析构函数完成派生类的清理后再调用基类的析构函数完成对基类部分的析构。
    ~student2(){
        //~person2();  这里也构成隐藏，为什么函数名不一样也构成隐藏呢？
        //因为他们的名字会被编译器统一处理成destructor（多态有关）
        //而且这里也不需要显示的调用，函数结束时，他会自动调用基类的析构
        cout << "~student2()" << endl;

    }

protected:
    int _num;
};

class teacher2 : public person2{

protected:
    int _jobId;
};





//如何设计一个不能被继承的类
//让其构造函数私有化
class A{

private:
    A(){}
};






//菱形继承
class person3{
public:
    string _name;
};

//解决冗余和二义性，需要使用虚继承
class student3 : virtual public person3{
protected:
    int _stu_id;
};

class teacher3 : virtual public person3{
protected:
    int _job_id;
};

class assistant : public student3,public teacher3{
    string _major_course;
};









//内存对象模型（对象在内存中是怎么存的？）
class A4{
public:
    int _a;
};

class B4 : public A4{
public:
    int _b;
};

class C4 : public A4{
public:
    int _c;
};

class D4 : public B4,public C4{
public:
    int _d;
};



class A5{
public:
    int _a;
};

class B5 : virtual public A5{
public:
    int _b;
};

class C5 : virtual public A5{
public:
    int _c;
};

class D5 : public B5,public C5{
public:
    int _d;
};




void test_inheritance1();
void test_inheritance2();
void test_inheritance3();
void test_inheritance4();