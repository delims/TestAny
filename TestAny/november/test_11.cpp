//
//  test_11.cpp
//  TestAny
//
//  Created by delims on 2020/11/3.
//  Copyright © 2020 delims. All rights reserved.
//

#include "test_11.hpp"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

alarm_info Alarm::info;

struct testOperator {
    
    void operator = (string arg) {
        cout<<arg<<endl;

    }
    void operator << (string arg){
        cout<<arg<<endl;
    }
    
    string operator + (string arg) {
        cout<<arg<<endl;
        return  "hello2";
    }
};


void test_11()
{
    printf("void test_11();");
    
    string s = "123345";
    s.size();
    s.length();
    s.substr();
    cout<<s<<endl;
    cout<<s.size()<<endl;
    cout<<s.length()<<endl;
    cout<<s.substr(2,2)<<endl;
    cout<<s.c_str()<<endl;
    
    
    vector<int> array;
    array.push_back(12);
    array.push_back(13);
    cout<<array.size()<<endl;
    cout<<array[1]<<endl;

    testOperator op ;
//    op<<"hello";
//    op="hello";
    
    op<<op+"delims";
    
    

}
