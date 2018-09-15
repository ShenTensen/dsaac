//
//  main.c
//  PrimeNumberSearch
//
//  Created by ShenTensen on 15/12/17.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//  打印从2到指定范围内的所有质数
//  这段代码似乎有瑕疵！

#include <stdio.h>
#include <math.h>
//#define N 300
const int N = 300;                                  // 指定范围

int main(void)
{
    int arr[N - 1] = {0};

    for ( int i = 0; i < N - 1; i++)                // 初始化数组，从 2到 N，数组共 N - 1 个元素
        arr[i] = i + 2;
    
//    for (int i = 0; i < N - 1; i++)                   // 检查数组的初始化是否合理
//        printf ("%-4d ", arr[i]);
    
//    研究这段代码
//    for ( int i = 2; i <= sqrt(N) ; i++)
//        for ( int j = 1; i * j <= N; j++)
//            if ( arr[i * j - 1] != 0)
//            {
//                if ( j == 1)
//                    printf ("%-4d ", arr[i - 1]);
//                else
//                    arr[i * j - 1]	= 0;
//            }
    
    
    for ( int i = 2; i <= sqrt(N) ; i++)
        for ( int j = 1; i * j <= N; j++)
            if ( arr[i * j - 2] != 0 && j != 1 )    // 注意索引和里面存储的值的关系
                    arr[i * j - 2]	= 0;

//    for (int i = 0; i < N - 1; i++)
//                printf ("%-4d ", arr[i]);
    
    // 打印素数，即表中不为0的数
    for (int i = 0; i < N; i++)
        if (arr[i] != 0)
            printf ("%-4d ", arr[i]);
    
    printf("\n");
    
    return 0;
}


