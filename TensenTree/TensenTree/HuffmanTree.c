//
//  HuffmanTree.c
//  TensenTree
//
//  Created by ShenTensen on 15/11/3.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//

#include "HuffmanTree.h"

struct TreeNode {
    ElementType Element;
    int Weight;
    PtrTreeNode Parent;
    PtrTreeNode Left;
    PtrTreeNode Right;
};

//
PtrTreeNode MakeEmpty (Tree T)
{
    PtrTreeNode temp = (PtrTreeNode) malloc (sizeof (struct TreeNode));
    
    return temp;
}

// 增加结点
PtrTreeNode CreateTreeNode (void)
{
    return (PtrTreeNode) malloc(sizeof(struct TreeNode));
}

//
PtrTreeNode Insert (ElementType X, int W, PtrTreeNode T)
{
    
    return NULL;
}

//
PtrTreeNode Search (ElementType X)
{
    
    return NULL;
}




