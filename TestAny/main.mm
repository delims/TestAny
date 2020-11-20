//
//  main.m
//  TestAny
//
//  Created by delims on 2020/8/5.
//  Copyright © 2020 delims. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <pthread/pthread.h>
#import "utf8_encoding.h"
#import "corefoundation_test.h"
#import "yymodel_test.h"
#import "other_test.h"
#import "pthread_test.hpp"
#import "sort_algorithm.hpp"
#import "AVLTree.hpp"
#import "test_constructor.hpp"
#import "test_11.hpp"

#import "TestAny-Swift.h"


//int* singleNumber(int* nums, int numsSize, int* returnSize){
//
//    int sum = 0;
//    for (int i = 0; i < numsSize; i ++) {
//        sum ^= nums[i];
//    }
//    if (sum == 0) return NULL;
//
//    int true_bit = 1;
//    while ((sum & true_bit) == 0) {
//        true_bit <<= 1;
//    }
//    int sum1 = 0 ,sum2 = 0;
//    for (int i = 0 ; i < numsSize; i ++) {
//        if (nums[i] & true_bit) {
//            sum1 ^= nums[i];
//        } else {
//            sum2 ^= nums[i];
//        }
//    }
//    int *ret = malloc(sizeof(int) * 2);
//
//    ret[0] = sum1;
//    ret[1] = sum2;
//    *returnSize = 2;
//    return ret;
//}


int main(int argc, const char * argv[]) {
//    @autoreleasepool {
//        uft8_encoding();
//        corefoundation_test();
//        yymodel_test();
//        other_test();
//
//    }
    
//    printf("main \n");
//
//    printf("%p\n",pthread_self());
//    printf("%p\n",NSThread.currentThread);
//    printf("%i\n",pthread_main_np());
//    printf("%p\n",NSThread.mainThread);

//    play_tree();
//    pthread_test();
//    sort_algorithm();
//    printf("%d\n",1^2);
//    test_constructor();
    
//    Alarm::info.speed = 2;
    
//    printf("%d\n",Alarm::info.speed);
    test_11();
//    November *nov = November.alloc.init;
//    [nov hello2];
//
//    printf("%p \n", @[]);
//
//    for (int i = 0;i < 1; i ++) {
//        printf("%p \n", NSObject.alloc.init);
//        printf("%p \n", NSArray.alloc.init);
//        printf("%p \n", NSDictionary.alloc.init);
//        printf("%p \n", NSString.alloc.init);
//    }
//
//
//
//    printf("\n\n");
    
    return 0;
}
