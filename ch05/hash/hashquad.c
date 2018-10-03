// 数据结构与算法分析--C语言描述（原书第2版）
// Mark Allen Weiss 著
// 第 5 章 散列
// hashquad.c
// 平方探测开放定址法
// Powerful Shen
// 2018.9.3 - ~

#include <stdio.h>
#include <stdlib.h>
#include "hashquad.h"

const int MinTableSize = 7;  // 散列表大小最少为7

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry {
    ElementType         Element;
    enum KindOfEntry    Info;
};

typedef struct HashEntry Cell;

struct HashTbl {
    int TableSize;
    Cell *TheCells;
};

HashTable InitializeTable(int TableSize)
{
    HashTable H;

    if (TableSize < MinTableSize)
    {
        fprintf(stderr, "Table size too small");
        return NULL;
    }

    // 为散列开辟内存
    H  = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        fprintf(stderr, "Out of space!!!");

    H->TableSize = TableSize;  // 为了适应练习5.1，与图5-15不同

    // 为每一个元素条目开辟内存
    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if (H->TheCells == NULL) 
        fprintf(stderr, "Ount of space!!!");

    for (int i = 0; i < H->TableSize; i++)
        H->TheCells[i].Info = Empty;

    return H;
}

void DestroyTable(HashTable H);

// 平方探测散列法
Position Find(ElementType Key, HashTable H)
{
    Position CurrentPos;
    int CollisionNum;

    CollisionNum = 0;
    CurrentPos = Hash(Key, H->TableSize);
    while (H->TheCells[CurrentPos].Info != Empty &&
           H->TheCells[CurrentPos].Element != Key)
    {
        CurrentPos += 2 * ++CollisionNum - 1;
        if (CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
    Position Pos;

    Pos = Find(Key, H);
    if (H->TheCells[Pos].Info != Legitimate)
    {
        // 插入
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}

// 例子没有给出这个函数的实现
Position Hash(ElementType Key, int TableSize)
{
    Position Pos;

    Pos = Key % TableSize;  // 散列函数h(X) = X(mod 10)
    return Pos;
}

// 例子没有给出这个函数的实现
void DestroyTable(HashTable H)
{
    free(H->TheCells);
    free(H);
}

void HashContents(HashTable H)
{
    if (H->TableSize > 0) 
    {
        printf("TableSize: %d\n", H->TableSize);
        for (int i = 0; i < H->TableSize; i++)
        {
            if (H->TheCells[i].Info != Empty)
                printf("%d: %d\n", i, H->TheCells[i].Element);
            else
                printf("%d: NULL\n", i); 
        }
    }
}

HashTable Rehash(HashTable H);