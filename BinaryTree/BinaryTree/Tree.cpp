//
//  Tree.cpp
//  BinaryTree
//
//  Created by xuwenyong on 15/11/28.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"

BTree CreateBTreeFromArray(ElemType* nums, int len)
{
    BTNode** tree=new BTNode*[len];
    for (int i=0; i<len; ++i)
    {
        if (nums[i]!=-1)
        {
            tree[i]=new BTNode();
            tree[i]->value=nums[i];
        }
        else
        {
            tree[i]=NULL;
        }
    }
    for (int i=0; i<len; ++i)
    {
        if (tree[i])
        {
            if (2*i+1<len)
            {
                tree[i]->lChild=tree[2*i+1];
            }
            else
            {
                tree[i]->lChild=NULL;
            }
            if (2*i+2<len)
            {
                tree[i]->rChild=tree[2*i+2];
            }
            else
            {
                tree[i]->rChild=NULL;
            }
        }
    }
    
    return tree[0];
}

int GetHeightOfBTree(BTree root)
{
    if (root==NULL)
    {
        return 0;
    }
    int leftH=GetHeightOfBTree(root->lChild);
    int rightH=GetHeightOfBTree(root->rChild);
    return 1+(leftH>rightH?leftH:rightH);
}

int CountBTreeNodes(BTree root)
{
    if (root==NULL)
    {
        return 0;
    }
    return CountBTreeNodes(root->lChild)+CountBTreeNodes(root->rChild)+1;
}


