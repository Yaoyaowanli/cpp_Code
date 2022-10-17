//
// Created by 姚远 on 2022/10/17.
//

#ifndef CPP_CODE_STRING_COPY_H
#define CPP_CODE_STRING_COPY_H

#endif //CPP_CODE_STRING_COPY_H

//C++ 的一个常见面试题是让你实现一个 String 类，限于时间，不可能要求具备 std::string 的功能，但至少要求能正确管理资源。
#include <iostream>
namespace string_copy {
    class string{
    public:
        //构造
        explicit string(const char* str="")
                :_str(new char[strlen(str)+1])
        {
            strcpy(_str,str);
        }

        //析构
        ~string(){
            delete[] _str;
            _str = nullptr;
        }

        //深拷贝，传统写法:
        //拷贝构造
       /* string(const string& s)
        :_str(new char[strlen(s._str)+1])
        {
            strcpy(_str,s._str);
        }*/
        //深拷贝，现代写法
        string(const string& s)
        :_str(nullptr)
        {
            string tmp(s._str);
            std::swap(_str,tmp._str);
        }

        //传统写法
        //赋值重载
       /* string& operator= (const string& s){
            if(this != &s){
                char* tmp = new char[strlen(s._str)+1];
                strcpy(tmp,s._str);
                delete[] _str;
                _str = tmp;
            }
            return *this;
        }*/
       //现代写法
       //赋值重载
      /* string& operator= (const string& s){
           if (this != &s){
               string tmp(s);
               std::swap(_str,tmp._str);
           }
           return *this;
       }*/

      //                注意这里，是传值，传参时s本就是拷贝的，所以函数里只用替换_str就行，函数结束时这个参数会自动析构。
      string& operator= (string s){
          std::swap(_str,s._str);
          return *this;
      }


        size_t size(){
            return strlen(_str);
        }

        char& operator[] (size_t i){
            return _str[i];
        }





    private:
        char* _str;
    };
}