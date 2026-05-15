#include <stdio.h>
#include <stdlib.h>
#include "prototype2.h"



int hashFunction(int customerID) {
    return customerID % TABLE_SIZE;
}

void setupHashTable(HashCustomerNode* table[]) {
    int i;

    for (i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}