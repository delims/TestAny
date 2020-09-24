//
//  sort_algorithm.cpp
//  TestAny
//
//  Created by delims on 2020/8/31.
//  Copyright © 2020 delims. All rights reserved.
//

#include "sort_algorithm.hpp"

void bubble_sort(int arr[],int len)
{
    int tem;
    for (int i = 0; i < len - 1; i ++) {
        for (int j = 0; j < len - 1 - i; j ++) {
            if (arr[j] > arr[j+1]) {
                tem = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tem;
            }
        }
    }
}

void selection_sort(int arr[],int len)
{
    int i,j,temp,min;
    for (i = 0; i < len; i ++) {
        min = i;
        for (j = i + 1; j < len; j ++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int arr[],int len)
{
    int i,j,key;
    for (i = 1; i < len; i ++) {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = key;
    }
}

void shell_sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
}

void sort_algorithm()
{
    
    int arr[] = {4,2,12,1,2,3,4,5,6,7,321,12,3,2,2,123,4,56,7,3,12,1,34,32};
    int count = sizeof(arr) / sizeof(int);
    
//    bubble_sort(arr, count);
//    selection_sort(arr, count);
    shell_sort(arr, count);
    
    for (int i = 0; i < sizeof(arr)/sizeof(int); i ++) {
        printf("%i ",arr[i]);
    }
    
    printf(" \n");
    
}
