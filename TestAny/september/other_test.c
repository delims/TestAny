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





//void bubble_sort(int arr[], int len)
//{
//    int i,j,temp;
//    for (i = 0; i < len -1; i ++)
//        for (j = 0; j < len -1 -i; j ++)
//            if (arr[j] > arr[j+1]) {
//                temp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = temp;
//            }
//}
//
//void swap(int *a,int *b) //交換兩個變數
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void selection_sort(int arr[], int len)
//{
//    int i,j,min,temp;
//    for (i = 0; i < len-1; i ++) {
//        min = i;
//        for (j = i + 1; j < len; j ++)
//            if (arr[j] < arr[min])
//                min = j;
//        temp = arr[min];
//        arr[min] = arr[i];
//        arr[i] = temp;
//    }
//}
//
//void insertion_sort(int arr[], int len)
//{
//    int i,j,key;
//    for (i = 1; i < len; i ++) {
//        j = i - 1;
//        key = arr[i];
//        while (j >= 0 && arr[j] > key) {
//            arr[j+1] = arr[j];
//            j --;
//        }
//        arr[j+1] = key;
//    }
//}

// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
//
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//    struct ListNode *p = NULL;
//    struct ListNode *dest = NULL;
//    int carry = 0;
//    int sum = 0;
//    while(l1 || l2 || carry) {
//        sum = carry;
//        if (l1) {
//            sum += l1->val;
//            l1 =  l1->next;
//        }
//        if (l2) {
//            sum += l2->val;
//            l2 =  l2->next;
//        }
//
//        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//        if (p == NULL) p = newNode;
//        else p->next = newNode;
//
//        if (dest == NULL) dest = p;
//        else p = p->next;
//        memset(p, 0, sizeof(struct ListNode));
//
//        p->val = sum % 10;
//        carry  = sum / 10;
//
//    }
//
//    return dest;
//}

//using namespace std;
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//
//
//
//
//
//    }
//};

//extern "C" {

//#include <stdio.h>
//
//unsigned long lengthOfLongestSubstring(char * s){
//    unsigned long max = 0;
//    unsigned long len = 0;
//    for(unsigned long i = 0; i < strlen(s); i ++) {
//        len = 0;
//        if (max >= strlen(s)-i) return max;
//        for (unsigned long j = i+1; j < strlen(s); j ++) {
//            for (unsigned long k = i ; k < j; k ++) {
//                if (s[k] == s[j]) {
//                    len = j - i;
//                    break;
//                }
//                if (k == j - 1) {
//                    len = j - i + 1;
//                    if (len > max) max = len;
//                    len = 0;
//                }
//            }
//            if (len > 0) {
//                if (len > max) max = len;
//                break;
//            }
//        }
//    }
//    return max;
//}



//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
//    int leftIndex,rightIndex;
//    if ((nums1Size + nums2Size) % 2 == 0) {
//        rightIndex = (nums1Size + nums2Size) / 2;
//        leftIndex = rightIndex - 1;
//    } else {
//        rightIndex = leftIndex = (nums1Size + nums2Size) / 2;
//    }
//
//    int num1 = *(nums1 + nums1Size/2);
//
//    return 0.0;
//}
