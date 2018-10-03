// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 5 章 散列
// main.c
// 实现分离链接法，线性探测、平方探测和双散列的开放定址法
// Powerful Shen
// 2018.9.3 - ~

#include <stdio.h>
#include "hashquad.h"

int main(void)
{
    int input[] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
    const int TABLESIZE = 10;
    HashTable hashquad = InitializeTable(TABLESIZE);

    int input_count = sizeof(input)/sizeof(int);
    for (int i = 0; i < input_count; i++) 
        Insert(input[i], hashquad);

    HashContents(hashquad);
    DestroyTable(hashquad);
    return 0;
}