//
// Created by 姚远 on 2022/11/8.
//

#include "STL_set.h"


void Test_set1(){
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(7);

    set<int>::iterator it = s.begin();
    while (it != s.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    //set其实就是一个平衡搜索树，可以起到排序和去重的作用

    auto pos = s.find(30);
    if (pos != s.end()){
        s.erase(pos);
    }

    for(auto e:s){
        cout << e << " ";
    }
    cout << endl;

}


void Test_set2(){
    map<int,int> m;
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(2,2));
    m.insert(pair<int,int>(3,3));
    m.insert(pair<int,int>(4,4));
    m.insert(pair<int,int>(5,5));   //pair的构造函数，构造了一个匿名对象
    m.insert(make_pair(6,6));   //make_pair是一个模版函数

    map<int,int>::iterator it = m.begin();
    while(it != m.end()){
        cout << it->first << ":" << it->second << " ";
        ++it;
    }
    cout << endl;
}


void Test_map1(){
    std::map<std::string,std::string> dict;
    dict.insert(pair<std::string,std::string>("123","345"));
    dict.insert(make_pair("321","345"));
    std::map<std::string,std::string>::iterator it = dict.begin();
    while (it != dict.end()){
        cout << it->first << ":" << it->second << " ";
        ++it;
    }
    cout << endl;
}


void Test_map2() {
    std::string strArr[] = {"西瓜","苹果","香蕉","石榴","橘子","橙子","西瓜","石榴",
                            "西瓜","西瓜","苹果","苹果","石榴","西瓜","苹果","西瓜"};
    std::map<std::string,int> countMap;
    for(auto& val:strArr){
        auto pos = countMap.find(val);
        if (pos != countMap.end()){
            pos->second++;
        }else{
            countMap.insert(make_pair(val,1));
        }
    }
    auto it = countMap.begin();
    while(it != countMap.end()){
        cout << it->first << ":" << it->second << " ";
        ++it;
    }
    cout << endl;
}


void Test_map3() {
    map<string,int> countMap;
    std::string strArr[] = {"西瓜","苹果","香蕉","石榴","橘子","橙子","西瓜","石榴",
                            "西瓜","西瓜","苹果","苹果","石榴","西瓜","苹果","西瓜"};
    for (auto& e:strArr){
        //1、如果水果不在map中则[]会插入pair<水果，int（）>，在返回其值0++
        //2、如果水果在map中则[]会取到该水果映射的val，并++
        countMap[e]++;
    }
    for(auto& e:countMap){
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;
}

void Test_map4(){
    std::string strArr[] = {"西瓜","苹果","香蕉","石榴","橘子","橙子","西瓜","石榴",
                            "西瓜","西瓜","苹果","苹果","石榴","西瓜","苹果","西瓜"};
    map<string,int> strMap;
    for (auto& e:strArr){
        //insert会返回一个pair，first是对应键值对的迭代器，second是一个bool，insert成功该bool为true，insert失败该bool返回false
        pair<std::map<string,int>::iterator,bool> ret = strMap.insert(make_pair(e,1));
        //如果返回的pair中bool为false，说明这个键已经存在，则++其迭代器中的值
        if(!ret.second){
            ret.first->second++;
        }
    }
    for (auto& e:strMap){
        cout << e.first << ":" << e.second << " ";
    }
    cout << endl;
}

//map中operator[]的实现
//mapped_type& operator[] (const key_type& k){
//    return (*((this->insert(make_pair(k,mapped_type() ) ) ).first)).second;
//}

//  底层调用了insert来实现：pair k是传入的key，mapped_type()是构造了一个默认值，insert插入该pair，
//  如果插入成功返回一个pair first是该键值对的iterator，解应用迭代器取其中的second，就是键对应的值。

//为什么用insert而不用find呢？
//我们知道，一般[]返回的就是映射关系的值，假设使用find，如果key不在map中如何返回呢？
//使用insert的好处就是如果key在map中可以返回他的值，key不再map中也可以返回其值，只不过这个值是这个类型的默认缺省值



//multimap 和 multiset
void Test_multiset1(){
    //multiset 和 set 的区别就是multiset允许值的重复
    // 和 map 的区别是multimap允许key重复，multimap的insert不返回pair，且不支持operator[]因为有多个重复key[]就失去意义了
    multiset<int> ms;
    ms.insert(3);
    ms.insert(2);
    ms.insert(3);
    ms.insert(1);
    ms.insert(4);
    ms.insert(3);

    for (auto& e:ms){
        cout << e << " ";
    }
    cout << endl;

    //find查找到的是第一个3
    multiset<int>::iterator pos = ms.find(3);
    cout << *pos << endl;
    ++pos;
    cout << *pos << endl;
    ++pos;
    cout << *pos << endl;
    ++pos;
    cout << *pos << endl;

}