//
//  main.cpp
//  LinkList
//
//  Created by xuwenyong on 15/11/22.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <iostream>
#include "List.h"

using namespace std;

void Test(LinkList* pHead,int value)
{
    printf("The original list is: \n");
    PrintLinkList(*pHead);
    printf("Length = %d\n",GetLinkListLength(*pHead));
    printf("After RemoveListNode(pHead,%d):\n",value);
    RemoveDuplicatedElemFromUnsortedLinkList(*pHead);
    printf("Length = %d\n",GetLinkListLength(*pHead));
    PrintLinkList(*pHead);
}

void Test1()
{
    LinkList pNode1 = CreateLinkListFromInput(4);
    
    Test(&pNode1, 3);
    
    DestroyLinkList(&pNode1);
}

void Test2()
{
    int data[]={3,2,3,4,5};
    LinkList pNode1 = CreateLinkListFromArray(data, sizeof(data)/sizeof(int));
    
    Test(&pNode1, 3);
    
    DestroyLinkList(&pNode1);
}

void Test3()
{
    LinkList pNode1 = CreateListNode(3);
    LinkList pNode2 = CreateListNode(3);
    LinkList pNode3 = CreateListNode(3);
    LinkList pNode4 = CreateListNode(3);
    LinkList pNode5 = CreateListNode(3);
    
    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);
    
    Test(&pNode1, 3);
    
    DestroyLinkList(&pNode1);
}

void Test4()
{
    LinkList pNode1 = CreateListNode(3);
    
    Test(&pNode1, 3);
    DestroyLinkList(&pNode1);
}

void Test5()
{
    LinkList pNode1 = NULL;
    Test(&pNode1, 3);
}


int main(int argc, const char * argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}
