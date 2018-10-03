// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 
// leftheap.h
// 实现左式堆
// Powerful Shen
// 2018.10.2 - ~

#ifndef _LEFTHEAP_H
#define _LEFTHEAP_H

#define Sentinel -1024

struct TreeNode;
typedef struct TreeNode *PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H) (H = Insert1((X), H))
PriorityQueue Insert1(ElementType X, PriorityQueue H);
#define DeleteMin(H) (H = DeleteMin1(H))
PriorityQueue DeleteMin1(PriorityQueue H);

void SwapChildren(PriorityQueue H);
void Print(PriorityQueue H);

#endif
