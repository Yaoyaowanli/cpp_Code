//
// Created by 姚远 on 2022/10/26.
//

#include <vector>
#include "test_effectivecpp_1.h"


//如果要取其地址，就需要定义,由于声明时候已经给了值，这里就不用给值。
const int GamePlayer::NumTurns;
enum {a3 = 20};
const int a1 = 10;

inline void print_something(){
    //numTurns 是GamePer类中的常量，我们只声明了他，并未定义任何实体，却还是可以使用这个常量（不能对其取地址，会报链接错误）
    int x = GamePlayer::NumTurns;
    std::cout << x << std::endl;
    std::cout << "&GamePlayer::NumTurns: " << &GamePlayer::NumTurns << std::endl;
    std::cout << "变量：" << &x << std::endl;
    std::cout << "常量字符串&authorName ：" << &authorName << std::endl;
    std::cout << "常量string &authorName2 ：" << &authorName2 << std::endl;
    std::cout << "常量int  &a1 ：" << &a1 << std::endl;
    std::cout << "enum常量  a3 ：" << a3 << std::endl;
}

void test_GamePlayer(){
    print_something();
}

//对于单纯常量，最好以const对象或者enums 替换#define
//对于形似函数的宏，最好改用inline替换#define。



//const
void test_const(){
    //const在*左边，修饰的是数据
    //const在*右边，修饰的是指针
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    const int* pi = &v[0];
    //*pi = 10; 错误，const在*左边，修饰的是数据，故*pi只能读不能改
    int* const pi2 = &v[1];
    *pi2 = 99;
    //pi2++;    错误，const在*右边，修饰的是指针

}