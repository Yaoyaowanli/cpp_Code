//
// Created by 姚远 on 2022/10/9.
//

#include "no6.h"



// C++内存管理

//在C语言中，我们申请内存需要使用到malloc、realloc、calloc
//malloc是在堆上申请一块指定大小的内存并返回他的起始位置指针，如果申请失败就返回空指针
//calloc是在堆上申请指定大小的空间，并全部初始化为0
//realloc是扩容，会在堆上申请指定大小的空间，并把原来的数据拷贝过去，并返回新的起始位置指针。


//C++给了新的方式来申请内存

void TestNo6(){
    //C  函数
    int* p1 = (int *)malloc(sizeof(int));
    int* p11 = (int*)malloc(sizeof(int)*10);
    free(p1);
    free(p11);

    //C++  操作符
//    int* p2 = new int;
    int* p2 = new int(10);  //申请一个int初始化为10。
    int* p22 = new int[10];
    delete p2;
    delete []p22;
}



//new和delete的意义何在？
//1、对于申请内置类型，他们的效果是一样的。
//2、对于申请自定义类型，申请空间+构造函数初始化
//3、对于释放自定义类型，析构+释放空间

class Ano6{
public:
    Ano6(){
        _a=0;
        std::cout << "Ano6()" << std::endl;
    }

    ~Ano6(){
        std::cout << "~Ano6()" << std::endl;
    }

private:
    int _a;
};

void TestAno6(){
    Ano6* p1 = (Ano6*) malloc(sizeof(Ano6));  //申请空间

    Ano6* p2 = new Ano6;  //申请空间+初始化

    free(p1);  //释放空间
    delete p2;  //析构+释放空间
}


//C语言中关于结构体的创建和初始化的方式
typedef struct ListNode_c {
    int _val;
    struct ListNode_c* _next;
    struct ListNode_c* _prev;
}ListNode_c;

ListNode_c* BuyListNode(int val){
    ListNode_c* p = (ListNode_c*)malloc(sizeof(ListNode_c));
    p->_val = val;
    p->_next = NULL;
    p->_prev = NULL;
}

//C++中的
//在CPP中，struct已经可以认为是类，和class一样，只是默认的访问限定符不一样。
struct ListNode_CPP{
    int _val;
    struct ListNode_CPP* _next; //兼容C的用法
    ListNode_CPP* _prev;  //C++不需要typedef和struct也可以

    explicit ListNode_CPP(int val = 0)
    :_val(val),
    _next(nullptr),
    _prev(nullptr)
    {}

    ~ListNode_CPP(){
        _val = 0;
        _prev = nullptr;
        _next = nullptr;
    }
};

void TestListNode_c_cpp(){
    ListNode_c* p1 = (ListNode_c*) malloc(sizeof(ListNode_c));
    ListNode_c* p2 = BuyListNode(3);
    free(p1);
    free(p2);
    //CPP
    auto* p3 = new ListNode_CPP;
    delete p3;
}


//   operator new 和 operator delete
class no6A{
public:
    explicit no6A(int a=0)
    :_a(a)
    {
        std::cout << "no6A()" << std::endl;
    }

    ~no6A(){
        std::cout << "~no6A()" << std::endl;
    }

private:
    int _a;
};


void TestNo6A(){
    no6A* p1 = (no6A*) malloc(sizeof(no6A));
    no6A* p2 = (no6A*) operator new(sizeof(no6A));
    // operator new 和 malloc 的区别是什么？
    //其实区别是在于申请失败的情况
    size_t  size = 2;
    void* p3 = malloc(size*1024*1024*1024*1024*1024);
    std::cout << p3 << std::endl;   //申请失败返回0
    free(p3);
    //void * p4 = operator new(size*1024*1024*1024*1024*1024);  //失败抛异常
    //operator delete(p4);

    try {
        void *p4 = operator new(size*1024*1024*1024*1024*1024);
        std::cout << p4 << std::endl;
    }
    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    //结论：他们使用的方式都是一样的，只是处理错误的方式不一样。
}


// malloc : 申请内存，如果内存不够申请失败了，就会返回0，这是面向过程的处理方式。
// operator new ： 内部还是使用malloc申请内存，只不过失败了会抛出异常。
// new ： operator new + 析构函数
// delete 和 free 的区别：调用析构函数




//          为类定制专属的operator new

class no6A2{

public:
    //void* operator new(size_t size) {
        //...
    //}

private:
    int _a;
};



//         定位new/replacement new

void testReplacementNew(){
    no6A* p1 = new no6A;
    delete p1;
    //我们知道new会调用operator new + 析构函数，如果现在想模拟new的行为呢？
    no6A* p2 = (no6A*)operator new(sizeof(no6A));
    new(p2)no6A(10);
}




//     c++模版与泛型编程

//模版->写跟类型无关的代码
//  泛型编程： 编写与类型无关的通用代码，是代码复用的一种手段，模板是泛型编程的基础。


//函数模板

// 1、 template<class T>
template<typename T>
void Swap(T& a,T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

void TestTemplate(){
    int a =11;
    int b =99;
    Swap(a,b);
    std::cout << a  << " "<< b << std::endl;

    double c = 1.11;
    double d = 2.22;
    Swap(c,d);
    std::cout << c << " " << d << std::endl;

    char e = 'a';
    char f = 'b';
    Swap(e,f);
    std::cout << e << " " << f << std::endl;
}

//通过反汇编发现其实他们调用的不是同一个函数，编译器在预处理阶段会根据调用值的类型按照模版生成对应的函数，这个过程叫做模版的实例化。



//   C语言如何实现一个栈

typedef int StackType;

typedef struct Stack_c{
    StackType* _a;
    int size;
    int capacity;
}Stack_c;

void StackInit(Stack_c* ps){
    //...
}

void StackDestroy(Stack_c* ps){
    //...
}

void StackPush(Stack_c* ps,StackType n){
    //...
}
//...


//  那么c++是如何实现一个栈的呢？
template<class T>

class Stack_cpp{
public:

    Stack_cpp() {
        //...
    }
    ~Stack_cpp() {
        //...
    }
    void Stack_cppPush(T n){
        //...
    }

private:
    T* _a;
    int _size;
    int _capacity;
};



void TestStack_c(){
    Stack_c stc;
    //1、容易忘记调用初始化    c++ : 构造函数+析构函数
    //2、没有封装，谁都可以修改数据   c++ : private保护只能在类中修改，或者通过类提供的public方法修改。
    //3、如果想定义两个栈，一个存int，一个存double，就需要再写一个栈。  c++ : 模版
    StackInit(&stc);
    StackPush(&stc,1);
    StackPush(&stc,2);
    StackPush(&stc,3);
    //非法修改
    stc.capacity = 0;
    StackDestroy(&stc);

    Stack_cpp<int> st;
    st.Stack_cppPush(1);
    st.Stack_cppPush(2);

    Stack_cpp<double> stb;
    stb.Stack_cppPush(1.11);
    stb.Stack_cppPush(2.22);
}
