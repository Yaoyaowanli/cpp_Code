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


//引用：引用不是新定义一个变量，而是给已有变量起了一个别名，编译器不会为其开辟空间，他和他引用的变量共用一块空间
void Test3(){
    int a = 10;
    int& ra = a; //表示ra是a的引用，引用也就是别名，给a起了个别名叫ra
    int& b = a;  //b的类型还是int，因为他是a的别名
    int& c = b;
//引用的特性：  1、引用必须在定义的时候初始化。  2、一个变量可以有多个引用。  3、一个引用一旦引用了一个实体，就不能再引用其他实体。

    //常引用
    const int aa = 99;
    // int& bb = aa; 错误，因为aa是一个const修饰的，他只能被读，不能被修改，这里用int&是错的
    const int& bb = aa;

    int a1 = 22;
    int& b1 = a1;
    const int& c1 = a1; //这也是可以的，虽然a是可读可写的，但他的引用只要不放大其操作权限就可以，这时使用c就是只读的。

    int i =0;
    double ai = i; //隐士类型转换。
    //double& bi = i; 错误
    const double& bi = i;  //可以，因为这里会进行隐士类型转换，会在转换时创建一个临时变量，这个临时变量具有常性，
                            //这里的 bi 引用的其实是这个临时变量.
}

//使用引用的场景
//1、做参数
void Swap_Cpp(int& a,int& b){
    int tmp = a;
    a=b;
    b=tmp;
}
//2、引用做返回值
//这里返回的int其实不是n，返回的是一个临时空间，把n赋给了这个临时变量，再把他返回
int Count1()
{
    static int n = 0;
    n++;
    return n;
}
//这里返回的是一个int&，返回是也会发生临时变量赋值，不过这里是引用，所以返回的是n的别名。也就是n。
int& Count2()
{
    static int x = 0;
    x++;
    return x;
}
void Test4(){
    //int& r1 = Count1();   这里编不过，因为返回的那个临时变量具有常性，要想以引用接收就要加const才能接收。
    const int& r1 = Count1();
    //经过调试观察，发现n的地址和接收返回值后的r1地址不同，说明函数count1在返回时确实是把n赋给了临时变量，返回了临时变量，而这个临时变量具有
    //常性，所以r1引用接收时 才需要加const修饰。
    int& r2 = Count2();
    //经过调试观察，x的地址，和返回后的r2地址相同，说明返回值为引用时，确实会把函数里面的变量引用返回。
    //如果一个函数要使用引用返回，那么返回的变量出了函数的作用域必须还存在，否则就是不安全的。
    // 常见的做法是在函数内给返回变量加上static修饰生命周期。
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
