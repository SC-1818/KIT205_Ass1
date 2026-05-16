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

HashCustomerNode* createHashCustomerNode(int customerID) {
    HashCustomerNode* newNode = (HashCustomerNode*)malloc(sizeof(HashCustomerNode));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->customerID = customerID;
    newNode->products = NULL;
    newNode->next = NULL;

    return newNode;
}

HashCustomerNode* findHashCustomer(HashCustomerNode* table[], int customerID) {
    int index = hashFunction(customerID);
    HashCustomerNode* current = table[index];

    while (current != NULL) {
        if (current->customerID == customerID) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void insertHashCustomer(HashCustomerNode* table[], int customerID) {
    int index;
    HashCustomerNode* newNode;

    if (findHashCustomer(table, customerID) != NULL) {
        return;
    }

    index = hashFunction(customerID);
    newNode = createHashCustomerNode(customerID);

    newNode->next = table[index];
    table[index] = newNode;
}