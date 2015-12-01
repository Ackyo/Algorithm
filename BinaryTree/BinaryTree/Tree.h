//
//  Tree.h
//  BinaryTree
//
//  Created by xuwenyong on 15/11/23.
//  Copyright © 2015年 Ack. All rights reserved.
//

#ifndef Tree_h
#define Tree_h


#endif /* Tree_h */

typedef int ElemType;

typedef struct BTNode
{
    ElemType value;
    BTNode* lChild;
    BTNode* rChild;
    
}BTNode,*BTree;


//typedef struct DLNode
//{
//    ElemType value;
//    DLNode* prior;
//    DLNode* next;
//}DLNode,*DLinkList;

BTree CreateBTreeFromArray(int* nums, int len);

int GetHeightOfBTree(BTree root);
int CountBTreeNodes(BTree root);

/*
 *Get the Nodes at Level h, include the count of node at that level
 */
void PrintLevelH(BTree root, int h);
void PrintEachLevel(BTree root);
int CountBTreeNodeAtLevelH(BTree root, int h);

void VisitBTNode(BTNode* bt);
void PreOrderBTreeRecursively(BTree root);
void PreOrderBTreeNonRecursion(BTree root);

void InOrderBTreeRecursively(BTree root);
void InOrderBTreeNonRecursion(BTree root);

void PostOrderBTreeRecursively(BTree root);
void PostOrderBTreeNonRecursion(BTree root);

void LevelOrderBTree(BTree root);

int SumOfAllPathFromRoot2Leaf(BTree root);
void PrintPath(int* path, int cur);
void PrintAllPathFromRoot2Leaf(BTree root);

bool IsBalancedBTree(BTree root);

bool IsBSortTree(BTree root, int min, int max);
bool IsBinarySortTree(BTree root);

bool BTree1SymmetricWithBTree2(BTree root1, BTree root2);
bool IsSymmetricBTree(BTree root);

bool IsCompleteBinaryTree(BTree root);

bool IsFullBinaryTree(BTree root);

BTree BinarySortTree2SortedDoubleLinkList(BTree root);