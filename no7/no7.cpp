//
// Created by 姚远 on 2022/10/10.
//

#include "no7.h"


template<class T>
class vector{
public:
    vector()
    :_a(nullptr),
    _size(0),
    _capacity(0)
    {}

    ~vector(){
        delete []_a;
        _a = nullptr;
        _size = _capacity = 0;
    }

    void push_back(const T& x);

    T operator[](size_t i){
        assert(i < _size);
        return _a[i];
    }

    size_t size(){
        return _size;
    }


private:
    T* _a;
    size_t _size;
    size_t _capacity;
};

//如果声明在.h，定义在.cpp中的话，需要说明他的模版，函数名也要写上所属的类
template<class T>
void vector<T>::push_back(const T& x){
    //增容
    if (_size == _capacity){
        size_t newCapacity = _capacity == 0 ? 2:_capacity*2;

        T* tmp = new T[newCapacity];

        if (_a){
            memcpy(tmp, _a, _size * sizeof(T));
            delete []_a;
            _a = tmp;
        }
        _capacity = newCapacity;
    }

    _a[_size] = x;
    _size++;
}
