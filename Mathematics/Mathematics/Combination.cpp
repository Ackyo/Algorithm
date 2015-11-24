//
//  Mathematics.cpp
//  Mathematics
//
//  Created by xuwenyong on 15/11/24.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <stdio.h>
#include "Mathematics.h"
#include<string.h>

void Combination(char* str)
{
    if (str==NULL)
    {
        return;
    }
    
    int len=strlen(str);
    
    int count=1<<len;
    
    for (int i=1; i<count; ++i)
    {
        for (int j=0; j<len; ++j)
        {
            if ((1<<j)&i)
            {
                printf("%c",str[j]);
            }
        }
        puts("");
    }
}