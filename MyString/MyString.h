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



    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };
}


void Test_string1();