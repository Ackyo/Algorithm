//
//  main.cpp
//  SortAlgorithm
//
//  Created by xuwenyong on 15/11/23.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <iostream>
#include "SortMethod.h"

void OutPutSortResult(int* result, int len, int* expected)
{
    bool res=true;
    printf(" ");
    for (int i=0; i<len; ++i)
    {
        if (result[i]!=expected[i])
        {
            res=false;
            printf(" ↑ ");
        }
        else
        {
            printf("   ");
        }
    }
    
    if (res==false)
    {
        puts("\n!!!!!!!!!!!!  Wrong Result!!!!!!!!!!!!\n");
    }
    else
    {
        puts("\nRight\n");
    }
}

void Test(char* testName, int* nums, int len, int* expected)
{
    int* copyArray=new int[len];
    
    puts(testName);
    puts("source data:");
    PrintArray(nums, len);
    
    CopyArray(nums,len,copyArray);
    puts("BubbleSortResult:");
    BubbleSort(copyArray,len);
    PrintArray(copyArray, len);
    OutPutSortResult(copyArray,len,expected);
    
    CopyArray(nums,len,copyArray);
    puts("QuickSortResult:");
    QuickSort(copyArray,len);
    PrintArray(copyArray, len);
    OutPutSortResult(copyArray,len,expected);
    
    CopyArray(nums,len,copyArray);
    puts("InsertSortResult:");
    InsertSort(copyArray,len);
    PrintArray(copyArray, len);
    OutPutSortResult(copyArray,len,expected);
    
    CopyArray(nums,len,copyArray);
    puts("BinaryInsertSortResult:");
    BinaryInsertSort(copyArray,len);
    PrintArray(copyArray, len);
    OutPutSortResult(copyArray,len,expected);
    
    CopyArray(nums,len,copyArray);
    puts("ShellSortResult:");
    ShellSort(copyArray,len);
    PrintArray(copyArray, len);
    OutPutSortResult(copyArray,len,expected);
    
    CopyArray(nums,len,copyArray);
    puts("SelectSortResult:");
    SelectSort(copyArray,len);
    PrintArray(copyArray, len);
    OutPutSortResult(copyArray,len,expected);
    
    CopyArray(nums,len,copyArray);
    puts("HeapSortResult:");
    HeapSort(copyArray,len);
    PrintArray(copyArray, len);
    OutPutSortResult(copyArray,len,expected);
    
    CopyArray(nums,len,copyArray);
    puts("MergeSortResult:");
    MergeSort(copyArray,len);
    PrintArray(copyArray, len);
    OutPutSortResult(copyArray,len,expected);
    
    delete[] copyArray;
}

void Test1()
{
    int nums[]={};
    int expected[]={};
    Test("Test1",nums,sizeof(nums)/sizeof(int),expected);
}

void Test2()
{
    int nums[]={1, 6, 3, 4, 9, 2, 5, 3, 4, 3};
    int expected[]={1, 2, 3, 3, 3, 4, 4, 5, 6, 9};
    Test("Test2",nums,sizeof(nums)/sizeof(int),expected);
}

void Test3()
{
    int nums[]={10, 9, 5, 6, 9, 4, 2, 5, 7, 8, 9, 3, 11, 9, 3, 4, 7, 8, 5, 1};
    int expected[]={1, 2,  3,  3,  4,  4,  5,  5,  5,  6,  7,  7,  8,  8,  9,  9,  9,  9,  10,  11};
    Test("Test3",nums,sizeof(nums)/sizeof(int),expected);
}


int main(int argc, const char * argv[])
{
    Test1();
    Test2();
    Test3();
    return 0;
}
