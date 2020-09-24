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
#include <stdlib.h>



//统计字符出现次数
void statisticCharNumber()
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

// 测试栈和堆的地址生长方向，通过测试得知 heap地址生长方向越来越大。
void heapAddressDirection()
{
    int a = 0x12345678;
    
    char *p = (char *)&a;
    
    printf("address:%p--%x\n",p,*p);p++;
    printf("address:%p--%x\n",p,*p);p++;
    printf("address:%p--%x\n",p,*p);p++;
    printf("address:%p--%x\n",p,*p);p++;

    int *p2 = (int *)malloc(4);
    *p2 = a;
    
    char *p3 = (char*)p2;
    
    printf("p3 address:%p--value:%x\n",p3,*p3);p3++;
    printf("p3 address:%p--value:%x\n",p3,*p3);p3++;
    printf("p3 address:%p--value:%x\n",p3,*p3);p3++;
    printf("p3 address:%p--value:%x\n",p3,*p3);p3++;

    int *p4 = (int*)malloc(4);
    printf("p4 address:%p--value:%x\n",p4,*p4);
}


// 全局变量和局部静态变量在一起

static int global_var;
static int global_var_initted = 0;

void static_var_address_test()
{
    static int local_static_var;
    static int local_static_var_initted = 0;
    
    
    
    printf("global: %p\n",&global_var);
    printf("local: %p\n",&local_static_var);

    printf("global_initted: %p\n",&global_var_initted);
    printf(" local_initted: %p\n",&local_static_var_initted);
    
    
}


void other_test()
{
//    heapAddressDirection();
    static_var_address_test();

}


