//
//  main.cpp
//  HuffmanTree
//
//  Created by ShenTensen on 15/10/27.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//

#include <iostream>
#include <string>
#include "HuffmanTree.h"
const int N = 40;
using namespace std;

int main ()
{
    PtrToNode array[N];

    char ch;
    int temp = 0;
    int i = 0;
    cout << "输入字符：";                           // input
    while ( (ch = getchar()) != '\n' && i < N/2)
    {
        array[i] = CreateTreeNode();
        array[i]->Element = ch;
        cout << "输入权值：";
        cin >> temp;
        array[i]->Weight = temp;
        array[i]->Parent = NULL;
        array[i]->LeftChild = NULL;
        array[i]->RightChild = NULL;
        i++;
        while ( (ch = getchar()) != '\n')
            continue;
        cout << "输入字符（换行符退出）：";
    }
    
    //检测，看看内部
//    for ( int j = 0; j < i; j++)
//        cout << array[j]->Element << " " << array[j]->Weight << endl;
    
    // 构造哈夫曼树，一直选取两个结点，直至只剩一个结点没有父结点
    i = Merge( array, i);
    
    // 打印哈夫曼树
    cout << "============ 打印哈夫曼树 ===========" << endl;
   // PrintHuffmanTree( array[i - 1], 0);
    // 打印有哈夫曼编码的哈夫曼树
    PrintHuffmanTree2 ( array, i, array[i - 1], 0);
    
    // 打印哈夫曼树里的叶结点字符及其对应01码
    cout << "=========== 哈夫曼树编码表 ===========" << endl;
    PrintList( array);

    // 编码
    cout << "=============== 编码 ===============" << endl;
    cout << "输入字符串：" << endl;
    int j = 0;
    while ( (ch = getchar()) != '\n')
    {
        if (j == 0)
            cout << "哈夫曼编码为：" << endl;
        j++;
        Code ( array, ch, i);
    }
    cout << endl;
    
    
    // 解码
    cout << "=============== 解码 ===============" << endl;
    cout << "输入哈夫曼编码：" << endl;
    Decode ( array[i - 1]);
    
    cout << "Good Bye!" << endl;
    
    return 0;
}
