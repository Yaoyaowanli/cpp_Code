//
// Created by 姚远 on 2022/10/18.
//

#include "MyVector.h"

using namespace yaoYuan;

template<class T>yaoYuan::vector<T>::vector(const vector<T> &v) {
    _start = new T[v.capacity()];
    _finish = _start;
    _end_of_storage = _start+v.capacity();
    for (size_t i=0; i<v.size();i++){
        *_finish = v[i];
        ++_finish;
    }
}

/*template<class T>vector<T>& yaoYuan::vector<T>::operator=(const vector<T> &v) {
    if (this != &v){
        delete[] _start;
        _start = new T[v.capacity()];
        memcpy(_start,v._start, sizeof(T)*v.size());
    }
    return *this;
}*/

template<class T> void yaoYuan::vector<T>::swap(vector<T> &v) {
    std::swap(_start,v._start);
    std::swap(_finish,v._finish);
    std::swap(_end_of_storage,v._end_of_storage);
}

//operator赋值                                        //这里直接传值，v就是拷贝构造出来的，我们写的拷贝构造是深拷贝，所以这里也是深拷贝
template<class T>vector<T>& yaoYuan::vector<T>::operator=(vector<T> v) {
    //直接交换this和v，除作用域v会自动析构，就会将this的空间析构
    this->swap(v);
    return *this;
}

template<class T>yaoYuan::vector<T>::~vector<T>() {
    delete[] _start;
    _start = _finish = _end_of_storage = nullptr;
}

template<class T>T* yaoYuan::vector<T>::begin() {
    return _start;
}

template<class T>const T* yaoYuan::vector<T>::begin() const {
    return _start;
}

template<class T>T* yaoYuan::vector<T>::end() {
    return _finish;
}

template<class T>const T* yaoYuan::vector<T>::end() const {
    return _finish;
}

template <class T>void yaoYuan::vector<T>::reserve(size_t n) {
    if (n > capacity()){
        size_t size = this->size();
        T* tmp = new T[n];
        if(_start){
            //memcpy(tmp,_start, sizeof(T)*size);
            for(size_t i=0;i<size;i++){
                tmp[i] = _start[i];     //这里如果T是自定义对象的话，调用的是对象的operator=
            }
            delete[] _start;
        }
        _start = tmp;
        _finish = tmp+size;
        _end_of_storage = tmp+n;
    }
}

template <class T>void yaoYuan::vector<T>::push_back(const T& x){
   /* if(_finish == _end_of_storage){
        size_t newCapacity = capacity()==0 ? 2:capacity()*2;
        reserve(newCapacity);
    }
    *_finish = x;
    ++_finish;*/
    insert(_finish,x);
}

template <class T>size_t yaoYuan::vector<T>::size(){
    return _finish - _start;
}

template<class T>size_t yaoYuan::vector<T>::capacity() {
    return _end_of_storage - _start;
}

template <class T>size_t yaoYuan::vector<T>::size()const{
    return _finish - _start;
}

template<class T>size_t yaoYuan::vector<T>::capacity()const {
    return _end_of_storage - _start;
}

template<class T>T& yaoYuan::vector<T>::operator[](size_t i) {
    assert(i < size());
    return _start[i];
}

template<class T>const T& yaoYuan::vector<T>::operator[](size_t i)const {
    assert(i < size());
    return _start[i];
}

template<class T>void yaoYuan::vector<T>::print_vector(const vector<T>& v) {
    auto it = v.begin();
    while (it != v.end()){
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    /*for (const auto& e:v){
        std::cout << e << " ";
    }
    std::cout << std::endl;*/
}

template<class T>void yaoYuan::vector<T>::pop_back() {
    /*assert(_start < _finish);
    _finish--;*/
    erase(_finish-1);
}

template<class T>void yaoYuan::vector<T>::insert(iterator pos, const T &x) {
    assert(pos <= _finish);
    //先检查容量
    if(_finish == _end_of_storage){
        //这里如果记录pos的偏移量，因为如果扩容了数据空间就不一样了，会发生迭代器失效。
        size_t n = pos-_start;
        size_t newCapacity = capacity()==0 ? 2:capacity()*2;
        reserve(newCapacity);
        //重新计算pos的位置
        pos = _start+n;
    }
    //挪动数据
    iterator end = _finish;
    while (end != pos){
        *end = *(end-1);
        --end;
    }
    *pos = x;
    ++_finish;
}

template<class T> T* yaoYuan::vector<T>::erase(iterator pos) {
    assert(pos < _finish);
    auto end = pos + 1;
    while (end != _finish) {
        *(end - 1) = *end;
        ++end;
    }
    --_finish;
    return pos;
}

template<class T>void yaoYuan::vector<T>::resize(size_t n, const T &val) {
    if (n > size()){
        if(n>capacity()){
            reserve(n);
            while (_finish != _end_of_storage){
                *_finish = val;
                _finish++;
            }
            return;
        }
        for(size_t i = size(); i<n;i++){
            _start[i] = val;
        }
        _finish = _start+n;
    }else{
        _finish = _start+n;
    }
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


    /*int arr[5] = {1,2,3,4,5};
    std::cout << *v.end()<< std::endl;*/

    for (size_t i=0; i<v.size();i++){
        std::cout << v[i] << std::endl;
    }

    for (auto& e:v) {
        e+=1;
        std::cout << e << " ";
    }
    std::cout << std::endl;

    for(size_t i=0;i<v.size();i++){
        std::cout<< v[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "print_vector : " << std::endl;
    v.print_vector(v);
}

void test_my_vector2() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    /*v.print_vector(v);
    v.pop_back();
    v.print_vector(v);
    v.insert(v.end(),5);
    v.print_vector(v);
    v.insert(v.begin(),0);
    v.print_vector(v);
    v.insert(v.begin()+3,99);*/
    v.print_vector(v);

    auto it = v.begin();
    while (it != v.end()){
        if (*it % 2 ==0 && *it != 0){
            it = v.erase(it);
        }else{
            ++it;
        }
    }
    v.print_vector(v);
}

void test_my_vector3() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.resize(10,0);
    v1.print_vector(v1);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    v2.reserve(20);
    std::cout<< "v2.capacity: "<< v2.capacity() <<std::endl;
    v2.resize(15,0);
    v2.print_vector(v2);

    vector<int>v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(5);
    v3.push_back(6);
    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    v3.push_back(10);
    std::cout << "v3.capacity: " << v3.capacity() << std::endl;
    v3.resize(5,0);
    std::cout<<"v3:"<<std::endl;
    v3.print_vector(v3);
    std::cout << "v3.size:" << v3.size() << "    v3.capacity:" << v3.capacity() << std::endl;
    v3.push_back(6);
    v3.push_back(6);
    v3.push_back(6);
    v3.push_back(6);
    v3.push_back(6);
    v3.push_back(6);
    v3.push_back(6);
    v3.push_back(6);
    v3.push_back(6);
    v3.push_back(6);
    v3.push_back(6);
    v3.resize(16,0);
    v3.print_vector(v3);
    std::cout << "v3.size:" << v3.size() << "    v3.capacity:" << v3.capacity() << std::endl;

    v3.resize(5,0);
    v3.print_vector(v3);
}

void test_my_vector4() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for(size_t i=0;i<v.size();i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    vector<int> v2(v);
    for(size_t i=0;i<v2.size();i++){
        std::cout << v2[i] << " ";
    }

    vector<int> v3;
    v3=v;
    v3.print_vector(v3);
}

void test_my_vector5(){
    //memcpy 在vector中的问题
    vector<std::string> v;
    v.push_back("111111111111111111111111111111111111");
    v.push_back("222222222222222222222222222222222222");
    //在插入就会报错，为什么？
    //因为我们这里会发生增容，而我们的reserve 内部是用memcpy拷贝的原对象地址，下一句delete原对象就会让自定义类型触发析构函数
    //所以元素string就会析构释放空间，而我们扩容后的对象是拷贝的原地址，这块空间以及被析构了，所以会出错
    //v.push_back("333333333333333333333333333333333333");
    //v.push_back("444444444444444444444444444444444444");

    for (auto e:v){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}