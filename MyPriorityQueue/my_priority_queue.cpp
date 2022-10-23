//
// Created by 姚远 on 2022/10/23.
//

#include "my_priority_queue.h"


template <class T,class Container,class Compare>
size_t yao::priority_queue<T,Container,Compare>::size() {
    return _con.size();
}

template<class T,class Container,class Compare>
bool yao::priority_queue<T,Container,Compare>::empty() {
    return _con.empty();
}

template<class T,class Container,class Compare>
void yao::priority_queue<T,Container,Compare>::push(const T &x) {
    _con.push_back(x);
    AdjustUp(_con.size()-1);
}

template<class T,class Container,class Compare>
void yao::priority_queue<T,Container,Compare>::AdjustUp(size_t child) {
    Compare com;
    int parent = int(child-1)/2;
    while (child > 0){
        //if (_con[parent] < _con[child]){
        if (com(_con[parent],_con[child])){
            std::swap(_con[parent],_con[child]);
            child = parent;
            parent = int(child-1)/2;
        }else{
            break;
        }
    }
}

template<class T,class Container,class Compare>
void yao::priority_queue<T,Container,Compare>::pop() {
    std::swap(_con[0],_con[_con.size()-1]);
    _con.pop_back();
    AdjustDown();
}

template<class T,class Container,class Compare>
void yao::priority_queue<T,Container,Compare>::AdjustDown(int root) {
    Compare com;
    int parent = root;
    int child = parent*2+1;

    while (child < _con.size()){
        //if (child+1 < _con.size() && _con[child] < _con[child+1]){
        if (child+1 < _con.size() && com(_con[child],_con[child+1])){
            ++child;
        }
            //if (_con[parent] < _con[child]){
        if (com(_con[parent],_con[child])){
            std::swap(_con[parent],_con[child]);
            parent = child;
            child = parent*2+1;
        }else{
            break;
        }
    }
}

template<class T,class Container,class Compare>
T& yao::priority_queue<T,Container,Compare>::top() {
    return _con[0];
}








void test_my_priority_queue1(){
    //yao::priority_queue<int> pq ;
    yao::priority_queue<int,std::vector<int>,yao::greater<int>> pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(19);
    pq.push(22);
    pq.push(1);
    pq.push(6);
    pq.push(75);

    while (! pq.empty()){
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
}