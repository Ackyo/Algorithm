//
//  BinarySortTree.cpp
//  BinaryTree
//
//  Created by xuwenyong on 15/11/28.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"

bool IsBSortTree(BTree root, int min, int max)
{
    if (root==NULL)
    {
        return true;
    }

    if (root->lChild)
    {
        if (!(root->lChild->value<=root->value && root->lChild->value>min))
        {
            return false;
        }
    }
    if (root->rChild)
    {
        if(!(root->rChild->value>root->value && root->rChild->value<=max))
        {
            return false;
        }
    }
    
    return IsBSortTree(root->lChild, min, root->value) && IsBSortTree(root->rChild, root->value, max);
}

bool IsBinarySortTree(BTree root)
{
    
    return IsBSortTree(root, 0x8fffffff, 0x7fffffff);
}

