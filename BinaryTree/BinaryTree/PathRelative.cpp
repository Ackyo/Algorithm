//
//  SumOfAllPathFromRoot2Leaf.cpp
//  BinaryTree
//
//  Created by xuwenyong on 15/11/28.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"
#include <stack>
#include <map>
#define MaxLen 1000

using namespace std;

int SumOfAllPathFromRoot2Leaf(BTree root)
{
    int sum=0;
    if (root==NULL)
    {
        return 0;
    }
    if (root->lChild==NULL && root->rChild==NULL)
    {
        //VisitBTNode(root);
        return root->value;
    }
    
    BTNode* ptr=root;
    stack<BTNode*> recursiveStack;
    map<BTNode*,int> visited;
    int currentSum=0;
    
    while (ptr || recursiveStack.empty()==false)
    {
        if (ptr)
        {
            while (ptr)
            {
                recursiveStack.push(ptr);
                currentSum=currentSum*10+ptr->value;
                ptr=ptr->lChild;
            }
        }
        else
        {
            ptr=recursiveStack.top();
            if (ptr->rChild && visited.count(ptr->rChild)<1)
            {
                ptr=ptr->rChild;
            }
            else
            {
                //VisitBTNode(ptr);
                if (ptr->lChild==NULL && ptr->rChild==NULL)
                {
                    sum+=currentSum;
                    //printf("Add current sum: %d\n",currentSum);
                }
                visited[ptr]++;
                currentSum-=ptr->value;
                currentSum/=10;
                recursiveStack.pop();
                ptr=NULL;
            }
        }
    }
    
    return sum;
}

void PrintPath(int* path, int cur)
{
    printf("(");
    for (int i=0; i<cur; ++i)
    {
        printf(" %d ",path[i]);
    }
    puts(")");
}

void PrintAllPathFromRoot2Leaf(BTree root)
{
    if (root==NULL)
    {
        return;
    }
    if (root->lChild==NULL && root->rChild==NULL)
    {
        //VisitBTNode(root);
        printf(" %d ",root->value);
        return;
    }
    
    int path[MaxLen];
    int cur=0;
    
    BTNode* ptr=root;
    stack<BTNode*> recursiveStack;
    map<BTNode*,int> visited;
    
    while (ptr || recursiveStack.empty()==false)
    {
        if (ptr)
        {
            while (ptr)
            {
                recursiveStack.push(ptr);
                path[cur++]=ptr->value;
                ptr=ptr->lChild;
            }
        }
        else
        {
            ptr=recursiveStack.top();
            if (ptr->rChild && visited.count(ptr->rChild)<1)
            {
                ptr=ptr->rChild;
            }
            else
            {
                //VisitBTNode(ptr);
                if (ptr->lChild==NULL && ptr->rChild==NULL)
                {
                    //printf("Add current sum: %d\n",currentSum);
                    PrintPath(path,cur);
                }
                visited[ptr]++;
                recursiveStack.pop();
                --cur;
                ptr=NULL;
            }
        }
    }
    
}