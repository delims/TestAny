//
//  other_test.c
//  TestAny
//
//  Created by delims on 2020/8/11.
//  Copyright © 2020 delims. All rights reserved.
//

#include "other_test.h"
#include <stdio.h>
#include <string.h>

void other_test()
{
    
    char str[1000000];
    int i, num[256] = {0};
    printf("please input string:");
    scanf("%s",str);
    for (i = 0; i < strlen(str); i ++) {
        num[(int)str[i]] ++;
    }
    for (i = 0; i < 256; i ++) {
        if (num[i] != 0) {
            printf("字符 %c 出现了 %i 次\n",(char)i,num[i]);
        }
    }
}
