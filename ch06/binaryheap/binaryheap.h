// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 6.2, 6.3
// binaryheap.h
// 二叉堆的函数声明
// Powerful Shen
// 2018.9.23 - 9.28

#ifndef _BinaryHeap_H
#define _BinaryHeap_H

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;
// const int MinPQSize = 5;   // 优先队列最少要有这个数目的元素
// const int MinData = -1024; // 下标为 0 的元素的值
// #define MinPQSize 5
// #define MinData -1024
// #define Infinity 1048576

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
// 构建堆，以 O(N)时间构建
void BuildHeap(PriorityQueue H, const ElementType *Array, int ArraySize);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void Print(PriorityQueue H);
void PercolateDown(PriorityQueue H, int i);// 下滤
void PercolateUp(PriorityQueue H, int i);  // 上滤
// 降低位置 i处的关键字的值，降值幅度为正的量 Delta
void DecreaseKey(int i, int Delta, PriorityQueue H);
// 增加关键字的值
void IncreaseKey(int i, int Delta, PriorityQueue H);
// 删除位置 i上的节点
void Delete(int i, PriorityQueue H);

#endif // _BinaryHeap_H