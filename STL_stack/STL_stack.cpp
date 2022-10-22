//
// Created by 姚远 on 2022/10/21.
//

#include "STL_stack.h"



void test_stack1(){
//stack没有迭代器
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while(!st.empty()){
        cout << st.top() << " " ;
        st.pop();
    }
    cout << endl;
}