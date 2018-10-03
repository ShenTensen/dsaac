// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 6.32
// binomialqueue.c
// 实现二项队列
// Powerful Shen
// 2018.10.3

#include "binomialqueue.h"
#include <stdio.h>
#include <stdlib.h>

static void PrintBinNode(BinTree T);

// 节点
struct BinNode {
    ElementType Element;
    Position    LeftChild;
    Position    NextSibling;
};

// 二项队列
struct Collection {
    int CurrentSize;
    BinTree TheTrees[MaxTrees];
};

BinQueue Initialize(void)
{
    BinQueue H = malloc(sizeof(struct Collection));

    if (H == NULL)
    {
        fprintf(stderr, "Initialize: Out of space!!!\n");
        return H;
    }
    // 初始化二项队列
    H->CurrentSize = 0;
    for (int i = 0; i < MaxTrees; i++)
        H->TheTrees[i] = NULL;
    return H;
}

// 使用 Merge
BinQueue Insert(ElementType X, BinQueue H)
{
    BinQueue NewQueue = Initialize();
    BinTree SingleTree = malloc(sizeof(struct BinNode));

    if (SingleTree == NULL)
    {
        fprintf(stderr, "Insert: Out of space!!!\n");
        return H;
    }
    // 构造单节点二项树
    SingleTree->Element = X;
    SingleTree->LeftChild = NULL;
    SingleTree->NextSibling = NULL;

    NewQueue->CurrentSize = 1;
    NewQueue->TheTrees[0] = SingleTree;

    return Merge(H, NewQueue);
}

BinQueue Merge(BinQueue H1, BinQueue H2)
{
    BinTree T1, T2, Carry = NULL;

    // 习题 6.32 a
    // 避免传进同一个二项队列产生破坏
    if (H1 == H2)
    {
        fprintf(stderr, "Merge: 合并的两个二项队列是同一个\n");
        return H1;
    }

    if (H1->CurrentSize + H2->CurrentSize > Capacity)
    {
        fprintf(stderr, "Merge: Merge would exceed capacity\n");
        return H1;
    }

    // 习题 6.32 c
    // 使得较小的树总被和合并到较大的树中
    if (H1->CurrentSize < H2->CurrentSize)
        return Merge(H2, H1);

    H1->CurrentSize += H2->CurrentSize;
    for (int i = 0, j = 1; j <= H1->CurrentSize; i++, j*=2)
    {
        T1 = H1->TheTrees[i];
        T2 = H2->TheTrees[i];

        switch (IsTreeExist(T1) + 2 * IsTreeExist(T2) 
                                + 4 * IsTreeExist(Carry))               
        {
            case 0: // No Trees
            case 1: // 只有 H1
                break;
            case 2: // 只有 H2
                H1->TheTrees[i] = T2;
                H2->TheTrees[i] = NULL;
                break;
            case 3: // H1 和 H2
                Carry = CombineTrees(T1, T2);
                H1->TheTrees[i] = H2->TheTrees[i] = NULL;
                break;
            case 4: // 只有新合并的树
                H1->TheTrees[i] = Carry;
                Carry = NULL;
                break;
            case 5: // H1 和 Carry
                Carry = CombineTrees(T1, Carry);
                H1->TheTrees[i] = NULL;
                break;
            case 6: // H2 和 Carry
                Carry = CombineTrees(T2, Carry);
                H2->TheTrees[i] = NULL;
                break;
            case 7: // 所有树
                H1->TheTrees[i] = Carry;
                Carry = CombineTrees(T1, T2);
                H2->TheTrees[i] = NULL;
                break;
        }
    }
    return H1;
}

ElementType DeleteMin(BinQueue H)
{
    int MinTree; // 拥有最小元素的树
    BinQueue DeletedQueue;
    BinTree DeletedTree, OldRoot;
    ElementType MinItem;

    if (IsEmpty(H))
    {
        fprintf(stderr, "DeleteMin: 二项队列为空\n");
        return -Infinity;
    }

    // 寻找最小元素及其所在的树
    MinItem = Infinity;
    for (int i = 0, j = 1; j <= H->CurrentSize; i++, j*=2)
    {
        if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)
        {
            MinTree = i;
            MinItem = H->TheTrees[MinTree]->Element;
        }
    }
    
    DeletedTree = H->TheTrees[MinTree];
    OldRoot = DeletedTree;
    DeletedTree = DeletedTree->LeftChild;
    free(OldRoot);

    // 最小元素删除后形成的二项队列
    DeletedQueue = Initialize();
    DeletedQueue->CurrentSize = (1 << MinTree) - 1;
    for (int i = MinTree - 1; i >= 0; i--)
    {
        DeletedQueue->TheTrees[i] = DeletedTree->LeftChild;
        DeletedTree = DeletedTree->NextSibling;
        DeletedQueue->TheTrees[i]->NextSibling = NULL;
    }

    H->TheTrees[MinTree] = NULL;
    H->CurrentSize -= DeletedQueue->CurrentSize + 1;

    H = Merge(H, DeletedQueue);
    return MinItem;
}

// 合并两棵同等大小的树，返回结果
BinTree CombineTrees(BinTree T1, BinTree T2)
{
    if (T1->Element > T2->Element)
        return CombineTrees(T2, T1);
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
    return T1;
}

int IsEmpty(BinQueue H)
{
    if (H == NULL)
    {
        fprintf(stderr, "IsEmpty: 二项队列不存在\n");
        return 0;
    }

    if (H->CurrentSize > 0)
        return 0;
    else 
        return 1;
}

// 判断二项树是否存在
int IsTreeExist(BinTree T)
{
    if (T == NULL)
        return 0;
    else
        return 1;
}

void Print(BinQueue H)
{
    if (IsEmpty(H))
    {
        fprintf(stderr, "Print: 二项队列为空\n");
        return;
    }

    for (int i = 0; i < MaxTrees; i++)
    {
        printf("%d:\n", i);
        PrintBinNode(H->TheTrees[i]);
        printf("--------------------------\n");
    }
}

static void PrintBinNode(BinTree T)
{
    if (T == NULL)
        return;

    printf("%d  ", T->Element);
    PrintBinNode(T->LeftChild);
    PrintBinNode(T->NextSibling);
    printf("\n");
}