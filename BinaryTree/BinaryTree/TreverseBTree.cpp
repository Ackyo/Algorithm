//
//  TreverseBTree.cpp
//  BinaryTree
//
//  Created by xuwenyong on 15/11/28.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"
#include <stack>
#include <queue>
#include <map>

using namespace std;

void VisitBTNode(BTNode* bt)
{
    printf(" %d ",bt->value);
}

void PreOrderBTreeRecursively(BTree root)
{
    if (root)
    {
        VisitBTNode(root);
        PreOrderBTreeRecursively(root->lChild);
        PreOrderBTreeRecursively(root->rChild);
    }
}

void PreOrderBTreeNonRecursion(BTree root)
{
    if (root==NULL)
    {
        return;
    }
    if (root->lChild==NULL && root->rChild==NULL)
    {
        VisitBTNode(root);
        return;
    }
    BTNode* ptr=root;
    stack<BTNode*> visitedStack;
    
    while (ptr || visitedStack.empty()==false)
    {
        if (ptr)
        {
            while (ptr)
            {
                visitedStack.push(ptr);
                VisitBTNode(ptr);
                ptr=ptr->lChild;
            }
        }
        else
        {
            ptr=visitedStack.top();
            visitedStack.pop();
            ptr=ptr->rChild;
        }
    }
}

void InOrderBTreeRecursively(BTree root)
{
    if (root)
    {
        InOrderBTreeRecursively(root->lChild);
        VisitBTNode(root);
        InOrderBTreeRecursively(root->rChild);
    }
}

void InOrderBTreeNonRecursion(BTree root)
{
    if (root==NULL)
    {
        return;
    }
    if (root->lChild==NULL && root->rChild==NULL)
    {
        VisitBTNode(root);
        return;
    }
    BTNode* ptr=root;
    stack<BTNode*> recursiveStack;
    
    while (ptr || recursiveStack.empty()==false)
    {
        if (ptr)
        {
            while (ptr)
            {
                recursiveStack.push(ptr);
                ptr=ptr->lChild;
            }
        }
        else
        {
            ptr=recursiveStack.top();
            VisitBTNode(ptr);
            recursiveStack.pop();
            ptr=ptr->rChild;
        }
    }
}

void PostOrderBTreeRecursively(BTree root)
{
    if (root)
    {
        PostOrderBTreeRecursively(root->lChild);
        PostOrderBTreeRecursively(root->rChild);
        VisitBTNode(root);
    }
}

void PostOrderBTreeNonRecursion(BTree root)
{
    if (root==NULL)
    {
        return;
    }
    if (root->lChild==NULL && root->rChild==NULL)
    {
        VisitBTNode(root);
        return;
    }
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
                VisitBTNode(ptr);
                visited[ptr]++;
                recursiveStack.pop();
                ptr=NULL;
            }
        }
    }
}

void LevelOrderBTree(BTree root)
{
    if (root==NULL)
    {
        return;
    }
    if (root->lChild==NULL && root->rChild==NULL)
    {
        VisitBTNode(root);
        return;
    }
    BTNode* ptr=root;
    queue<BTNode* > levelQueue;
    levelQueue.push(root);
    
    while (levelQueue.empty()==false)
    {
        ptr=levelQueue.front();
        VisitBTNode(ptr);
        levelQueue.pop();
        
        if (ptr->lChild)
        {
            levelQueue.push(ptr->lChild);
        }
        if (ptr->rChild)
        {
            levelQueue.push(ptr->rChild);
        }
    }
}
