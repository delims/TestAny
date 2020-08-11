//
//  corefoundation_test.c
//  TestAny
//
//  Created by delims on 2020/8/6.
//  Copyright © 2020 delims. All rights reserved.
//

#include "corefoundation_test.h"
#import <CoreFoundation/CoreFoundation.h>
#include <Foundation/Foundation.h>

void corefoundation_test(void)
{
    
#pragma mark CoreFoundation API usage
    
    //CFStringRef 的使用
    // 定义
    // typedef struct __CFString CFStringRef;
    // 通过C字符串创建 创建 __CFString
    
    const char *c_str = "hello delims";
    CFStringRef cfStr = CFStringCreateWithCString(CFAllocatorGetDefault(), c_str, kCFStringEncodingUTF8);
    
    
    char buffer[13];
    bool succes = CFStringGetCString(cfStr, buffer, 13, kCFStringEncodingUTF8);
    if (succes) {
        printf("%s",buffer);
    }
        
    CFMutableDictionaryRef mutableDictRef = CFDictionaryCreateMutable(CFAllocatorGetDefault(), 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    
    int intValue = 1000;
    CFNumberRef number = CFNumberCreate(CFAllocatorGetDefault(), kCFNumberIntType, &intValue);
    
    CFDictionarySetValue(mutableDictRef, cfStr, number);
    
    CFNumberRef number2 = CFDictionaryGetValue(mutableDictRef, cfStr);
    
    int fromCFNumber;
    CFNumberGetValue(number2, kCFNumberIntType, &fromCFNumber);
    printf("%i",fromCFNumber);
    
    
    const void *array[] = {cfStr, mutableDictRef};
    CFArrayRef arrayRef = CFArrayCreate(CFAllocatorGetDefault(), array, 2, &kCFTypeArrayCallBacks);
    CFStringRef stringRef = CFArrayGetValueAtIndex(arrayRef, 0);
    char buf[13];
    CFStringGetCString(stringRef, buf, 13, kCFStringEncodingUTF8);
    printf("%s",buf);
    
    
    
    

}

    
    

//
//    CFMutableDictionaryRef dictRef = CFDictionaryCreateMutable(CFAllocatorGetDefault(), 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
//
////    static int key = 100;
////    static int value = 100;
//
//    int a = 100;
//    int b = 100;
//
//    const char *cStr = "abcdefghijk";
//
//    CFStringRef string = CFStringCreateWithCString(CFAllocatorGetDefault(), cStr, kCFStringEncodingUTF8);
//
//    CFNumberRef number_a = CFNumberCreate(CFAllocatorGetDefault(), kCFNumberIntType, &a);
//    CFNumberRef number_b = CFNumberCreate(CFAllocatorGetDefault(), kCFNumberIntType, &b);
//
//    CFDictionarySetValue(dictRef,string,number_b);
//
//    CFNumberRef number = CFDictionaryGetValue(dictRef, string);
//
//    int result;
//
//    CFNumberGetValue(number, kCFNumberIntType, &result);
//
//    printf("%i\n",result);
    
    
//    NSNumber *number = [NSNumber numberWithInt:8];
//
//    NSLog(@"%@",NSStringFromClass(number.superclass));
    

