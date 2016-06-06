//哈夫曼树的实现程序
//

#include "HuffmanTree.h"
#include "Stack.h"
#include <stdlib.h>
#include <iostream>

// 创建树结点，返回地址
PtrToNode CreateTreeNode (void)
{
    PtrToNode temp;
    temp = (PtrToNode)malloc( sizeof (struct TreeNode));
    if ( temp != NULL)
        return temp;
    else {
        std::cout << "No space " << std::endl;
        return NULL;
    }
}

// 合并子树，返回更新数组的索引
// 注意 Index 的值
int Merge ( PtrToNode * Arr, int Index)
{
    int i = 0;
    int count = 0;
    int MinWeight = Max, SecondMinWeight = Max;
    PtrToNode MinWeightNode = NULL, SecondMinWeightNode = NULL;
    
    // std::cout << Arr[i]->Weight << "  " << Arr[i]->Element << std::endl;
    // 检测
    while ( count != 1)
    {
        for(i = 0; i < Index; i++)
        {
            if ( Arr[i]->Weight < MinWeight && Arr[i]->Parent == NULL)
            {                                           // 找两个最小的结点
                SecondMinWeight = MinWeight;            // 易错
                SecondMinWeightNode = MinWeightNode;    // 更新结点
                MinWeight = Arr[i]->Weight;
                MinWeightNode = Arr[i];                 //
            } else if ( Arr[i]->Weight < SecondMinWeight && Arr[i]->Parent == NULL) {
                SecondMinWeight = Arr[i]->Weight;
                SecondMinWeightNode = Arr[i];
            }
        }
        
        Arr[Index] = CreateTreeNode();
        Arr[Index]->Weight = MinWeight + SecondMinWeight;
        Arr[Index]->LeftChild = MinWeightNode;
        Arr[Index]->RightChild = SecondMinWeightNode;
        Arr[Index]->Parent = NULL;
        Arr[Index]->Element = '$';                      // 将生成结点的字符初始化为空格
        MinWeightNode->Parent = Arr[Index];
        SecondMinWeightNode->Parent = Arr[Index];
        Index++;
        MinWeight = SecondMinWeight = Max;              // 重置 Max
//      for ( int j = 0; j < Index; j++)
//            std::cout << "Arr[" << j << "]->Element = "<< Arr[j]->Element
//                      << " Arr[" << j << "]->Weight = " << Arr[j]->Weight << std::endl;
        i = 0;                                          // 将 i 置零
        count = 0;
        for ( int j = 0; j < Index; j++)
        {
            if ( Arr[j]->Parent == NULL)                // 之前将 j 写成了 i ，导致程序崩溃，检查半天！！！！！
                count++;
        }
        //std::cout << "count = " << count << std::endl;// 检测
        
    }
    
    return Index;
}

// 使用递归打印哈夫曼树
void PrintHuffmanTree (Root Tree, int Level)
{
    if ( Tree == NULL)
        return;
    std::cout << '|';
    for ( int i = 0; i < Level; i++)
        std::cout << "\t";
    std::cout << Tree->Element << " " << Tree->Weight << std::endl;
    PrintHuffmanTree( Tree->LeftChild, Level + 1);
    PrintHuffmanTree( Tree->RightChild, Level + 1);
}

// 打印哈夫曼树和叶结点的哈夫曼编码
void PrintHuffmanTree2 ( PtrToNode * Arr, const int Index, Root Tree, int Level)
{
    if ( Tree == NULL)
        return;
    std::cout << '|';
    for ( int i = 0; i < Level; i++)
        std::cout << "\t";
    std::cout << Tree->Element << " " << Tree->Weight << " ";
    if ( Tree->Element != '$')
        Code ( Arr, Tree->Element, Index);
    
    std::cout << std::endl;
    PrintHuffmanTree2 ( Arr, Index, Tree->LeftChild, Level + 1);
    PrintHuffmanTree2 ( Arr, Index, Tree->RightChild, Level + 1);

}

// 打印哈夫曼树字符及其对应的01码
void PrintList (PtrToNode * Arr)
{
    Stack S = CreateStack();
    int i = 0;
    while ( Arr[i]->Element != '$')
    {
        PtrToNode temp = Arr[i];
        while (temp->Parent != NULL)
        {
            if ( temp->Parent->LeftChild == temp)
                Push ( '0', S);
            else if ( temp->Parent->RightChild == temp)
                Push ( '1', S);
            temp = temp->Parent;
        }
        
        std::cout << Arr[i]->Element << ": ";
        do {
            std::cout << Top(S);
            Pop(S);
        } while ( !IsEmpty(S));
        
        std::cout << std::endl;
        i++;
    }
    
    DeleteStack (S);
}

// 编码
void Code ( PtrToNode * Arr, ElementType X, int Index)
{
    Stack S;
    S = CreateStack();
    PtrToNode temp = NULL;
    int i = 0;
    for ( i = 0; i < Index; i++)
        if ( Arr[i]->Element == X)
            break;
    
    temp = Arr[i];
    while ( temp->Parent != NULL)
    {
        if ( temp->Parent->LeftChild == temp)
            Push ( '0', S);
        else if ( temp->Parent->RightChild == temp)
            Push ( '1', S);
        temp = temp->Parent;
    }
    
    do {
        std::cout << Top(S);
        Pop(S);
    } while ( !IsEmpty(S));
    
    DeleteStack(S);
}

// 解码，传入根结点
void Decode ( const Root HuffmanTree)                   // HuffmanTree指向的地址不变
{
    char ch = 0;
    int count = 1;
    PtrToNode Temp = HuffmanTree;
    while ( ch!= '\n')
    {
        while ( Temp->RightChild != NULL && (ch = getchar()) != '\n')
        {                                               // 需注意，将 getchar() 作为第二个判断的条件
            // ch = getchar();                          // getchar()该放在哪里是个需要考虑的问题！
            if ( ch == '1')
            {
                Temp = Temp->RightChild;
            } else if ( ch == '0') {
                Temp = Temp->LeftChild;
            }
        }
        if ( count == 1)
            std::cout << "字符串为：" << std::endl;
        count++;
        if ( ch != '\n')                                // 为了防止退出时打印出了根结点里的元素
            std::cout << Temp->Element;

        Temp = HuffmanTree;
    }
    
    std::cout << std::endl;
}



