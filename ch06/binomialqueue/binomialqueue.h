// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 6 章 优先队列（堆）
// 习题 6.32
// binomialqueue.h
// 实现二项队列
// Powerful Shen
// 2018.10.3

#ifndef _BINOMIALQUEUE_H
#define _BINOMIALQUEUE_H

#define MaxTrees 30   // 二项队列支持的最大树数量
#define Capacity 200  // 二项队列支持的最大节点数量
#define Infinity 1024 // 代表某个很大的值

struct BinNode;
struct Collection;
typedef struct BinNode *BinTree;
typedef struct BinNode *Position;
typedef struct Collection *BinQueue;
typedef int ElementType;

BinQueue Initialize(void);
BinQueue Insert(ElementType, BinQueue H);
BinQueue Merge(BinQueue H1, BinQueue H2);
ElementType DeleteMin(BinQueue H);
BinTree CombineTrees(BinTree T1, BinTree T2);
int IsEmpty(BinQueue H);
int IsTreeExist(BinTree T);
void Print(BinQueue H);

#endif // _BINOMIALQUEUE_H