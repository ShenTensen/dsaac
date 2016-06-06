// HuffmanTree.h
// 
//

#ifndef _HuffmanTree_H
#define _HuffmanTree_H
#include "Stack.h"
typedef char ElementType;                       // 与 #define ElementType char 同意
#define Max 10000
struct TreeNode;                                // 声明结点
typedef struct TreeNode * PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode Root;

// 定义结点
struct TreeNode {
    ElementType Element;
    int Weight;
    PtrToNode Parent;
    PtrToNode LeftChild;
    PtrToNode RightChild;
};

Position CreateTreeNode (void);
Position Search (ElementType X);
int Merge ( PtrToNode * Arr, int Index);
void PrintHuffmanTree (Root Tree, int Level);
void PrintList (PtrToNode * Arr);
void Decode ( const Root HuffmanTree);
void Code ( PtrToNode * Arr, ElementType X, int Index);
void PrintHuffmanTree2 ( PtrToNode * Arr, const int Index, Root Tree, int Level);

#endif
