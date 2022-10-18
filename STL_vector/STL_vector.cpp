//
// Created by 姚远 on 2022/10/17.
//

#include "STL_vector.h"

void test_vector1(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    vector<int>v2(v1);
    for(size_t i=0; i<v2.size(); i++){
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    vector<int>v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(40);
    v3.push_back(50);
    v1 = v3;
    for(auto e: v1){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_vector2(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    //遍历修改
    for(size_t i=0; i<v1.size(); i++){
        v1[i] += 1;
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    //迭代器
    vector<int>::iterator it = v1.begin();
    while(it != v1.end()){
        *it -= 1;
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    //范围for
    for (auto e:v1){
        std::cout << e << " ";
    }
    std::cout << std::endl;

}

//三种类型的迭代器

//const_iterator迭代器:不能解引用修改
void Print_vector(const vector<int>& vt){
    vector<int>::const_iterator it = vt.begin();
    while(it != vt.end()){
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

void test_vector3(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    //1、普通的正向迭代器  可读、可写
    vector<int>::iterator it = v.begin();
    while(it != v.end()){
        *it -= 1;
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    Print_vector(v);

    //反向迭代器
    vector<int>::reverse_iterator rit = v.rbegin();
    while (rit != v.rend()){
        std::cout << *rit << " ";
        rit++;
    }
    std::cout << std::endl;
}

void test_vector4(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    //我的编译器每次增2倍
    //vector的自动增容，有的编译器增2倍，有的增1。5倍，各有优劣，主要在于效率和空间的问题，
    //增2倍可能浪费的空间更多，但是他扩容的次数少，带来的效率高
    //增1。5倍可能浪费的空间少，但是他扩容的次数多，带来的效率低
    //为了解决这种问题vector还提供了reserve接口，可以扩容到指定大小。
    //resize接口可以扩容至指定大小，并且改变size并初始化其内容
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
}

void test_vector5(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //insert 需要给迭代器，和val
    v.insert(v.begin(),0);
    for (auto e:v){
        std::cout << e << " ";
    }
    std::cout << std::endl;
    //erase同理
    v.erase(v.begin());
    for(auto e:v){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_vector6() {
    vector<int> v;
    v.push_back(23);
    v.push_back(533);
    v.push_back(63);
    v.push_back(8);
    v.push_back(64);
    v.push_back(123);
    v.push_back(255);
    //假设现在不知道vector中8的位置，要删除他
    //这时候就需要用到算法库中的find
    //我们只要给find一个迭代器区间，一个目标值，他就会返回找到的迭代器。
    vector<int>::iterator pos = find(v.begin(),v.end(),8);
    if (pos != v.end()){
        v.erase(pos);
    }
    for (auto e:v){
        std::cout << e << " ";
    }
    std::cout << std::endl;


    int a = 3;
    int b = 5;
    int c = a^b;
    int lowBit = c & (-c);
    std::cout << lowBit << std::endl;
}

void test_vector7() {
    //迭代器失效
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it = v.begin();

    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    //迭代器失效
//    v.push_back(9);  为什么插入9就会崩溃？
//因为这里一开始pushback了5个数据此时他的容量是8，我们定义了iterator是指向begin的
//当我们插入9时vector会触发扩容，所以vector的空间变了，然而我们的iterator仍然指向扩容前的空间，所以发生了越界访问。
//一些可能会扩容的操作都可能会导致迭代器失效

    while(it != v.end()){
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void test_vector8() {
    //迭代器失效
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    //要求删除容器中的所有偶数
    auto it = v.begin();
    while(it != v.end()){
        if ((*it)%2 == 0){
            //v.erase(it);    //erase会造成错误
            it = v.erase(it);
        }
        ++it;   //这里会出现错误，因为上面如果删除了，erase就会把元素删除，然后将后面的元素向前移动，就会造成少检查一个元素，导致结果错误
        //如果最后一个原素是要删除的元素的话会导致end前移，然后++it会导致越界
    }

    for(auto e:v){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}