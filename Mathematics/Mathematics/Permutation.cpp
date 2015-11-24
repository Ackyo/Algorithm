//
//  Permutation.cpp
//  Mathematics
//
//  Created by xuwenyong on 15/11/24.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Mathematics.h"

void Swap(char* p, char* q)
{
    char temp=*p;
    *p=*q;
    *q=temp;
}

bool HaveRepeat(char* str,int start, int end)
{
    for (int j=start; j<end; ++j)
    {
        if (str[j]==str[end])
        {
            return true;
        }
    }
    return false;
}

void PermutationIncludeRepeatSrcString(char* str, int start, int end)
{
    if (start==end)
    {
        puts(str);
    }
    else
    {
        for (int i=start; i<=end; ++i)
        {
            if (!HaveRepeat(str,start,i))
            {
                Swap(&str[start], &str[i]);
                PermutationIncludeRepeatSrcString(str, start+1, end);
                Swap(&str[start], &str[i]);
            }
        }
    }
}