//
//  yymodel_test.c
//  TestAny
//
//  Created by delims on 2020/8/6.
//  Copyright © 2020 delims. All rights reserved.
//

#include "yymodel_test.h"
#import <objc/runtime.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <AppKit/AppKit.h>

void yymodel_test(void)
{
    
//    BOOL isMeta = class_isMetaClass(NSObject.superclass);
//
//    Class metaClass = objc_getMetaClass(class_getName(NSArray.class));

    NSDictionary *dictionary = (id)kCFNull;
    
    if (!dictionary || [dictionary isKindOfClass:NSDictionary.class] == NO) {
        NSLog(@"%@",@"Meiyou ");
    }
    
    
    NSLog(@"%@",NSStringFromClass(dictionary.class));

    
    CFDictionaryRef dict2 = CFDictionaryCreateMutable(CFAllocatorGetDefault(), 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    NSDictionary *dict3 = @{}.mutableCopy;
    
    NSDictionary *dict4 = (__bridge id)dict2;
    
    NSLog(@"%@",NSStringFromClass(dict4.superclass));
    NSLog(@"%@",NSStringFromClass(dict3.class));

    
    NSColor *color1 = NSColor.whiteColor;
    NSColor *color2 = NSColor.whiteColor;
    
    NSLog(@"%@",color1);
    NSLog(@"%@",color2);
    NSLog(@"%i",color1 == color2);
    
    NSString *str1 = @"delims1";
    NSString *str2 = @"delims1".mutableCopy;
    NSString *str3 =[NSString stringWithFormat:@"delims"];
    NSString *str4 =[NSString stringWithFormat:@"winter"];

    
    NSLog(@"%i",str1 == str2);
    
    NSLog(@"%p",str1);
    NSLog(@"%p",str2);
    NSLog(@"%p",str3);
    NSLog(@"%p",str4);
    NSLog(@"%@",NSStringFromClass(str1.class));
    NSLog(@"%@",NSStringFromClass(str2.class));
    NSLog(@"%@",NSStringFromClass(str3.class));
    
    NSObject *obj1 = NSObject.new;
    NSObject *obj2 = NSObject.new;
    
    NSMutableSet *set = NSMutableSet.new;
    [set addObject:obj1];
    [set addObject:obj2];
    
    NSLog(@"%i",[obj1 isEqual:obj2]);
    NSLog(@"%p --- %lx",obj1,(unsigned long)obj1.hash);
    
}


