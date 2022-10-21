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
template<class T,class Ref,class Ptr>
Ref yao::__list_iterator<T,Ref,Ptr>::operator*() {
    //对迭代器解引用的期望就是获得其节点存储的数据，我们只需要将其返回
    return _node->_data;
}

template<class T,class Ref,class Ptr>
yao::__list_iterator<T,Ref,Ptr>& yao::__list_iterator<T,Ref,Ptr>::operator++() {
    _node = _node->_next;
    return *this;
}

template<class T,class Ref,class Ptr>
yao::__list_iterator<T,Ref,Ptr> yao::__list_iterator<T,Ref,Ptr>::operator++(int) {
    Self tmp(*this);
    ++(*this);
    return tmp;
}

template<class T,class Ref,class Ptr>
yao::__list_iterator<T,Ref,Ptr>& yao::__list_iterator<T,Ref,Ptr>::operator--() {
    _node=_node->_prev;
    return * this;
}

template<class T,class Ref,class Ptr>
yao::__list_iterator<T,Ref,Ptr> yao::__list_iterator<T,Ref,Ptr>::operator--(int) {
    Self tmp(*this);
    --(*this);
    return tmp;
}

template<class T,class Ref,class Ptr>
bool yao::__list_iterator<T,Ref,Ptr>::operator!=(const __list_iterator<T,Ref,Ptr> &it) {
    return _node!=it._node;
}

template<class T,class Ref,class Ptr>
bool yao::__list_iterator<T,Ref,Ptr>::operator==(const __list_iterator<T,Ref,Ptr> &it) {
    return _node == it._node;
}

template<class T,class Ref,class Ptr>
Ptr yao::__list_iterator<T,Ref,Ptr>::operator->() {
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
yao::list<T>::list(const list<T>& l){
    _head = new Node;
    _head->_next = _head;
    _head->_prev = _head;
    //1、
    /*const_iterator it = l.begin();
    while (it != l.end()){
        push_back(*it++);
    }*/
    //2、
    for (auto e:l){
        push_back(e);
    }
}

template<class T>
yao::list<T>& yao::list<T>::operator=(list<T> l) {
    if (this != &l){
        std::swap(_head,l._head);
    }
    return *this;
}

template<class T>
void yao::list<T>::swap(list<T> &l1, list<T> &l2) {
    std::swap(l1,l2);
}

template<class T>
yao::list<T>::~list() {
    clear();
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
    /*Node* tail = _head->_prev;
    Node* newNode = new Node(x);
    //链接
    tail->_next = newNode;
    newNode->_prev = tail;
    newNode->_next = _head;
    _head->_prev = newNode;*/

    insert(end(),x);
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

template<class T>
typename yao::list<T>::const_iterator yao::list<T>::begin() const{
    return const_iterator(_head->_next);
}

template<class T>
typename yao::list<T>::const_iterator yao::list<T>::end() const{
    return const_iterator(_head);
}

template<class T>
void yao::list<T>::insert(iterator pos, const T &x) {
    Node *cur = pos._node;
    Node *prev = pos._node->_prev;
    Node* newNode = new Node(x);

    prev->_next = newNode;
    newNode->_next = cur;
    newNode->_prev = prev;
    cur->_prev = newNode;
}

template<class T>
void yao::list<T>::push_front(const T &x) {
    insert(begin(),x);
}

template<class T>
void yao::list<T>::erase(iterator pos) {
    assert(pos != iterator(_head));
    Node* next = pos._node->_next;
    Node* prev = pos._node->_prev;
    prev->_next = next;
    next->_prev = prev;
    delete pos._node;
}

template<class T>
void yao::list<T>::pop_back() {
    //erase(iterator(_head->_prev));
    erase(--end());
}

template<class T>
void yao::list<T>::pop_front() {
    erase(begin());
}






void print_list(const yao::list<int>& lt){
    yao::list<int>::const_iterator it = lt.begin();
    while (it != lt.end()){
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void test_my_list1(){
    yao::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    //l.pop_back();
    //l.pop_front();
   /* auto it = l.begin();
    while(*it != 3){
        ++it;
    }
    std::cout << "delete: " << *it << std::endl;
    l.erase(it);*/

    l.clear();
    l.push_back(5);
    l.push_back(4);
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);


    print_list(l);
}

void test_my_list2(){
    yao::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);


    yao::list<int> l2(l);
    print_list(l);
    print_list(l2);

    l2.push_back(6);
    l2.push_back(7);
    l2.push_back(8);
    yao::list<int> l3;
    l3.push_back(11);
    l3.push_back(22);
    l3.push_back(33);
    l3.push_back(44);
    l3.push_back(55);

    l2 = l3;
    print_list(l2);
    print_list(l3);

}
