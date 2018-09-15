//
//  TensenList.c
//  TensenList
//
//  Created by ShenTensen on 15/12/28.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//  链表实现程序


#include "TensenList.h"
//#include <stdlib.h>

struct Node {
    ElementType Element;
    Pnode Next;
};


// 创建链表，使用头指针
List CreateList (void)
{
    List Header = NULL;         // 这儿的变量如何命名合适？
    
    Header = malloc(sizeof(struct Node));   // 为头指针开辟出了不被使用的存放元素的空间
    Header->Element = '\0';
    Header->Next = NULL;
    
    return Header;
}

// 插入元素，变量 L 未使用，插到 P 的下一个结点
void Insert (ElementType Elem, Position P)
{
    Position TempCell;
    
    TempCell = malloc(sizeof(struct Node));
    TempCell->Element = Elem;
    
    TempCell->Next = P->Next;
    P->Next = TempCell;
}

// 打印链表中所有元素
void PrintList (List L)
{
    while (L != NULL)
    {
        printf ("%c ", L->Element);
        L = L->Next;
    }
    printf ("\n");
}

// 删除整个链表
void DeleteList (List L)
{
    Position P, Tmp;
    
    P = L->Next;
    L->Next = NULL;         // L 的空间依然存在，只是指向空地址
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}


















