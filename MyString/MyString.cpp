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

size_t string:: npos = -1;

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

std::istream& operator>> (std::istream& in,string& s){
    while(1){
        char ch;
        ch = in.get();
        if (ch=='\n') {
            break;
        }else{
            s+=ch;
        }
    }
    return in;
}

void yaoYuan::string::reserve(size_t n) {
    if (n > _capacity){
        char* tmp = new char[n+1];
        strcpy(tmp,_str);
        delete[] _str;
        _str = tmp;
        _capacity = n;
    }
}


void yaoYuan::string::push_back(const char ch) {
    if (_size == _capacity){
        size_t newCapacity = _capacity==0 ? 2:_capacity*2;
        reserve(newCapacity);
    }
    _str[_size] = ch;
    ++_size;
    _str[_size] = '\0';
}

void yaoYuan::string::append(const char *str) {
    size_t len = strlen(str);
    if(_size+len > _capacity){
        reserve(_size+len);
    }
    strcpy(_str+_size,str);
    _size += len;
}

string& yaoYuan::string::operator+=(const char ch) {
    this->push_back(ch);
    return *this;
}

string& yaoYuan::string::operator+=(const char *str) {
    this->append(str);
    return *this;
}


string& yaoYuan::string::insert(size_t pos, char ch) {
    assert(pos < this->_size);
    if (_size == _capacity){
        size_t newCapacity = _capacity==0? 2:_capacity*2;
        reserve(newCapacity);
    }
    //移动字符
    size_t end = _size;
    while (end >= pos){
        _str[end+1] = _str[end];
        --end;
    }
    _str[pos] = ch;
    ++_size;
    return *this;
}

string& yaoYuan::string::insert(size_t pos, const char *str) {
    assert(pos < this->_size);
    size_t len = strlen(str);
    if (_size+len >= _capacity){
        reserve(_size+len);
    }
    size_t end = _size;
    while (end >= pos){
        _str[end+len] = _str[end];
        end--;
    }
    /*for (size_t i=0;i< len;i++){
        _str[pos] = str[i];
        pos++;
    }*/
    strncpy(_str+pos,str,len);
    _size+=len;
    return *this;
}

void yaoYuan::string::resize(size_t n, char ch) {
    if (n < _size){
        _str[n] = ch;
        _size = n;
    }else{
        if (n > _capacity){
            reserve(n);
        }
        while (_size < n){
            _str[_size] = ch;
            _size++;
        }
        _str[_size] = '\0';
    }
}

string& yaoYuan::string::erase(size_t pos, size_t len) {
    assert(pos<_size);
    if (len == string::npos || pos+len >= _size){
        _str[pos] = '\0';
    }else{
        size_t end = pos+len;
        while (_str[end] != '\0'){
            _str[pos++] = _str[end++];
        }
        _str[pos] = '\0';
    }
    _size = pos;
    return *this;
}

size_t yaoYuan::string::find(char ch,size_t pos) {
    assert(pos<_size);
    size_t i = pos;
    while(_str[i++] != ch){
        if(i>=_size){
            return string::npos;
        }
    }
    return i-1;
}

size_t yaoYuan::string::find(const char *str, size_t pos) {
    char* p = strstr(_str,str);
    if (p== nullptr){
        return string::npos;
    }else{
        return p-_str;
    }
}

bool yaoYuan::string::operator<(const string &s) {
    int ret = strcmp(_str,s._str);
    return ret < 0;
}

bool yaoYuan::string::operator==(const string &s) {
    int ret = strcmp(_str,s._str);
    return ret==0;
}

bool yaoYuan::string::operator!=(const string &s) {
    return !(*this == s);
}

bool yaoYuan::string::operator>(const string &s) {
    return !(*this < s);
}

bool yaoYuan::string::operator<=(const string &s) {
    return (*this < s) || (*this == s);
}

bool yaoYuan::string::operator>=(const string &s) {
    return (*this > s) || (*this == s);
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

void Test_string2() {
    string s1("hello");
    s1.push_back(' ');
    s1.push_back('w');
    s1.push_back('o');
    s1.push_back('r');
    s1.push_back('l');
    s1.push_back('d');

    for (size_t i = 0; i < s1.size(); i++) {
        std::cout << s1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << s1.c_str() << std::endl;

    std::cout << s1.capacity() << " " << s1.size() << std::endl;
    s1.append(" std xxxxxxxxxxxxxxxxxxxxxxxxxx");
    string::iterator it = s1.begin();
    while (it != s1.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    std::cout << s1.capacity() << " " << s1.size() << std::endl;
    std::cout << s1.c_str() << std::endl;

    s1 += ' ';
    s1 += 'h';
    s1 += "ello world";
    for (auto e:s1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    string s2;
    s2 += 'h';
    s2 += "ello";
    for (auto e:s2) {
        std::cout << e;
    }
    std::cout << std::endl;


    string s3("hello");
    s3.insert(1, 'x');
    std::cout << s3 << std::endl;
    s3.insert(1, "aaaaaaaaaaaaaaa");
    std::cout << s3.c_str() << std::endl;
}


void Test_string3(){
    string s1("hello");
    s1.reserve(10);
    std::cout << s1 << std::endl;
    s1.resize(8,'x');
    std::cout << s1 << std::endl;
    s1.resize(18,'a');
    std::cout << s1 << std::endl;
    s1.resize(2);
    std::cout << s1 << std::endl;

    string s2("helloworld");
    s2.erase(5,2);
    std::cout << s2 << std::endl;

    string s3("hello");
    std::cout << s3.find("ll") << std::endl;
}