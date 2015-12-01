//
//  MergeSortLinkList.cpp
//  LinkList
//
//  Created by xuwenyong on 15/11/23.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include "List.h"
#include <stdio.h>

LinkList DivideTo2LinkList(LinkList pHead)
{
    LinkList pHead2;
    if (pHead==NULL || pHead->next==NULL)
    {
        pHead2=NULL;
        return pHead2;
    }
    
    LNode* slowPtr=pHead;
    LNode* quickPtr=pHead;
    while (quickPtr)
    {
        quickPtr=quickPtr->next;
        if (quickPtr)
        {
            quickPtr=quickPtr->next;
        }
        if (quickPtr)
        {
            slowPtr=slowPtr->next;;
        }
    }
    
    pHead2=slowPtr->next;
    slowPtr->next=NULL;
    
    return pHead2;
}

LinkList Merge(LinkList pHead1, LinkList pHead2)
{
    
    if (pHead1==NULL)
    {
        return pHead2;
    }
    if(pHead2==NULL)
    {
        return pHead1;
    }
    
    LNode* ptr1=pHead1;
    LNode* ptr2=pHead2;
    LNode* ptrSortedTail;
    LinkList sortedpHead;
    
    if (pHead1->value<pHead2->value)
    {
        sortedpHead=pHead1;
        ptr1=ptr1->next;
    }
    else
    {
        sortedpHead=pHead2;
        ptr2=ptr2->next;
    }
    
    ptrSortedTail=sortedpHead;
    
    while (ptr1 && ptr2)
    {
        if (ptr1->value<=ptr2->value)
        {
            ptrSortedTail->next=ptr1;
            ptrSortedTail=ptr1;
            ptr1=ptr1->next;
            
        }
        else
        {
            ptrSortedTail->next=ptr2;
            ptrSortedTail=ptr2;
            ptr2=ptr2->next;
        }
    }
    
    if (ptr1)
    {
        ptrSortedTail->next=ptr1;
    }
    
    if (ptr2)
    {
        ptrSortedTail->next=ptr2;
    }
    
    return sortedpHead;
}

void MergeSortLinkList(LinkList* ppHead)
{
    if (ppHead && (*ppHead) && (*ppHead)->next)
    {
        puts("Origianl LinkList: ");
        PrintLinkList(*ppHead);
        LinkList pHead1=*ppHead;
        LinkList pHead2=DivideTo2LinkList(pHead1);
        puts("After Divide:");
        puts("pHead1");
        PrintLinkList(pHead1);
        puts("pHead2");
        PrintLinkList(pHead2);
        MergeSortLinkList(&pHead1);
        MergeSortLinkList(&pHead2);
        *ppHead=Merge(pHead1, pHead2);
        
    }
}