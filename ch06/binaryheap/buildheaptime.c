// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 6.11
// buildheaptime.c
// 二叉堆的不同建立方式的时间比较
// Powerful Shen
// 2018.9.28 - 9.28

#include "binaryheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 1000000;

int main(void)
{
    PriorityQueue binaryheap = Initialize(N);
    int array[N];
    clock_t clock1, clock2;

    // 习题 6.11
    // 已排序
    for (int i = 0; i < N; i++)
        array[i] = i + 1;
    // 逆序
    // for (int i = N - 1; i >= 0; i--)
    //     array[i] = i + 1;
    // 随机输入
    // srand(time(NULL));
    // for (int i = 0; i < N; i++)
    // {
    //     array[i] = rand() % 1000000 + 1;
    // }    

    clock1 = clock();
    // for (int i = 0; i < N; i++)
    // {
    //     Insert(array[i], binaryheap);
    // }
    B1uildHeap(binaryheap, array, N);
    clock2 = clock();
    printf("%lu\n", clock2 - clock1);

    return 0;
}
