//
//  main.cpp
//  AvlTree
//
//  Created by ShenTensen on 15/12/1.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//  AVL树的一个实现

#include <iostream>
#include "AvlTree.hpp"
using namespace std;

int main()
{
    int elem = 0, count = 1;
    AvlTree avltree = NULL;
    
    // 遇到 EOF 结束输入，本该按要求以 '\n' 作为结束
    cout << "Input an interger: ";
    while (cin >> elem)
    {
        // 插入和平衡
        avltree = Insert(elem, avltree);
        // 打印
        cout << "============== AVL Tree " << count++ << " =============" << endl;
        PrintAvlTree(avltree, 0);
        // 输入下一个数
        cout << "Input an interger(ctrl+z to quit): ";
    }
    
    cout << "Bye!" << endl;
    
    return 0;
}
