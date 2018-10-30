#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include "type.h"

bool operator==(const IID& guid1, const IID& guid2);

void LogD(const char* TAG,const char* format, ...);

void LogE(const char* TAG,const char* format, ...);

#endif // UTIL_H
