// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 
// leftheap.c
// 实现左式堆
// Powerful Shen
// 2018.10.2 - ~

#include "leftheap.h"
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    ElementType   Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int           Npl;      // Null path length, 零路径长
};

PriorityQueue Initialize(void)
{
    PriorityQueue H = NULL;
    return H;
}

ElementType FindMin(PriorityQueue H)
{
    if (IsEmpty(H))
    {
        fprintf(stderr, "FindMin: 优先队列为空\n");
        return Sentinel;
    }
    return H->Element;
}

int IsEmpty(PriorityQueue H)
{
    return H == NULL;
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if (H1->Left == NULL) // 单节点
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H1->Right->Npl)
            SwapChildren(H1);
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

// 合并左式堆的驱动函数
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    // 以有较小的元素的堆为根
    if (H1->Element < H2->Element)
        return Merge1(H1, H2);
    else 
        return Merge1(H2, H1);
}

// 创建单节点堆，调用 Merge 实现插入
PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;

    SingleNode = malloc(sizeof(struct TreeNode));
    if (SingleNode == NULL)
    {
        fprintf(stderr, "Insert1: Out of space!!!\n");
    } else {
        SingleNode->Element = X;
        SingleNode->Left = SingleNode->Right = NULL;
        SingleNode->Npl = 0;
        H = Merge(SingleNode, H);
    }   
    return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap, RightHeap;
    
    if (IsEmpty(H))
    {
        fprintf(stderr, "DeleteMin1: 优先队列为空\n");
        return H;
    }
    
    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}

void SwapChildren(PriorityQueue H)
{
    PriorityQueue TempTree;

    if (IsEmpty(H))
    {
        fprintf(stderr, "SwapChildren: 优先队列为空\n");
        return;
    }
    TempTree = H->Left;
    H->Left = H->Right;
    H->Right = TempTree;
}

void Print(PriorityQueue H)
{
    if (IsEmpty(H))
        return;
    
    printf("%d\t", H->Element);
    Print(H->Left);
    Print(H->Right);
}
