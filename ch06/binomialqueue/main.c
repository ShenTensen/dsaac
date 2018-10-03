// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 6.32
// main.c
// 实现二项队列
// Powerful Shen
// 2018.10.3 - ~

#include "binomialqueue.h"
#include <stdio.h>

int main(void)
{
    BinQueue binomialqueue = Initialize();
    
    for (int i = 1; i <= 15; i++)
        binomialqueue = Insert(i, binomialqueue);

    Print(binomialqueue);
    return 0;
}