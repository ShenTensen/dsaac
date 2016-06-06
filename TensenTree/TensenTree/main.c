//
//  main.c
//  TensenTree
//
//  Created by ShenTensen on 15/10/27.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
//#include "HuffmanTree.h"

#define ElementType char;
#define N (20)
struct TreeNode;
typedef struct TreeNode * Tree;
typedef struct TreeNode * PtrTreeNode;

struct TreeNode {
    ElementType Element;
    int Weight;
    PtrTreeNode Parent;
    PtrTreeNode Left;
    PtrTreeNode Right;
};

int main()
{
    PtrTreeNode you;
    you = malloc ( sizeof (struct Node));
  //  you->Weight = 10;
    PtrTreeNode array[10];
    char ch;
    while ( (ch = getchar()) != '\n')
    {
        int i = 0;
        array[i] = CreateTreeNode();
        array[i]->Element = ch;
        
        
        
    }
    
    
    return 0;
}
