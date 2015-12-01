//
//  LevelRelative.cpp
//  BinaryTree
//
//  Created by xuwenyong on 15/11/29.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"
#include <queue>

using namespace std;

int CountBTreeNodeAtLevelH(BTree root, int h)
{
    if (root==NULL )
    {
        return 0;
    }
    //refer to method PrintLevelH
    
    return 0;
}

void PrintEachLevel(BTree root)
{
    if (root==NULL)
    {
        return;
    }
    if (root->lChild==NULL && root->rChild==NULL)
    {
        printf("Just one Level: %d\n",root->value);
        //VisitBTNode(root);
        return;
    }
    
    BTNode* ptr=root;
    queue<BTNode* > levelQueue;
    levelQueue.push(root);
    
    int nodesCountOfLastLevel=1;
    int nodesCountOfCurrentLevel=0;
    int level=1;
    
    while (levelQueue.empty()==false)
    {
        nodesCountOfCurrentLevel=0;
        printf("Level %d: ",level);
        
        while (nodesCountOfLastLevel)
        {
            --nodesCountOfLastLevel;
            ptr=levelQueue.front();
            printf(" %d ",ptr->value);
            //VisitBTNode(ptr);
            levelQueue.pop();
            
            if (ptr->lChild)
            {
                levelQueue.push(ptr->lChild);
                nodesCountOfCurrentLevel++;
            }
            if (ptr->rChild)
            {
                levelQueue.push(ptr->rChild);
                nodesCountOfCurrentLevel++;
            }
        }
        puts("");
        nodesCountOfLastLevel=nodesCountOfCurrentLevel;
        ++level;
    }
}

void PrintLevelH(BTree root, int h)
{
    if (root==NULL)
    {
        return;
    }
    if (root->lChild==NULL && root->rChild==NULL)
    {
        printf("Just one Level: %d\n",root->value);
        //VisitBTNode(root);
        return;
    }
    
    BTNode* ptr=root;
    queue<BTNode* > levelQueue;
    levelQueue.push(root);
    
    int nodesCountOfLastLevel=1;
    int nodesCountOfCurrentLevel=0;
    int level=1;
    
    while (levelQueue.empty()==false)
    {
        nodesCountOfCurrentLevel=0;
        if (level==h)
        {
            printf("Level %d: ",level);
        }
        //printf("Level %d: ",level);
        
        while (nodesCountOfLastLevel)
        {
            --nodesCountOfLastLevel;
            ptr=levelQueue.front();
            if (level==h)
            {
                printf(" %d ",ptr->value);
            }
            //printf(" %d ",ptr->value);
            //VisitBTNode(ptr);
            levelQueue.pop();
            
            if (ptr->lChild)
            {
                levelQueue.push(ptr->lChild);
                nodesCountOfCurrentLevel++;
            }
            if (ptr->rChild)
            {
                levelQueue.push(ptr->rChild);
                nodesCountOfCurrentLevel++;
            }
        }
        puts("");
        nodesCountOfLastLevel=nodesCountOfCurrentLevel;
        ++level;
        if (level>h)
        {
            break;
        }
    }
}

