//
// Created by 姚远 on 2022/10/26.
//

#ifndef CPP_CODE_TEST_EFFECTIVECPP_1_H
#define CPP_CODE_TEST_EFFECTIVECPP_1_H

#endif //CPP_CODE_TEST_EFFECTIVECPP_1_H


#include <iostream>

//1、定义一个char* 字符串 常量指针。
const char* const authorName = "yaoYuan";
const std::string authorName2("yaoYuan");

//class专属常量
// 定义一个只有类才能使用访问的常量

class GamePlayer{
public: //有时候我们会#define定义定长数组的长度，c++中更推荐将其定义为class专属常量，即让NumTurns在private中。
    static const int NumTurns = 5;  //常量声明
    int scores[NumTurns];
};






void test_GamePlayer();