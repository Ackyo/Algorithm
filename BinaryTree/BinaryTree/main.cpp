//
//  main.cpp
//  BinaryTree
//
//  Created by xuwenyong on 15/11/23.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <iostream>
#include "Tree.h"
using namespace std;

void PrintDLinkList(BTree pHead)
{
    if (pHead==NULL )
    {
        puts("NULL Tree");
        return;
    }
    printf("NULL--");
    while (pHead)
    {
        printf("%d--",pHead->value);
        pHead=pHead->rChild;
    }
    puts("NULL");
}

void Test(const char* testName, BTree root)
{
    printf("\n--------------------------------------\n");
    puts(testName);
    
//    printf("GetHeightOfBTree: %d\n",GetHeightOfBTree(root));
//    
//    puts("PreOrder:");
//    PreOrderBTreeRecursively(root);
//    puts("");
//    
//    puts("PreOrder Non Recursion:");
//    PreOrderBTreeNonRecursion(root);
//    puts("");
//    
//    puts("InOrder:");
//    InOrderBTreeRecursively(root);
//    puts("");
//
//    puts("InOrder Non Recursion:");
//    InOrderBTreeNonRecursion(root);
//    puts("");
//
//    puts("PostOrder:");
//    PostOrderBTreeRecursively(root);
//    puts("");
//
//    puts("PostOrder Non Recursion:");
//    PostOrderBTreeNonRecursion(root);
//    puts("");

    puts("LevelOrderBTree:");
    LevelOrderBTree(root);
//    printf("\n CountBTreeNodes: %d",CountBTreeNodes(root));
//    puts("");
//    printf("SumOfAllPathFromRoot2Leaf: %d",SumOfAllPathFromRoot2Leaf(
    
    //printf("\nIsBinarySortTree: %d\n",IsBinarySortTree(root));
    puts("");
//    PrintAllPathFromRoot2Leaf(root);
//    printf("IsSymmetricBTree: %d\n",IsSymmetricBTree(root));
    
//    BTree sortedDLinkList=BinarySortTree2SortedDoubleLinkList(root);
//    PrintDLinkList(sortedDLinkList);
    PrintEachLevel(root);
    //PrintLevelH(root,3);
    printf("IsFullBinaryTree: %d\n",IsFullBinaryTree(root));
    printf("\n");
}

void Test1()
{
    BTree root=NULL;
    Test("NULL Binary Tree:", root);
}

void Test2()
{
    BTree root=new BTNode();
    root->value=9;
    root->lChild=NULL;
    root->rChild=NULL;
    Test("Binary Tree with One Node:", root);
}

void Test3()
{
    int nums[]={6,4,7,2,6,-1,10,-1,4,-1,-1,-1,-1,9,13,-1,-1,2,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,14};
    BTree root=CreateBTreeFromArray(nums, sizeof(nums)/sizeof(int));
    Test("Normal Binary Tree Test:", root);
}

void Test4()
{
    int nums[]={6,4,7,2,5,-1,10,-1,4,-1,-1,-1,-1,8,-1,-1,-1,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,-1,-1};
    BTree root=CreateBTreeFromArray(nums, sizeof(nums)/sizeof(int));
    Test("Binary Sorted Tree Test:", root);
}

void Test5()
{
    int nums[]={1,3,3,4,2,2,4,7,-1,-1,-1,-1,-1,-1,7};
    BTree root=CreateBTreeFromArray(nums, sizeof(nums)/sizeof(int));
    Test("Mirror Tree Test:", root);
}

void Test6()
{
    int nums[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    BTree root=CreateBTreeFromArray(nums, sizeof(nums)/sizeof(int));
    Test("Full Tree Test:", root);
}

int main(int argc, const char * argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    return 0;
}
