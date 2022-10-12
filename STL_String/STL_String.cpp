//
// Created by 姚远 on 2022/10/11.
//

#include "STL_String.h"
using namespace std;


//             STL ： string
//  参考文档学习

void TestString(){
    std::string s1;
    std::string s2("hello");
    std::string s3(s2);
    string s4(10,'a');

    //这里是用hello先构造一个string对象再用该临时对象去拷贝构造s5，但是这里会被编译器优化，会直接构造，等价于string s5("hello");
    string s5 = "hello";
    //拷贝构造
    string s6 = s2;


    //这里的<<重载了，所以可以这样输出, >>也重载了
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    cout << s4 << endl;

    //字符串插入
    string s7("12345");
    s7.push_back('6');
    s7.append("78");
    s7 += "9";
    cout << s7 << endl;

    //字符串转成整形
    string s8 ("12345");
    int val = 0;
    for(int i=0 ; i<s8.size();i++){
        val *= 10;
        val += (s8[i]-'0');
    }
    cout << val << endl;
}


//4个默认成员函数
void TestString1(){
    //构造函数:
    //1、无参构造函数
    string s1;
    //2、从C字符串构造
    string s2("yao yuan");
    //3、拷贝构造
    string s3(s2);
    //4、构造子串 :复制str中从字符位置pos开始并跨越len字符的部分
    string s4(s2,4,4);
    cout<< s4 << endl;
    //5、form buffer ：从由s指向的字符数组中复制前n个字符。
    char str[10] = {'a','b','c','d','e','f','g','h','i','\0'};
    string s5(str,5);
    cout<< s5 << endl;
    string s6("YaoYuan",3);
    cout << s6 << endl;
    //6、填充构造：用字符c的n个连续副本填充字符串。
    string s7(8,'f');
    cout << s7 << endl;
    string s8(8,42);   //42的ascii码*
    cout << s8 << endl;
    //以范围的构造函数：以相同的顺序复制范围[第一个，最后一个)中的字符序列。
    string s9(s6.begin(),s6.begin()+3);
    cout << s9 << endl;
}


//遍历
void TestString2(){
    string s1("hello world");
    cout << s1 << endl;
    //string 重载了operator[] 他可以根据下标访问，返回其字符的引用，如果是const的会返回const char&
    //里面的operator[]重载了， 一个是 char& operator[](size_t pos);
    //一个是const char& operator[](size_t pos) const;
    for (size_t i=0;i<s1.size();i++) {
        s1[i] += 1;
    }

    for (size_t i=0;i<s1.size();i++) {
        cout << s1[i] << " " ;
    }
    cout << endl;

    // 迭代器遍历
    string::iterator it = s1.begin();
    while(it != s1.end()){
        *it-=1;
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    //范围for
    //底层原理就是迭代器
    for(auto e : s1){
        cout << e << " ";
    }
    cout << endl;
}


int string2int(const string& s){
    int val = 0;
    string::const_iterator it = s.begin();
    while (it != s.end()){
        val *= 10;
        val += (*it-'0');
        ++it;
    }
    return val;
}

void TestString3(){
    //了解迭代器
    string s1("hello world");
    //倒序遍历
    string::iterator it = s1.end();
    for(auto i=it-1; i>=s1.begin(); i--){
        cout << *i <<" ";
    }
    //反向迭代器
    string::reverse_iterator rit = s1.rbegin();
    while (rit != s1.rend()){
        cout << *rit << " ";
        rit++;
    }
    cout << endl;

    string s2("12345");
    int val = string2int(s2);
    cout << val << endl;
}

void TestString4(){
    string s1("hello world");
    string s2("hello");
    cout << s1.size() << endl;
    cout << s2.size() << endl;
    cout << s1.length() << endl;
    cout << s2.length() << endl;
    cout << s1.max_size() << endl;
    cout << s2.max_size() << endl;
    cout << s1.capacity() << endl;
    cout << s2.capacity() << endl;
    s1 += "111111111111";
    cout << s1 << endl;
    cout << s1.capacity() << endl;  //我们发现s1的容量从22增加到了47
    s1.clear();     //清除s1的数据
    cout << s1 << endl;
    cout << s1.capacity() << endl;  //s1的数据清除了，但是他的容量没有减少

    //reserve 增容，void reserve (size_t n = 0); 指定增容到n个字节大小。
    s1.reserve(100);
}

void TestString5(){
    string s1("hello world");
    //reserve 增容，void reserve (size_t n = 0); 指定增容到n个字节大小。
    s1.reserve(100);
    //resize  调整字符串 ,将字符串的长度调整为n个字符。
    //如果n小于当前字符串长度，则将当前值缩短为第n个字符，删除第n个字符以外的字符。
    //如果n大于当前字符串长度，则通过在末尾插入所需的字符来扩展当前内容，以达到n的大小。如果指定了c，则将新元素初始化为c的副本，否则，它们是值初始化的字符(空字符)。
    string s;
    s.resize(20,'a');
    cout << s << endl;
}


void TestString6() {
    //插入
    string s1;
    //插入单个字符
    s1.push_back('h');
    cout << s1 << endl;
    //插入多个字符
    s1.append("ello");
    cout << s1 << endl;

    s1 += " world";
    cout << s1 << endl;
    //头插
    auto it = s1.insert(s1.begin(), 'Y');
    cout << s1 << endl;
    cout << *it << endl;

    s1.insert(1, "ao");
    cout << s1 << endl;
    //删除
    s1.erase(8,1);
    cout << s1 << endl;

}