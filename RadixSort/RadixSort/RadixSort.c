//
//  main.c
//  RadixSort
//
//  Created by ShenTensen on 15/12/1.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//  基数排序

#include <stdio.h>
#define BASE 10
#define LIMIT 12            // 二维数组第二维大小，注意，不然之后存储会出现问题

void RadixSort (int *Arr, int Length);
int FindMax (int * Arr, int Length);

int main(void)
{
    int array[12] = {
        1, 92, 334, 14, 38, 45, 87, 2, 589, 33, 91, 78
    };
    
    RadixSort(array, 12);
    
    return 0;
}

// 基数排序
void RadixSort (int *Arr, int Length)
{
    int bucket[BASE][LIMIT] = {0};      // 初始化
    int LoopTimes = 1;                  // 确定循环次数
    int max = FindMax(Arr, Length);
    while ( (max = max / 10) != 0)
        LoopTimes++;
    
    int count = 1;
    int tempbase = 1;
    while (count <= LoopTimes)
    {
        // 打印数组
        printf ("Arr[12] = {");
        for (int i = 0;  i < 12; i++)
            printf("%d,", Arr[i]);
        printf("}\n");

        for (int i = 0; i < Length; i++)
        {
            bucket[Arr[i] / tempbase % BASE][0]++;       // 数组第二维的元素数量
            bucket[Arr[i] / tempbase % BASE][bucket[Arr[i] / tempbase % BASE][0]] = Arr[i];
        }
        
        // 更新数组
        int  k = 0;
        for (int i = 0; i < BASE; i++)
        {
            for (int j = 1; j <= bucket[i][0]; j++)
                if (k < 12)                 // 此处隐藏着问题
                    Arr[k++] = bucket[i][j];
        }
        
        // 打印二维数组
        for (int i = 0; i < BASE; i++)
        {
            printf ("bucket[%d] = {", i);
            for (int j = 1; j <= bucket[i][0]; j++)
                printf("%d,", bucket[i][j]);
            printf ("}\n");
        }
        
        
        // 擦除痕迹
        for (int i = 0; i < BASE; i++)
            for (int j = 0; j < LIMIT; j++)
                bucket[i][j] = 0;
        
        count++;
        tempbase = tempbase * BASE;
    }
    
    // 打印数组
    printf ("Arr[12] = {");
    for (int i = 0;  i < 12; i++)
        printf("%d,", Arr[i]);
    printf("}\n");
    
}

// 找最大元素的值
int FindMax (int * Arr, int Length)
{
    int max= Arr[0];
    
    for (int i = 0; i < Length; i++)
        max = (max < Arr[i]) ? Arr[i] : max;
    
    return max;
}









