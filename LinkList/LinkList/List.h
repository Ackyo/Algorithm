//
//  List.h
//  LinkList
//
//  Created by xuwenyong on 15/11/22.
//  Copyright © 2015年 Ack. All rights reserved.
//

typedef int Elemtype;

typedef struct LNode
{
    Elemtype value;
    struct LNode* next;
}LNode,*LinkList;


LNode* CreateListNode(Elemtype value);
void ConnectListNode(LNode* ptrCurrent, LNode* ptrNext);
LinkList CreateLinkListFromInput(int count);
LinkList CreateLinkListFromArray(Elemtype* data, int len);
void PrintListNode(LNode* pNode);
void PrintLinkList(LinkList pHead);
void AddToTail(LinkList* pHead, Elemtype value);
void RemoveListNode(LinkList* pHead, Elemtype value);
int GetLinkListLength(LinkList pHead);
void DestroyLinkList(LinkList* pHead);

void RemoveDuplicatedElemFromUnsortedLinkList(LinkList pHead);
