//
// Created by 姚远 on 2022/10/15.
//


#ifndef CPP_CODE_MYSTRING_H
#define CPP_CODE_MYSTRING_H

#endif //CPP_CODE_MYSTRING_H

#include <iostream>

/*
namespace yaoYuan{
    class string{
    public:
        //构造
        explicit string(const char* str = "");
        //析构
        ~string();

        string(const string& str);

        size_t size();

        const char* c_str();

        char& operator[](size_t i);
        string& operator= (const string& str);

    private:
        char* _str;
    };
}


void test_string1();
void test_string2();
*/


namespace yaoYuan{
    class string{
    public:
        //vector的迭代器就是指针的重新包装
        typedef char* iterator;

        iterator begin();

        iterator end();

        explicit string(const char* str="");

        ~string();

        string(const string& s);

        string& operator= (const string& s);

        size_t size() const;

        size_t capacity()const;

        char& operator[](size_t i);

        const char& operator[](size_t i)const;

        const char* c_str()const;

        void reserve(size_t n);

        void push_back(char ch);

        void append(const char* str);

        string& operator+= (char ch);

        string& operator+= (const char* str);

        string& insert(size_t pos,char ch);

        string& insert(size_t pos,const char* str);

        void resize(size_t n,char ch='\0');

        string& erase(size_t pos,size_t len=npos);

        size_t find(char ch,size_t pos = 0);

        size_t find(const char* str,size_t pos = 0);

        bool operator< (const string& s);

        bool operator== (const string& s);
        bool operator!= (const string& s);
        bool operator<= (const string& s);
        bool operator> (const string& s);
        bool operator>= (const string& s);

    private:
        char* _str;
        size_t _size;
        size_t _capacity;

        static size_t npos;
    };
}



void Test_string1();
void Test_string2();
void Test_string3();