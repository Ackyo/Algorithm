//
//  SortMethod.cpp
//  SortAlgorithm
//
//  Created by xuwenyong on 15/11/23.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



void Swap(int* p, int* q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

void BubbleSort(int* nums, int len)
{
    if (nums==NULL || len<=1)
    {
        return;
    }
    bool swapTag;
    int lastSwap=len;
    int temp;
    while (lastSwap>1)
    {
        swapTag=false;
        temp=lastSwap;
        for (int j=1; j<lastSwap; ++j)
        {
            if (nums[j]<nums[j-1])
            {
                Swap(&nums[j],&nums[j-1]);
                swapTag=true;
                temp=j;
            }
        }
        if (swapTag==false)
        {
            return;
        }
        lastSwap=temp;

    }
}

int Partition(int* nums, int start, int end)
{
    int pivot=start + (rand()%(end-start));
    Swap(&nums[start], &nums[pivot]);
    pivot=start;
    while (start<end)
    {
        while (start<end && nums[end]>=nums[pivot])
        {
            --end;
        }
        while (start<end && nums[start]<nums[pivot])
        {
            ++start;
        }
        if (start<end)
        {
            Swap(&nums[start], &nums[end]);
        }
    }
    Swap(&nums[start], &nums[pivot]);
    pivot=start;
    return pivot;
}

void QuickSorCore(int *nums, int start, int end)
{
    if (start<end)
    {
        int pivot=Partition(nums,start,end);
        QuickSorCore(nums, start, pivot-1);
        QuickSorCore(nums, pivot+1, end);
    }
}

void QuickSort(int* nums, int len)
{
    QuickSorCore(nums, 0, len-1);
}

void InsertSort(int* nums, int len)
{
    if (nums==NULL || len<=1)
    {
        return;
    }
    int temp,j;
    for (int i=1; i<len; ++i)
    {
        temp=nums[i];
        j=i-1;
        while (j>=0 && nums[j]>temp)
        {
            nums[j+1]=nums[j];
            --j;
        }
        ++j;
        nums[j]=temp;
    }
}

void BinaryInsertSort(int* nums, int len)
{
    if (nums==NULL || len<=1)
    {
        return;
    }
    int start,mid,end,pos,temp;
    for (int i=1; i<len; ++i)
    {
        temp=nums[i];
        start=0;
        end=i-1;
        while (start<=end)
        {
            mid=(start+end)/2;
            if (nums[mid]<temp)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        if (nums[start]<temp)
        {
            pos=start+1;
        }
        else
        {
            pos=start;
        }
        for (int j=i; j>pos; --j)
        {
            nums[j]=nums[j-1];
        }
        nums[pos]=temp;
    }
}

void ShellSort(int* nums, int len)
{
    if (nums==NULL || len<=1)
    {
        return;
    }
    int temp,t;
    for (int increment=len/2; increment>=1; increment/=2)
    {
        for (int i=0; i<=len-increment; i+=increment)
        {
            for (int j=i+increment; j<len; j+=increment)
            {
                temp=nums[j];
                t=j-increment;
                while (t>=0 && nums[t]>temp)
                {
                    nums[t+increment]=nums[t];
                    t-=increment;
                }
                t+=increment;
                nums[t]=temp;
            }
        }
    }
}

void SelectSort(int* nums, int len)
{
    if (nums==NULL || len<=1)
    {
        return;
    }
    int min,pos;
    for (int i=0; i<len-1; ++i)
    {
        min=nums[i];
        pos=i;
        for (int j=i+1; j<len; ++j)
        {
            if (nums[j]<min)
            {
                min=nums[j];
                pos=j;
            }
        }
        if (pos!=i)
        {
            Swap(&nums[pos], &nums[i]);
        }
    }
}

void AdjustBigRootHeap(int* nums, int start, int end)
{
    if (2*start+1 <= end)
    {
        int maxPos,left,right;
        left=2*start+1;
        right=2*start+2;
        maxPos=start;
        if (nums[left]>nums[maxPos])
        {
            maxPos=left;
        }
        if (right<=end && nums[right]>nums[maxPos])
        {
            maxPos=right;
        }
        if (maxPos!=start)
        {
            Swap(&nums[maxPos], &nums[start]);
            AdjustBigRootHeap(nums,maxPos,end);
        }
    }


}

void BuildBigRootHeap(int* nums, int len)
{
    int last=(len-1)/2;

    for (int i=last; i>=0; --i)
    {
        AdjustBigRootHeap(nums,i,len-1);
    }
}

void HeapSort(int* nums, int len)
{
    if (nums==NULL || len<=1)
    {
        return;
    }

    BuildBigRootHeap(nums,len);
    for (int i=len-1; i>=1; --i)
    {
        Swap(&nums[0], &nums[i]);
        AdjustBigRootHeap(nums,0,i-1);
    }
}

void Merge(int* nums, int start, int mid, int end)
{

    int len1=mid-start+1;
    int len2=end-mid;
    int* nums1=new int[len1];
    int* nums2=new int[len2];
    for (int i=0; i<len1; ++i)
    {
        nums1[i]=nums[start+i];
    }
    for (int j=0; j<len2; ++j)
    {
        nums2[j]=nums[mid+1+j];
    }
    int s1=0,s2=0,k=start;
    while (s1<len1 && s2<len2)
    {
        if (nums1[s1]<=nums2[s2])
        {
            nums[k++]=nums1[s1++];
        }
        else
        {
            nums[k++]=nums2[s2++];
        }
    }
    while (s1<len1)
    {
        nums[k++]=nums1[s1++];
    }
    while (s2<len2)
    {
        nums[k++]=nums2[s2++];
    }

}

void MergeSortCore(int* nums, int start, int end)
{
    if (start<end)
    {
        int mid=start+(end-start)/2;
        MergeSortCore(nums,start,mid);
        MergeSortCore(nums,mid+1,end);
        Merge(nums,start,mid,end);
    }
}

void MergeSort(int* nums, int len)
{
    if (nums==NULL || len<=1)
    {
        return;
    }
    MergeSortCore(nums,0,len-1);
}

void RadixSort(int* nums, int len)
{

}

void PrintArray(int* nums, int len)
{
    if (nums && len>0)
    {
        printf("[");
        for (int i=0; i<len; i++)
        {
            printf(" %d ",nums[i]);
        }
        printf("]\n");
    }
}

void CopyArray(int* src, int len, int* dest)
{
    for (int i=0; i<len; ++i)
    {
        dest[i]=src[i];
    }
}


