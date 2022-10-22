//
// Created by 姚远 on 2022/10/22.
//

#include "my_queue.h"

template<class T,class Container>
void yao::queue<T,Container>::push(const T &x) {
    _con.push_back(x);
}

template<class T,class Container>
void yao::queue<T,Container>::pop() {
    _con.pop_front();
}

template<class T,class Container>
T& yao::queue<T,Container>::front() {
    return _con.front();
}

template<class T,class Container>
size_t yao::queue<T,Container>::size() {
    return _con.size();
}

template<class T,class Container>
bool yao::queue<T,Container>::empty() {
    return _con.empty();
}

template<class T,class Container>
T& yao::queue<T,Container>::back() {
    return _con.back();
}


void test_my_queue1(){
    //yao::queue<int,std::vector<int>> que;  不能用vector，因为他没有pop_front接口
    yao::queue<int,std::list<int>> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);

    while (!que.empty()){
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << std::endl;

}