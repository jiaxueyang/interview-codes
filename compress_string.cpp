// Copyright (c) 2017 Baidu.com, Inc. All Rights Reserved
// @Author: yangjiaxue(yang.jiaxue.micheal@gmail.com)
// 
// @File: compress_string.cpp
// @Last modified: 2017-10-10 12:00:46
// @Brief: 1. remove spaces both at the beginning and end of string 
//         2. compress spaces between words to a space
//         e.g. "    a   b   " => "a b"

#include <stdio.h>

char* foo(char* str) {
    if (str == NULL) {
        return str;
    }
    char *res = str, *dst = str;
    while(*str == ' ') {
        ++str;
    }
    int count = 0;
    while(*str) {
        if (*str != ' ') {
            if (count > 0) {
                *dst++ = ' ';
                count = 0;
            }
            *dst++ = *str++;
        } else {
            ++count;
            ++str;
        }
    }
    *dst = '\0';
    return res;
}

int main(int argc, char* argv[]) {
    char a[] = "   ab    yyyyyyy        def   ";
    printf("dst \"%s\"\n", foo(a));
    char b[] = "ab c def";
    printf("dst \"%s\"\n", foo(b));
    char c[] = "       ";
    printf("dst \"%s\"\n", foo(c));
    return 0;
}

/* vim: set ts=4 sw=4: */

