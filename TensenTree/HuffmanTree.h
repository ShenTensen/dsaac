//
// 
// 
#ifndef _HuffmanTree_H
#define _HuffmanTree_H



#include <stdlib.h>
#define ElementType char

struct TreeNode;
typedef struct TreeNode * Tree;
typedef struct TreeNode * PtrTreeNode;


PtrTreeNode MakeEmpty (Tree T);
PtrTreeNode Insert (ElementType X, int W, Tree T);
PtrTreeNode Search (ElementType X);
PtrTreeNode Delete (ElementType X, PtrTreeNode PNode);
PtrTreeNode CreateTreeNode (void);

#endif
