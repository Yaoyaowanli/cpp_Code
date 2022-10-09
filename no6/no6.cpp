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
