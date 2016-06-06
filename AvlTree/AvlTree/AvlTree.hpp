//
//  AVLTree.hpp
//  AvlTree
//
//  Created by ShenTensen on 15/12/1.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//

#ifndef AvlTree_hpp
#define AvlTree_hpp

// 指定结点里存储元素的类型
#define ElementType int
//using ElementType = int;


struct AvlNode;
typedef struct AvlNode * Position;      // 即使 avlNode 之前没有 struct 也可以通过编译，why？！
typedef struct AvlNode * AvlTree;

AvlTree Insert (ElementType X, AvlTree Tree);
void PrintAvlTree (AvlTree Tree, int Level);



#endif /* AVLTree_hpp */
