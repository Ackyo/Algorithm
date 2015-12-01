//
//  FullBinaryTree.cpp
//  BinaryTree
//
//  Created by xuwenyong on 15/11/29.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"
#include <queue>

using namespace std;


bool IsFullBinaryTree(BTree root)
{
    if (root==NULL || (root->lChild==NULL && root->rChild==NULL))
    {
        return true;
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
//        printf("Level %d: ",level);
        
        while (nodesCountOfLastLevel)
        {
            --nodesCountOfLastLevel;
            ptr=levelQueue.front();
//            printf(" %d ",ptr->value);
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
        //puts("");
        nodesCountOfLastLevel=nodesCountOfCurrentLevel;
        ++level;
        if (nodesCountOfCurrentLevel && nodesCountOfCurrentLevel < (1<<(level-1)))
        {
            printf("Level %d just have %d nodes\n",level,nodesCountOfCurrentLevel);
            return false;
        }
    }
    
    
    return true;
}