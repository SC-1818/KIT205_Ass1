#include <stdio.h>
#include <time.h>
#include "prototype1.h"
#include "prototype2.h"
#include "performance.h"

void runPerformanceTest() {
    int i;
    int j;
    int dataSize;
    int sizes[] = { 1000, 5000, 10000 };
    int numberOfSizes = 3;

    clock_t start, end;
    double timeTaken;

    printf("\n----- Performance Test -----\n");
    printf("Time-critical operation: inserting customer-product records\n\n");

    for (i = 0; i < numberOfSizes; i++) {
        dataSize = sizes[i];

        CustomerNode* db1 = NULL;

        start = clock();

        for (j = 0; j < dataSize; j++) {
            db1 = addPurchasePrototype1(db1, j, j + 5000);
        }

        end = clock();

        timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Prototype 1 Linked List + BST (%d records): %.5f sec\n", dataSize, timeTaken);

        freeCustomersPrototype1(db1);

        HashCustomerNode* table[TABLE_SIZE];
        setupHashTable(table);

        start = clock();

        for (j = 0; j < dataSize; j++) {
            addPurchasePrototype2(table, j, j + 5000);
        }

        end = clock();

        timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Prototype 2 Hash Table + BST (%d records): %.5f sec\n\n", dataSize, timeTaken);

        freeHashTable(table);
    }

    printf("----- End Performance Test -----\n");
}