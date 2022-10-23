//
// Created by 姚远 on 2022/10/23.
//

#include "template.h"



//#define N 100

//之前使用模版定义的都是类型
//template<class T> 或 template<typename T>

//非类型模版参数,给模版参数一个变量，他可以在外部传入，这个变量也可以给缺省值
// 不管给不给缺省值该参数必须在编译器确定值，就会变成一个常量，不能修改
/*template<class T,int N = 10>
class Array{
public:
    //...
private:
    T _a[N];
};*/


/*
void test_template1(){
    //Array<int> a1;
    //Array<int> a2;
    //现在a1，a2 的大小都是100，我们也可以通过修改N让他变大变小
    //那么如果想让a1 是100，a2是1000呢？
    //我们可以通过在模版中添加一个变量来做到。
    Array<int,100>a1;
    Array<int,1000>a2;
}*/



//函数模版的特化
/*
template<class T>
bool IsEqual(T& left,T& right){
    return left == right;
}

//特化 （针对某些类型的特殊化处理）
template<>
bool IsEqual<char*>(char*& left,char*& right){
    return strcmp(left,right) == 0;
}

void test_template1() {
    int a=10,b=20;
    cout << IsEqual(a,b) << endl;
    //int 类型是可以正常比较的，那么字符串指针就不行了，所以要用到模版的特化
    char* p1 = "hello";
    char* p2 = "hello";
    cout << IsEqual(p1,p2) << endl;
}*/

//类的特化
/*
template<class T1,class T2>
class Date{
public:
    Date(){
        cout << "Date(T1,T2)" << endl;
    }
};

template<>  //全特化
class Date<int,char>{
public:
    Date(){
        cout << "全特化:Date(int,char)" << endl;
    }
};

template<class T2>  //偏特化
class Date<int,T2>{
public:
    Date(){
        cout << "偏特化:Date(int,T2)" << endl;
    }
};

void test_template1() {
    Date<int,int> d1;
    Date<int,char> d2;
    Date<int,double> d3;
}
*/

/*
template<class T>
void F1(const T& x){
    cout << x << endl;
}


void test_template1() {
    F1(3);
}*/




//分离编译
//项目工程中一般将函数或类的声明放到.h文件，将函数或类的定义放到.cpp文件。
//为什么要分离编译呢？ 为了方便查看和维护

