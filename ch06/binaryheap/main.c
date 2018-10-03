// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 6.2, 6.3, 6.5
// main.c
// 实现二叉堆
// Powerful Shen
// 2018.9.23 - 9.28

#include "binaryheap.h"
#include <stdio.h>
#include <string.h>

int main(void)
{    
    const int array[] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
    int size = sizeof(array) / sizeof(int);
    PriorityQueue binaryheap = Initialize(size);

    printf("sizeof(array): %lu\n", sizeof(array)); // 60
    // printf("strlen(array): %lu\n", strlen(array)); // 1

    // 习题 6.2 a
    for (int i = 0; i < size; i++)
    {
        Insert(array[i], binaryheap);
    }
    // 显示堆的内容
    printf("Insert(one by one):\n");
    Print(binaryheap);

    // 习题 6.2 b
    // BuildHeap(binaryheap, array, size);
    // 显示堆的内容
    // printf("BuildHeap:\n");
    // Print(binaryheap);

    // 习题 6.3
    // for (int i = 0; i < 3; i++)
    //     DeleteMin(binaryheap);
    // printf("DeleteMin(3 times):\n");
    // Print(binaryheap);

    // 习题 6.5
    printf("FindMin: %d\n", FindMin(binaryheap));
    DecreaseKey(3, 10, binaryheap);
    printf("DecreaseKey(3, 10):\n");
    Print(binaryheap);
    printf("FindMin: %d\n", FindMin(binaryheap));

    IncreaseKey(1, 10, binaryheap);
    printf("IncreaseKey(1, 10):\n");
    Print(binaryheap);
    printf("FindMin: %d\n", FindMin(binaryheap));
    
    Delete(5, binaryheap);
    printf("Delete(5, binaryheap):\n");
    Print(binaryheap);

    Destroy(binaryheap);
    return 0;
}

