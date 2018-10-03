// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 6.2, 6.3, 6.4, 6.5
// binaryheap.c
// 二叉堆的实现
// Powerful Shen
// 2018.9.23 - 9.28

#include "binaryheap.h"
#include <stdio.h>
#include <stdlib.h>

#define MinPQSize 5
#define MinData -1048576
#define Infinity 1024

// 声明在头文件，定义在此处
struct HeapStruct {
    int Capacity;
    int Size;
    ElementType *Elements;
};

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    
    if (MaxElements < MinPQSize)
        fprintf(stderr, "Priority queue size is too small");

    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        fprintf(stderr, "Out of space!!!");

    // 多开辟一份内存作为标记
    H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
    if (H->Elements == NULL)
        fprintf(stderr, "Out of space!!!");

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;

    return H;
}

void Destroy(PriorityQueue H)
{
    free(H->Elements);
    free(H);
}

void Insert(ElementType X, PriorityQueue H)
{
    int i;

    if (IsFull(H))
    {
        fprintf(stderr, "Insert: Priority queue is full\n");
        return;
    }

    for (i = ++H->Size; H->Elements[i/2] > X; i /= 2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}

void BuildHeap(PriorityQueue H, const ElementType *Array, int ArraySize)
{
    if (!IsEmpty(H))
    {
        char *function = "BuildHeap";
        fprintf(stderr, "%s: Priority queue is not empty\n", function);
        return;
    }
        
    // 将 Array中的关键字不排序放入树中
    for (int i = 1; i <= ArraySize; i++)
    {
        H->Elements[i] = Array[i-1]; // 注意索引不同！
    }
    H->Size = ArraySize;

    for (int i = H->Size / 2; i > 0; i--)
    {
        // PercolateDown(i); // 下滤
        int Child, TempElement;
        // 下滤结点 i
        for (int j = i; j * 2 <= H->Size; j = Child)
        {
            Child = j * 2;
            if (Child != H->Size && H->Elements[Child + 1]
                                  < H->Elements[Child])
                Child++;

            if (H->Elements[j] > H->Elements[Child])
            {
                TempElement = H->Elements[j];
                H->Elements[j] = H->Elements[Child];
                H->Elements[Child] = TempElement;
            } else 
            {
                break;
            }
        }
    }
}

ElementType DeleteMin(PriorityQueue H)
{
    int i, Child;
    ElementType MinElement, LastElement;

    if (IsEmpty(H))
    {
        fprintf(stderr, "DeleteMin: 优先队列为空\n");
        return H->Elements[0];
    }

    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    // 从根开始下滤
    for (i = 1; i * 2 <= H->Size; i = Child)
    {
        // 找出更小的儿子
        Child = i * 2;
        if (Child < H->Size && (H->Elements[Child+1] < H->Elements[Child]))
            Child++;
        
        if (H->Elements[Child] < LastElement)
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

ElementType FindMin(PriorityQueue H)
{
    if (IsEmpty(H))
    {
        fprintf(stderr, "FindMin: 优先队列为空\n");
        return H->Elements[0];
    }
    return H->Elements[1];
}

int IsEmpty(PriorityQueue H)
{
    if (H->Size == 0)
        return 1;
    else
        return 0;
}

int IsFull(PriorityQueue H)
{
    if (H->Size >= H->Capacity)
        return 1;
    else 
        return 0;
}

void Print(PriorityQueue H)
{
    if (IsEmpty(H)) 
    {
        fprintf(stderr, "Print: 优先队列为空\n");
        return;
    }
    
    printf("index: ");
    for (int i = 1; i <= H->Size; i++)
        printf("%3d ", i);
    printf("\n");

    printf("elem:  ");
    for (int i = 1; i <= H->Size; i++)
        printf("%3d ", H->Elements[i]);
    printf("\n");
}

// 下滤索引为 i的节点
void PercolateDown(PriorityQueue H, int i)
{
    int Child = 0;
    ElementType Element;

    if (IsEmpty(H))
    {
        fprintf(stderr, "PercolateDown: 优先队列为空\n");
        return;
    }

    if (i < 0 || i > H->Size)
    {
        fprintf(stderr, "PercolateDown: i 的值不合法\n");
        return;
    }
    Element = H->Elements[i];

    for (; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;

        // 确定最小的子节点
        if (Child < H->Size && H->Elements[Child+1] < H->Elements[Child])
            Child++;

        if (H->Elements[Child] < Element)
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = Element;
}

// 上滤索引为 i的节点
void PercolateUp(PriorityQueue H, int i)
{
    ElementType Element;

    if (IsEmpty(H))
    {
        fprintf(stderr, "PercolateUp: 优先队列为空\n");
        return;
    }

    if (i < 0 || i > H->Size)
    {
        fprintf(stderr, "PercolateUp: i的值不合法\n");
        return;
    }
    Element = H->Elements[i];

    for (; H->Elements[i/2] > Element; i /= 2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = Element;
}

void DecreaseKey(int i, int Delta, PriorityQueue H)
{
    if (IsEmpty(H))
    {
        fprintf(stderr, "DecreaseKey: 优先队列为空\n");
        return;
    }
    if (i < 0 || i > H->Size)
    {
        fprintf(stderr, "DecreaseKey: i的值不合法\n");
        return;
    }

    H->Elements[i] -= Delta;
    PercolateUp(H, i);
}

void IncreaseKey(int i, int Delta, PriorityQueue H)
{
    if (IsEmpty(H))
    {
        fprintf(stderr, "IncreaseKey: 优先队列为空\n");
        return;
    }
    if (i < 0 || i > H->Size)
    {
        fprintf(stderr, "IncreaseKey: i的值不合法\n");
        return;
    }

    H->Elements[i] += Delta;
    PercolateDown(H, i);
}

void Delete(int i, PriorityQueue H)
{
    if (IsEmpty(H))
    {
        fprintf(stderr, "Delete: 优先队列为空\n");
        return;
    }
    if (i < 0 || i > H->Size)
    {
        fprintf(stderr, "Delete: i的值不合法\n");
        return;
    }
    DecreaseKey(i, Infinity, H);
    DeleteMin(H);
}