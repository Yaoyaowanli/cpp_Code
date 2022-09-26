#include <iostream>
//using namespace std;  //c++库中的所有东西都是放在命名空间里的
using std::cout;
using std::cin;
using std::endl;



//缺省参数
void Func1(int a = 0){
    cout << a << endl;
}

//半缺省参数 : 缺省部分参数,没有缺省值的参数必须要传
void Func3(int a ,int b = 111,int c=222){
    cout << "Func3: " << a << " " << b << " " << c << endl;
}

//全缺省参数 : 可以所有参数都不传，全使用缺省值，也可以传部分参数，其余的使用缺省值
void Func2(int a=10 , int b=20 , int c=30){
    cout << "Func2: " << a << " " << b << " " << c << endl;
}

void Test1(){
    std::cout << "Hello, World!" << std::endl;
    int a = 1;
    double b = 1.1;
    std::cout << a << " " << b << std::endl;

    //std::cin >> a >> b ;
    std:: cout << a << " " << b << std::endl;

    //缺省参数
    Func1();
    Func1(10);
    //全缺省参数
    cout << "全缺省参数:" << endl;
    Func2();
    Func2(1);
    Func2(1,2);
    Func2(11,22,33);

    cout << "半缺省参数:" << endl;
    Func3(9);
    Func3(9,99);
    Func3(9,99,999);
    cout << "------------------------------------------------------------------" << endl;

}

//函数重载: 指可以有多个函数他们的函数名字相同，但是执行的代码却不同
//本质：通过识别不同 顺序 or 类型 or 参数个数 来识别具体去执行哪个同名的函数
//要求 ： 函数的参数 or 类型 or 顺序，任何一个不同都可以,但是返回值不同不构成重载
int Add(int a, int b){
    return a+b;
}
double Add(double a, double b){
    return a+b;
}
long Add(long a,long b){
    return a+b;
}

//顺序不同:
void Func1(int a, char b){

}
void Func1(char b,int a){

}
void Func1(){

}
//仅返回值不同不构成重载
// error: functions that differ only in their return type cannot be overloaded
//int Func1(){}

void Test2(){
    cout << "函数重载:" << endl;
    cout << Add(10,20) << endl;
    cout << Add(1.1,2.2) << endl;
    //注：这里参数后的 "L" 是指把11，22这个整数当作长整形来处理
    cout << Add(11L,22L) << endl;
    cout << "------------------------------------------------------------------" << endl;
}

int main() {
    Test1();
    Test2();

    return 0;
}
