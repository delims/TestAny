//
//  main.m
//  TestAny
//
//  Created by delims on 2020/8/5.
//  Copyright © 2020 delims. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "utf8_encoding.h"
#import "corefoundation_test.h"
#import "yymodel_test.h"
#import "other_test.h"
#import "pthread_test.hpp"


int main(int argc, const char * argv[]) {
//    @autoreleasepool {
//        uft8_encoding();
//        corefoundation_test();
//        yymodel_test();
//        other_test();
//
//    }
    
    pthread_test();
    

    return 0;
}
