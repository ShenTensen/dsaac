// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 
// main.c
// 实现左式堆
// Powerful Shen
// 2018.10.2 - ~

#include "leftheap.h"
#include <stdio.h>

int main(void)
{
    PriorityQueue leftheap;

    leftheap = Initialize();

    for (int i = 1; i < 16; i++)
        Insert(i, leftheap);

    Print(leftheap);
    
    DeleteMin(leftheap);
    Print(leftheap);
    
    return 0;
}