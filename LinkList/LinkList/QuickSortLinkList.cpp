//
//  QuickSortLinkList.cpp
//  LinkList
//
//  Created by xuwenyong on 15/11/28.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include "List.h"
#include <stdio.h>

void QuickSortLinkList(LinkList pHead)
{
    if (pHead==NULL)
    {
        return;
    }
    LNode* pTail=pHead;
    while (pTail->next)
    {
        pTail=pTail->next;
    }
    QuickSortCore(pHead,pTail);
}

LNode* FindPrior(LinkList pHead, LNode* ptr)
{
    if (pHead==NULL || pHead==ptr)
    {
        return NULL;
    }
    LNode* priorPtr=pHead;
    while (priorPtr->next && priorPtr->next!=ptr)
    {
        priorPtr=priorPtr->next;
    }
    if (priorPtr->next==ptr)
    {
        return priorPtr;
    }
    return NULL;
}

void SwapLinkListValue(LNode* p,LNode* q)
{
    int temp=p->value;
    p->value=q->value;
    q->value=temp;
}

LNode* PartitionLinkList(LinkList pHead, LNode* pTail)
{
    LNode* pPivot=pHead;
    LNode* start=pHead;
    LNode* end=pTail;
    
    while (start<end)
    {
        while (start<end && end->value>=pPivot->value)
        {
            end=FindPrior(pHead, end);
        }
        SwapLinkListValue(pPivot,end);
        pPivot=end;
        while (start<end && start->value<pPivot->value)
        {
            start=start->next;
        }
        SwapLinkListValue(pPivot, start);
        pPivot=start;
    }
    
    return pPivot;
}

void QuickSortCore(LinkList pHead, LNode* pTail)
{
    if (pHead<pTail)
    {
        LNode* pPivot=PartitionLinkList(pHead, pTail);
        QuickSortCore(pHead, FindPrior(pHead,pPivot));
        QuickSortCore(pPivot->next, pTail);
    }
}