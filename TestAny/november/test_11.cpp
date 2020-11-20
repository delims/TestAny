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


//#include "TestAny-Swift.h"

using namespace std;

alarm_info Alarm::info;

struct testOperator {
    
    testOperator() = default;
//    testOperator(testOperator &arg,int a) = delete;
    
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
    
    
    int operator[] (int arg) const{
        printf("you bad  %i \n",arg);
        return arg;
    }
    
    int operator[] (int arg) {
        printf("you good  %i \n",arg);
        return arg;
    }
    
    
    
    
};


struct person {
    person *prior;
    person *next;
    int number;
};

int last_leave_number(int count, int m) {
    if (count <= 1) return count;
    person *head = NULL;
    person *current = NULL;
    head = new person();
    head->number = 1;
    current = head;
    
    for (int i = 2; i <= count; i ++) {
        current->next = new person();
        current->next->prior = current;
        current = current->next;
        current->number = i;
    }
    
    current->next = head;
    head->prior = current;
    current = head;
    
    
    int remain = count;
    
    //qule 开始
    while (remain > 1) {
        int steps = m % remain;
        while (steps > 0) {
            steps --;
            current = current->next;
        }
        current = current->prior;
        current->prior->next = current->next;
        current->next->prior = current->prior;
        delete current;
        
        current = current->next;
        remain --;
    }
    int ret = current->number;
    delete current;
    return  ret;
}

// 可变模板参数

void handleValue(int value) {cout << "Integer :" << value <<endl;}
void handleValue(double value) {cout << "Double :" << value <<endl;}
void handleValue(string value) {cout << "string :" << value <<endl;}


template <typename Z>
void processValues(Z arg) { handleValue(arg); }

template <typename T, typename ... Ts>
void processValues(T arg, Ts && ...args)
{
    handleValue(arg);
    processValues(args...);
}

//const_cast <new_type> (expression)
//static_cast <new_type> (expression)
//reinterpret_cast <new_type> (expression)
//dynamic_cast <new_type> (expression)




void test_cast()
{
    //这是确实修改了内存地址的值。但是打印还是原来的值。因为编译器做了优化。
    const int a = 100;
//  volatile  const int a = 100; //volatile告诉编译器每次都去内存取值。这样可以打印出真实值。

    const int *p = (const int *)&a;
    int *mp = (int *)(p);
    *mp = 12;
    
//    cout << a <<endl;
    printf("%i \n",a);
    
//    cout<<"a adress: " << &a <<endl;
//    cout<<"p value : " << p <<endl;
//    cout<<"mp value: " << mp <<endl;
//
//
//    cout<<"mp value: " << *mp <<endl;
//    cout<<"a value: " << a <<" "  << &a << endl;
//    cout<<"mp value: " << mp <<endl;
    
//    long longvalue = 0xaaa7ffeefbff3c0UL;
    long longvalue = 0xfffbff3c0;

    printf("%lx \n",longvalue);
}


__attribute__((always_inline))
int infunc()
{
    int a = 0;
    int b = 0;
    int c = 100;
    int d = a + b + c;
    return  123;
}

class testOverLoad {
    int value alignas(long double);
public:
    int operator[] (int arg) {
        cout << "come" <<endl;
        return arg;
    }
    int operator[] (int arg) const{
        (*const_cast<testOverLoad*>(this))[123];
        cout << "come const" <<endl;
        return arg;
    }
    testOverLoad(){
        cout<< "testover constructor " <<endl;
        cout << sizeof(testOverLoad)  << endl;
    }
};

class A1 {
    
    testOverLoad array[10];
    
    
};

void test_11()
{
//    testOverLoad load;
//    load[12];
//    const testOverLoad load2;
//    load2[12];
//    unsigned char a = 1;
//    unsigned char b = -a;
//    printf("== %u \n",b);
//
//    printf("%li \n",0x00007ffeefbff45f);
//    printf("%li \n",-0x00007ffeefbff45f);
    A1 o;
    cout<<sizeof(o)<<endl;
}



//    test_cast();
    
//    for (int i = 3;i < 7; i++)
//    for (int j = 3;j < 7; j++) {
//        cout<< "count = " << i << "  m = " << j << "  return "<< last_leave_number(i, j) <<endl;
//    }
//
//    processValues(1, 2.5, "test");

//    printf("the last number = %i\n",last_leave_number(4, 3));
    
//    testOperator op;
//    testOperator op1 = op; op1[3];
//    const int a = 12;
//    op[a];
    
//    int a = sizeof(size_t);
//    a = infunc();
    

//    printf("void test_11();");
    
//    string s = "123345";
//    s.size();
//    s.length();
//    s.substr();
//    cout<<s<<endl;
//    cout<<s.size()<<endl;
//    cout<<s.length()<<endl;
//    cout<<s.substr(2,2)<<endl;
//    cout<<s.c_str()<<endl;
//
//
//    vector<int> array;
//    array.push_back(12);
//    array.push_back(13);
//    cout<<array.size()<<endl;
//    cout<<array[1]<<endl;
//
//    testOperator op ;
//    op<<"hello";
//    op="hello";
    
//    op<<op+"delims";
    
    
