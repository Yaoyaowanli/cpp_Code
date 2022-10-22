//
// Created by 姚远 on 2022/10/22.
//

#include "my_stack.h"


template<class T,class Container>
void yao::stack<T,Container>::push(const T &x) {
    _con.push_back(x);
}

template<class T, class Container>
void yao::stack<T,Container>::pop() {
    _con.pop_back();
}

template<class T,class Container>
size_t yao::stack<T,Container>::size() {
    return _con.size();
}

template<class T,class Container>
T& yao::stack<T,Container>::top() {
    return _con.back();
}

template<class T,class Container>
bool yao::stack<T,Container>::empty() {
    return _con.empty();
}




void test_my_stack1(){
    //yao::stack<int,std::vector<int>> st;
    yao::stack<int,std::list<int>> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while (!st.empty()){
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;

}