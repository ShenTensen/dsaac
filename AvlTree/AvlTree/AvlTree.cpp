//
//  AVLTree.cpp
//  AvlTree
//
//  Created by ShenTensen on 15/12/1.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//

#include "AvlTree.hpp"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

// 定义结构体
struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

// 这些函数只在此文件中使用
static Position SingleRotateWithLeft (Position K2);
static Position SingleRotateWithRight (Position K2);
static Position DoubleRotateWithLeft (Position K3);
static Position DoubleRotateWithRight (Position K3);
static int Height (Position P);
static int Max (int A, int B);


// 插入元素，平衡树
AvlTree Insert (ElementType X, AvlTree Tree)
{
    if (Tree == NULL)
    {
        Tree = (Position)malloc (sizeof (struct AvlNode));
        
        if (Tree == NULL)
            printf ("No space for Node!\n");
        else
        {
            Tree->Element = X;
            Tree->Height = 0;
            Tree->Left = Tree->Right = NULL;
        }
    }
    else if ( X < Tree->Element)
    {
        Tree->Left = Insert( X, Tree->Left);
        if ( Height (Tree->Left) - Height (Tree->Right) == 2)
        {
            if (X < Tree->Left->Element)
                Tree = SingleRotateWithLeft (Tree);
            else
                Tree = DoubleRotateWithLeft (Tree);
        }
    }
    else if ( X > Tree->Element)
    {
        Tree->Right = Insert(X, Tree->Right);
        if ( Height ( Tree->Right) - Height ( Tree->Left) == 2)
        {
            if (X > Tree->Right->Element)
                Tree = SingleRotateWithRight (Tree);
            else
                Tree = DoubleRotateWithRight (Tree);
        }
    }
    
    Tree->Height = Max( Height(Tree->Left), Height(Tree->Right)) + 1;
    
    return Tree;
}

// 左单旋转
static Position SingleRotateWithLeft (Position K2)
{
    Position K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->Height = Max( Height( K2->Left), Height( K2->Right)) + 1;
    K1->Height = Max( Height( K1->Left), Height( K1->Right)) + 1;
    
    return K1;
}

// 右单旋转
static Position SingleRotateWithRight (Position K2)
{
    Position K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    K2->Height = Max( Height( K2->Left), Height( K2->Right)) + 1;
    K1->Height = Max( Height( K1->Left), Height( K1->Right)) + 1;
    // 看看我的这句代码和上面例程相差在哪儿。
    // 不够明晰，但少调用了一次函数，不知是否有错。
//    K2->Height = K1->Left->Height - 1;    // 必不可少！！！
//    K1->Height = Max( Height( K1->Left), Height( K1->Right)) + 1;
    
    return K1;
}

// 左双旋转
static Position DoubleRotateWithLeft (Position K3)
{
    Position K1 = K3->Left;
    K3->Left = SingleRotateWithRight (K1);
    
    return SingleRotateWithLeft (K3);
}

// 右双旋转
static Position DoubleRotateWithRight (Position K3)
{
    Position K1 = K3->Right;
    K3->Right = SingleRotateWithLeft(K1);
    
    return SingleRotateWithRight(K3);
}

// 返回结点的高度
static int Height (Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

// 返回两个数中最大的数
static int Max (const int A, const int B)
{
//    if ( A > B)
//        return A;
//    else
//        return B;
    return (A > B) ? A : B;
}

// 使用递归打印树
// 也许可以增加一个指向父结点的指针，判断当前结点是左子还是右子，使打印更清晰
void PrintAvlTree (Position Tree, int Level)
{
    if ( Tree == NULL)
        return;
    // 中序遍历看起来最明晰
    PrintAvlTree ( Tree->Left, Level + 1);
    std::cout << '|';
    for ( int i = 0; i < Level; i++)
        std::cout << "\t";
    std::cout << Tree->Element << std::endl;// " " << Tree->Height << std::endl;
    // PrintAvlTree ( Tree->Left, Level + 1);
    PrintAvlTree ( Tree->Right, Level + 1);
}


