//
// Created by 姚远 on 2022/10/15.
//

#include "MyString.h"
/*
using namespace yaoYuan;

//构造
yaoYuan::string::string(const char *str)
:_str( new char[strlen(str)+1] )    //+1是为了给'\0'留位置，因为strlen不会计算\0的那一位
{
    //strCpy会拷贝\0
    strcpy(_str,str);
}
//析构
yaoYuan::string::~string() {
    delete[]_str;
    _str = nullptr;
}
//拷贝构造
yaoYuan::string::string(const string &str)
:_str(new char[strlen(str._str)+1])     //深拷贝，要重新开空间拷贝原字符串
{
    strcpy(_str,str._str);
}

char& yaoYuan::string::operator[](size_t i){
    return _str[i];
}

//赋值重载
string& yaoYuan::string::operator=(const string& str) {
    if (&str != this){
        char* newStr = new char[strlen(str._str)+1];
        strcpy(newStr,str._str);
        delete[] this->_str;
        this->_str = newStr;
        return *this;
    }
}

size_t yaoYuan::string::size(){
    return strlen(_str);
}

const char* yaoYuan::string::c_str() {
    return _str;
}





void test_string2(){
    string s1("hello");
    string s2(s1);
    std::cout << s1.c_str() << std::endl;
    std::cout << s2.c_str() << std::endl;

    string s3("world");
    s1 = s3;
    std:: cout << s1.c_str() << std::endl;
    std::cout << s3.c_str() << std::endl;
}


void test_string1(){
    string s1("hello");
    string s2;

    for(size_t i =0; i<s1.size();i++){
        std::cout << (s1[i]+=1) << " ";
    }
    std::cout << std::endl;

    for(int i=0; i<s2.size(); i++){
        std::cout<< s2[i] << " ";
    }
    std::cout << std::endl;
}*/

using namespace yaoYuan;

string::iterator yaoYuan::string::begin(){
    return _str;
}

string::iterator yaoYuan::string::end(){
    return _str+_size;
}

yaoYuan::string::string(const char *str)
{
    _size = strlen(str);
    _capacity = _size;
    _str = new char[_capacity+1];
    strcpy(_str,str);   //这里的strcpy会把str最后的\0拷贝过去。
}

yaoYuan::string::~string() {
    delete[] _str;
    _str = nullptr;
    _capacity = _size = 0;
}

yaoYuan::string::string(const string& s){
    _size = s._size;
    _capacity = s._capacity;
    _str = new char[strlen(s._str)+1];
    strcpy(_str,s._str);
}

string& yaoYuan::string::operator=(const string &s) {
    if (&s != this){
        this->_size = s._size;
        char* tmp = new char[strlen(s._str)+1];
        strcpy(tmp,s._str);
        delete this->_str;
        this->_str = tmp;
    }
    return *this;
}

size_t yaoYuan::string::size() const{
    return _size;
}

size_t yaoYuan::string::capacity() const {
    return _capacity;
}

char& yaoYuan::string::operator[](size_t i) {
    assert(i<_size);
    return _str[i];
}

const char& yaoYuan::string::operator[](size_t i) const {
    assert(i<_size);
    return _str[i];
}

const char* yaoYuan::string::c_str()const{
    return _str;
}


std::ostream& operator<< (std::ostream& out,const string& s){
    out << "capacity: " << s.capacity() << std::endl;
    out << "size: " << s.size() << std::endl;
    for (size_t i=0;i<s.size();i++){
        out << s[i] << " ";
    }
    out << std::endl;
    return out;
}

std::istream operator>> (std::istream& in,string& s){

}


void Test_string1(){
    string s1;
    string s2("hello");

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    //三种遍历方式
    for (size_t i=0; i<s2.size(); i++){
        s2[i]+=1;
        std::cout << s2[i] << " ";
    }
    std:: cout << std::endl;

    string::iterator it = s2.begin();
    while (it != s2.end()){
        *it-=1;
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    //其实范围for是由迭代器支持的，也就是说最终这段代码会被编译器替换成迭代器
    //只要一个类支持iterator，支持begin，end函数，就可以使用范围for
    for (auto e:s2){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}


