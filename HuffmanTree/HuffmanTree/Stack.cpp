//
//  Stack.cpp
//  HuffmanTree
//
//  Created by ShenTensen on 15/11/6.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>
// 如果要实现一些功能，必须将结构体定义放到头文件中去，不知为何！！
// 定义结点
struct Node {
    ElementType1 Element;
    Pnode Next;
};

// 创建栈
Stack CreateStack (void)
{
    Stack S;
    S = (Stack)malloc (sizeof (struct Node));          // S 本身是指向某个地址的指针
    if ( S == NULL )
        fprintf (stderr, "out of space!");
    S->Next = NULL;
    //此处何必要 MakeEmpty
    //MakeEmpty
    
    return S;
}

// 将元素压入栈顶
void Push (ElementType1 X, Stack S)
{
    Pnode temp;
    
    temp = (Stack)malloc(sizeof (struct Node));
    if ( temp == NULL )
    {
        fprintf (stderr, "out of space!");
        exit (1);
    } else {
        temp->Element = X;
        temp->Next = S->Next;
        S->Next = temp;
    }
}

// 弹出栈顶元素
void Pop (Stack S)
{
    if ( IsEmpty(S) )
    {
        fprintf (stderr, "Empty stack!");
        exit(0);
    } else {
        Pnode temp;
        temp = S->Next;
        S->Next = S->Next->Next;
        free (temp);
    }
}

// 返回栈顶元素
ElementType1 Top (Stack S)
{
    if ( IsEmpty(S)) {
        printf("Empty stack!");
        //fprintf (stderr, "Empty stack!\n");
        // 注意：fprintf 的机制特殊！！！
        return 0;
    } else
        return S->Next->Element;
}

// 检查栈是否为空，若为空返回0
int IsEmpty (Stack S)
{
    if ( S->Next == NULL)
        return 1;
    else
        return 0;
}

// 删除栈，清空
void DeleteStack (Stack S)
{
    while ( S->Next != NULL)
    {
        Stack temp = S->Next;
        S->Next = S->Next->Next;
        free(temp);
    }
    free (S);                   // 清空S指向的内存空间
    // S占的内存空间怎么办？
}

