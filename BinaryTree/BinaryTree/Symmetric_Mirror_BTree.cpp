//
//  MirrorBTree.cpp
//  BinaryTree
//
//  Created by xuwenyong on 15/11/28.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"

bool BTree1IsImageOfBTree2(BTree root1, BTree root2)
{
    if (root1==NULL && root1==NULL)
    {
        return true;
    }
    if ((root1==NULL && root2!=NULL) || (root2==NULL && root1!=NULL) )
    {
        return false;
    }
    if (!(root1->value==root2->value))
    {
        return false;
    }
    return BTree1IsImageOfBTree2(root1->lChild,root2->rChild) && BTree1IsImageOfBTree2(root1->rChild,root2->lChild);
}

bool IsSymmetricBTree(BTree root)
{
    if (root==NULL || (root->lChild==NULL && root->rChild==NULL))
    {
        return true;
    }
    
    return BTree1IsImageOfBTree2(root->lChild, root->rChild);
}