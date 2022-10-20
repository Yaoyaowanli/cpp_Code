//
// Created by 姚远 on 2022/10/20.
//

#include "myList.h"



//list_node
template<class T>
yao::__list_node<T>::__list_node(const T &x)
:_data(x),
_next(nullptr),
_prev(nullptr)
{}

//迭代器
//为了让list迭代器能够像原生指针一样使用，我们需要对运算符进行重载，规定迭代器在使用运算符的工作方式
template<class T>
T& yao::__list_iterator<T>::operator*() {
    //对迭代器解引用的期望就是获得其节点存储的数据，我们只需要将其返回
    return _node->_data;
}

template<class T>
yao::__list_iterator<T>& yao::__list_iterator<T>::operator++() {
    _node = _node->_next;
    return *this;
}

template<class T>
yao::__list_iterator<T> yao::__list_iterator<T>::operator++(int) {
    __list_node<T> tmp(*this);
    ++(*this);
    return tmp;
}

template<class T>
yao::__list_iterator<T>& yao::__list_iterator<T>::operator--() {
    _node=_node->_prev;
    return * this;
}

template<class T>
yao::__list_iterator<T> yao::__list_iterator<T>::operator--(int) {
    __list_node<T> tmp(*this);
    --(*this);
    return tmp;
}

template<class T>
bool yao::__list_iterator<T>::operator!=(const __list_iterator<T> &it) {
    return _node!=it._node;
}

template<class T>
bool yao::__list_iterator<T>::operator==(const __list_iterator<T> &it) {
    return _node == it._node;
}

template<class T>
T* yao::__list_iterator<T>::operator->() {
    return &_node->_data;
}


//list
template <class T>
yao::list<T>::list() {
    _head = new Node;       //stl源码中这里是去内存池中get_node()，我们直接new
    _head->_next = _head;
    _head->_prev = _head;
}

template<class T>
yao::list<T>::~list() {
    erase();
    delete _head;
    _head = nullptr;
}

template<class T>
void yao::list<T>::clear() {
    iterator it = begin();
    while(it != end()){
        erase(it++);
    }
}


template<class T>
void yao::list<T>::push_back(const T &x) {
    Node* tail = _head->_prev;
    Node* newNode = new Node(x);
    //链接
    tail->_next = newNode;
    newNode->_prev = tail;
    newNode->_next = _head;
    _head->_prev = newNode;
}

template<class T>
typename yao::list<T>::iterator yao::list<T>::begin() {
    //带头链表头是不存储数据的，所以头->next才是数据的第一个节点
    return iterator(_head->_next);
}

template<class T>
typename yao::list<T>::iterator yao::list<T>::end() {
    return iterator(_head);
}




void test_my_list1(){
    yao::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    yao::__list_iterator<int> it = l.begin();
    while (it != l.end()){
        std::cout << *it << " -> ";
        ++it;
    }
    std::cout << std::endl;
}