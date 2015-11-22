//
//  RemoveDuplicatedElemFromUnsortedLinkList.cpp
//  LinkList
//
//  Created by xuwenyong on 15/11/22.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include "List.h"
#include <iostream>
#include <map>

using namespace std;

void RemoveDuplicatedElemFromUnsortedLinkList(LinkList pHead)
{
    if (pHead==NULL)
    {
        return;
    }
    
    map<Elemtype,int> m;
    LNode* pCurrent=pHead;
    m[pHead->value]++;
    LNode* pToBeDeleted=NULL;
    while (pCurrent->next!=NULL)
    {
        if (m.count(pCurrent->next->value)>0)
        {
            pToBeDeleted=pCurrent->next;
            pCurrent->next=pCurrent->next->next;
            delete pToBeDeleted;
        }
        else
        {
            m[pCurrent->next->value]++;
            pCurrent=pCurrent->next;
        }
    }
    
}
