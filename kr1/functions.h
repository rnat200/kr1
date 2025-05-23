#ifndef HEADER
#define HEADER
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <exception>
#include <cstring>

struct String {
    char str[256];
    int key;
};

const int32_t MAX_STRINGS = 1000;
const int32_t MAX_WORD_LEN = 256;
void InputStrings(String*, int32_t);
int32_t ExtractKeys(const char*);
int CompareByKeys(const void*, const void*); 
void QsortByKeys(String*, int32_t);

void Task();
void InputStingsNumber(int32_t&);
#endif



