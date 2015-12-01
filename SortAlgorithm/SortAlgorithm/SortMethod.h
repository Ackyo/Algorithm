//
//  SortMethod.h
//  SortAlgorithm
//
//  Created by xuwenyong on 15/11/23.
//  Copyright © 2015年 Ack. All rights reserved.
//

#ifndef SortMethod_h
#define SortMethod_h


#endif /* SortMethod_h */

void PrintArray(int* nums, int len);
void CopyArray(int* src, int len, int* dest);
void Swap(int* p, int* q);

void BubbleSort(int* nums, int len);

int Partition(int* nums, int start, int end);
void QuickSorCore(int *nums, int start, int end);
void QuickSort(int* nums, int len);

void InsertSort(int* nums, int len);

void BinaryInsertSort(int* nums, int len);

void ShellSort(int* nums, int len);

void SelectSort(int* nums, int len);

void AdjustBigRootHeap(int* nums, int start, int end);
void BuildBigRootHeap(int* nums, int len);
void HeapSort(int* nums, int len);

void Merge(int* nums, int start, int mid, int end);
void MergeSortCore(int* nums, int start, int end);
void MergeSort(int* nums, int len);

