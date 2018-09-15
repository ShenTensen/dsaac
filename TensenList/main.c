//
//  main.c
//  TensenList
//
//  Created by ShenTensen on 15/12/28.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//  1. 打印单链表所有元素

#include <stdio.h>
#include "TensenList.h"


int main(void)
{
    List l = CreateList();
    
    for (int i = 0; i < 10; i++)
        Insert(i, l->Next);
    
    
    

    
    return 0;
}
