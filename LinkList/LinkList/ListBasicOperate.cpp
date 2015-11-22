//
//  List.cpp
//  LinkList
//
//  Created by xuwenyong on 15/11/22.
//  Copyright © 2015年 Ack. All rights reserved.
//
#include "List.h"
#include <stdio.h>

LNode* CreateListNode(Elemtype value)
{
    LNode* nodePtr=new LNode();
    nodePtr->value=value;
    nodePtr->next=NULL;
    return nodePtr;
}

void ConnectListNode(LNode* ptrCurrent, LNode* ptrNext)
{
    if (ptrCurrent==NULL)
    {
        puts("Error to connect two nodes.");
        return;
    }
    ptrCurrent->next=ptrNext;
}

LinkList CreateLinkListFromInput(int count)
{
    if (count<1)
    {
        return NULL;
    }
    LinkList pHead=NULL;
    int value;
    scanf("%d",&value);
    pHead=CreateListNode(value);
    for(int i=1;i<count;++i)
    {
        scanf("%d",&value);
        AddToTail(&pHead,value);
    }
    return pHead;
}

LinkList CreateLinkListFromArray(Elemtype* data, int len)
{
    if (data==NULL || len<1)
    {
        return NULL;
    }
    LinkList pHead=NULL;
    pHead=CreateListNode(data[0]);
    for (int  i=1; i<len; ++i)
    {
        AddToTail(&pHead,data[i]);
    }
    return pHead;
}

void PrintListNode(LNode* pNode)
{
    if(pNode == NULL)
    {
        printf("The node is NULL\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->value);
    }
}

void PrintLinkList(LinkList pHead)
{
    if (pHead==NULL)
    {
        puts("NULL LinkList");
        return;
    }
    LNode* ptrNode=pHead;
    while (ptrNode)
    {
        printf("%d->",ptrNode->value);
        ptrNode=ptrNode->next;
    }
    puts("NULL");
}

void DestroyLinkList(LinkList* pHead)
{
    LNode* pNode=*pHead;
    while ((*pHead)!=NULL)
    {
        *pHead=(*pHead)->next;
        delete pNode;
        pNode=*pHead;
    }
}

void AddToTail(LinkList* pHead, Elemtype value)
{
    //pass the head as second rank pointer in case of change the head pointer of the LinkList
    LNode* pNewNode=new LNode();
    pNewNode->value=value;
    pNewNode->next=NULL;
    if (*pHead==NULL)
    {
        *pHead=pNewNode;
        return;
    }
    LNode* pTail=*pHead;
    while (pTail->next!=NULL)
    {
        pTail=pTail->next;
    }
    pTail->next=pNewNode;
}

void RemoveListNode(LinkList* pHead, Elemtype value)
{
    if (pHead==NULL || *pHead==NULL)
    {
        return;
    }
    
    LNode* pToBeDeleted=NULL;
    
    while ((*pHead) && (*pHead)->value==value)
    {
        pToBeDeleted=*pHead;
        *pHead=(*pHead)->next;
        delete pToBeDeleted;
    }
    
    if (*pHead==NULL)
    {
        return;
    }
    LNode* pCurrent=*pHead;
    
    while (pCurrent->next!=NULL)
    {
        if (pCurrent->next->value==value)
        {
            pToBeDeleted=pCurrent->next;
            pCurrent->next=pCurrent->next->next;
            delete pToBeDeleted;
        }
        else
        {
            pCurrent=pCurrent->next;
        }
    }
//    if (pToBeDeleted!=NULL)
//    {
//        delete pToBeDeleted;
//        pToBeDeleted=NULL;
//    }
}

int GetLinkListLength(LinkList pHead)
{
    if (pHead==NULL)
    {
        return 0;
    }
    int len=0;
    LNode* pNode=pHead;
    while (pNode!=NULL)
    {
        len++;
        pNode=pNode->next;
    }
    return len;
}

