//
// Created by 姚远 on 2022/10/2.
//

#include "Sort.h"


//插入排序 :
// 时间复杂度：最好情况（有序）：O(N)  ； 最坏情况（逆序）：O(N^2);
// 空间复杂度：O(1);
void InsertSort(int* arr,int n){
    assert(arr);
    //将第一位看作有序，每次取后面一位向前遍历插入
    for (int i=1 ; i<n ; i++){
        int key = arr[i];
        int end = i-1;

        while (end >= 0){
            if (arr[end]>key){
                arr[end+1] = arr[end];
                end--;
            }else{
                break;
            }
        }

        arr[end+1] = key;
    }
}

//希尔排序:
// 时间复杂度： O(N^1.3 - N^2)
void ShellSort(int* arr,int n){
    assert(arr);
    int gap = n;

    while (gap>1) {
        //+1是为了保证最后一次进行一次直接插入排序
        gap = gap/3+1;

        //循环从数组的第一个元素开始，排第一组的第一部分，然后++排第二组的第一部分然后++。。。直到排到n-gap的时候所有组就排完了。
        for (int i =0; i < n-gap; i++){
            int end = i;
            int key = arr[end+gap];

            while (end >=0){
                if (arr[end] > key){
                    arr[end+gap] = arr[end];
                    end-=gap;
                }else{
                    break;
                }
            }
            arr[end+gap] = key;
        }
    }
}


//选择排序
void SelectSort(int* arr,int n){

}