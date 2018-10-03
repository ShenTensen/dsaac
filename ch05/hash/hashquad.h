// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 5 章 散列
// hashquad.h
// 平方探测开放定址法
// Powerful Shen
// 2018.9.3 - ~

#ifndef _HashQuad_H

typedef int ElementType;
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
// 原例程中没有 Hash 函数
Position Hash(ElementType Key, int TableSize);
HashTable Rehash(HashTable H);  // 再散列
// 书中没有这个函数
void HashContents(HashTable H); // 显示散列表中的内容
#endif  // _HashQuad_H