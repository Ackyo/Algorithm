//
//  BinaryTree-LinkList.cpp
//  BinaryTree
//
//  Created by xuwenyong on 15/11/29.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"
#include <stack>

using namespace std;

BTree BinarySortTree2SortedDoubleLinkList(BTree root)
{
    if (root==NULL || (root->lChild==NULL && root->rChild==NULL))
    {
        return root;
    }
    BTNode* pHead=root;
    stack<BTNode* > recursiveStack;
    
    while (pHead->lChild)
    {
        pHead=pHead->lChild;
    }
    
    BTNode* ptr=root;
    BTNode* prior=NULL;
    BTNode* currentPtr;
    
    while (ptr || recursiveStack.empty()==false)
    {
        if (ptr)
        {
            recursiveStack.push(ptr);
            ptr=ptr->lChild;
        }
        else
        {
            ptr=recursiveStack.top();
            currentPtr=ptr;
            recursiveStack.pop();
            ptr=ptr->rChild;
            
            if (prior)
            {
                prior->rChild=currentPtr;
            }
            currentPtr->lChild=prior;
            prior=currentPtr;
        }
    }
    prior->rChild=NULL;
    
    return pHead;
}