//
// Created by 姚远 on 2022/10/23.
//

#include "STL_priority_queue.h"




void test_priority_queue1(){
    //priority_queue<int> pq; //默认大的优先级高
    //如果想让小的优先级高，就需要用到仿函数
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(3);
    pq.push(1);
    pq.push(9);
    pq.push(4);
    pq.push(2);

    while (! pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}