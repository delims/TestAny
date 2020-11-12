//
//  test_11.hpp
//  TestAny
//
//  Created by delims on 2020/11/3.
//  Copyright © 2020 delims. All rights reserved.
//

#ifndef test_11_hpp
#define test_11_hpp

#include <stdio.h>

struct alarm_info {
    int speed;
    char *name;
};

class Alarm{
public:
    static alarm_info info;
};



void test_11();
#endif /* test_11_hpp */
