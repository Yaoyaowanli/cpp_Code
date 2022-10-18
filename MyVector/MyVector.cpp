//
// Created by 姚远 on 2022/10/18.
//

#include "MyVector.h"

using namespace yaoYuan;

template<class T>T* yaoYuan::vector<T>::begin() {
    return _start;
}

template<class T>T* yaoYuan::vector<T>::end() {
    return _finish;
}

template <class T>void yaoYuan::vector<T>::reserve(size_t n) {
    if (n > capacity()){
        size_t size = this->size();
        T* tmp = new T[n];
        if(_start){
            memcpy(tmp,_start, sizeof(T)*size);
            delete[] _start;
        }
        _start = tmp;
        _finish = tmp+size;
        _end_of_storage = tmp+n;
    }
}

template <class T>void yaoYuan::vector<T>::push_back(const T& x){
    if(_finish == _end_of_storage){
        size_t newCapacity = capacity()==0 ? 2:capacity()*2;
        reserve(newCapacity);
    }

    *_finish = x;
    ++_finish;
}

template <class T>size_t yaoYuan::vector<T>::size(){
    return _finish - _start;
}

template<class T>size_t yaoYuan::vector<T>::capacity() {
    return _end_of_storage - _start;
}



void test_my_vector1(){
    yaoYuan::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);

    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;


    auto it = v.begin();
    while (it != v.end()){
        std::cout<< *it << " ";
        it++;
    }
    std::cout << std::endl;
}