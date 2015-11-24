//
//  main.cpp
//  Mathematics
//
//  Created by xuwenyong on 15/11/24.
//  Copyright © 2015年 Ack. All rights reserved.
//

#include <iostream>
#include "Mathematics.h"

int main(int argc, const char * argv[]) {
    char str1[]="abcd";
    printf("Combination of \"%s\" :\n",str1);
    Combination(str1);
    
    char str2[]="abbb";
    printf("Permutation of \"%s\" :\n",str2);
    PermutationIncludeRepeatSrcString(str2, 0, strlen(str2)-1);

    return 0;
}
