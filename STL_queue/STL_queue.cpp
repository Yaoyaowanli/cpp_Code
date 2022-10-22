//
// Created by 姚远 on 2022/10/21.
//

#include "STL_queue.h"



void test_queue1(){
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);

    while (!que.empty()){
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
}