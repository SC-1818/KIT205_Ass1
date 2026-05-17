#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "prototype1.h"
#include "prototype2.h"
#include "performance.h"

int main() {
    testPrototype1();
    testPrototype2();
    runPerformanceTest();

    return 0;
}