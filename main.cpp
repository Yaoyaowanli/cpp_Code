#include "no1/no1.h"
#include "no2/no2.h"
#include "no3/no3.h"
#include "Sort/Sort.h"
#include "MyDate/Mydate.h"
#include "no4/no4.h"
#include "no5/no5.h"
#include "no6/no6.h"
#include "no7/no7.h"
#include "STL_String/STL_String.h"
#include <time.h>

void TestInsertSort(){
    int arr[] = {1,7,6,0,2,8,4,2,2,8,2};
    //int arr[] = {1,2,3,4,5,6,7,8,9};
    //int arr[] = {9,8,7,6,5,4,3,2,1,0};
    //int arr[] = {};
    InsertSort(arr, sizeof(arr)/ sizeof(arr[0]));
    std::cout << "insertSort : ";
    for (auto e : arr){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void TestShellSort(){
    int arr[] = {1,7,6,0,2,8,4,2,2,8,2};
    //int arr[] = {1};
    ShellSort(arr, sizeof(arr)/ sizeof(arr[0]));
    std::cout << "ShellSort: ";
    for (auto e: arr){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void TestOp(){
    srand(time(0));
    const int N = 10000;
    int* a1 = (int*)malloc(sizeof(int)*N);
    int* a2 = (int*)malloc(sizeof(int)*N);


    for (int i=0; i<N;i++){
        a1[i] = rand();
        a2[i] = a1[i];
    }

    int beginA1 = clock();
    InsertSort(a1,N);
    int endA1 = clock();

    int beginA2 = clock();
    ShellSort(a2,N);
    int endA2 = clock();

    std::cout << "insertSort: " << endA1-beginA1 << std::endl;
    std::cout << "shellSort: " << endA2 - beginA2 << std::endl;

    free(a1);
    free(a2);
}


int main() {
    //TestInsertSort();
    //TestShellSort();
    //TestOp();
    //Test1();
    //Test2();
    //Test3();
    //Test4();
    //Test5();
    //Test6();
    //Test7();
    //Test21();
    //Test22();
    //Test31();
    //Test32();
    //Test33();
    //Test34();
    //Test35();
    //TestMyDate();
    //TestNo4A();
    //TestSum();
    //TestNo5Date3();
    //TestNo5Date4();
    //TestSolution2();
    //TestABCD();
    //TestAno6();
    //TestNo6A();
    //TestTemplate();
    //TestVector();
    //TestString();
    //TestString1();
    //TestString2();
    //TestString3();
    //TestString4();
    //TestString5();
    //TestString6();
    //TestString7();
    //TestString8();
    //TestString9();
    //TestString10();
    TestString11();
    return 0;
}
