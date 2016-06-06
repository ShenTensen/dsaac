//
//  TensenList.h
//  TensenList
//
//  Created by ShenTensen on 15/12/28.
//  Copyright © 2015年 ShenTensen. All rights reserved.
//

#ifndef TensenList_h
#define TensenList_h

#include <stdio.h>
#include <stdlib.h>

#define ElementType char

struct Node;
typedef struct Node * Pnode;
typedef struct Node * List;
typedef Pnode Position;

List CreateList (void);
List MakeEmpty (List L);
void Insert (ElementType Elem, Position P);
void PrintList (List L);
void DeleteList (List L);





#endif /* TensenList_h */
