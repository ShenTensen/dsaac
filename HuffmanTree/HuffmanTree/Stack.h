//
//  Stack.hpp
//  HuffmanTree
//
//  Created by ShenTensen on 15/11/6.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.h"
#define ElementType1 char
struct Node;                    //声明结点
typedef struct Node * Pnode;    //指向结点的指针
typedef Pnode Stack;            //指向头结点的指针

// 但恐破坏了ADT的封装特性
// 定义结点，为何要放在这里，放到实现文件里不是一样吗？？！！
//struct Node {
//    ElementType Element;
//    Pnode Next;
//};
//
Stack CreateStack (void);
void Push (ElementType1 X, Stack S);
ElementType1 Top (Stack S);
void Pop (Stack S);
int IsEmpty (Stack S);
void DeleteStack (Stack S);






#endif /* Stack_hpp */
