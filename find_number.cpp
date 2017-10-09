// Copyright (c) 2017 Baidu.com, Inc. All Rights Reserved
// @Author: yangjiaxue(yang.jiaxue.micheal@gmail.com)
// 
// @File: find_number.cpp
// @Last modified: 2017-10-09 18:00:05
// @Brief: find the max number in the array which increases firstly and then decreases
//         e.g. (1 3 5 4 2), (1 2 3 4 5), (5 4 3 2 1) or (3 3 3 3 3)

#include <stdio.h>

int foo(int* array, size_t num) {
    if (num == 0) {
        return 0;
    }

    size_t begin = 0U, end = num - 1U;
    while (begin < end) {
        if (end - begin + 1 == 2) {
            return array[begin] > array[end] ? array[begin] : array[end];
        }
        size_t mid = (begin + end) / 2;
        if (array[mid] > array[mid - 1U] && array[mid] > array[mid + 1]) {
            return array[mid];
        } else if (array[mid] > array[mid + 1]) {
            end = mid;
        } else if (array[mid] > array[mid - 1]){
            begin = mid;
        } else {
            // array[mid] == array[mid - 1] == array[mid + 1]
            // find the maxes of array[begin .. mid - 1] and array[mid + 1 .. end]
            int lmax = foo(array + begin, mid - begin);
            int rmax = foo(array + mid + 1, end - mid);
            return lmax > rmax ? lmax : rmax;
        }
    }
    return array[begin];
}

int main(int argc, char* argv[]) {
    int a[] = {1, 2, 3, 3, 3, 3, 5, 6};
    printf("the max number is %d\n", foo(a, sizeof(a) / sizeof(a[0])));

    int b[] = {6, 5, 3, 3, 3, 3, 1};
    printf("the max number is %d\n", foo(b, sizeof(b) / sizeof(b[0])));

    int c[] = {1, 2, 7, 4, 3, 3, 1};
    printf("the max number is %d\n", foo(c, sizeof(c) / sizeof(c[0])));

    int d[] = {1, 2};
    printf("the max number is %d\n", foo(d, sizeof(d) / sizeof(d[0])));
    return 0;
}

/* vim: set ts=4 sw=4: */

