#pragma once
#include "product_bst.h"

#define TABLE_SIZE 10007

typedef struct HashCustomerNode {
    int customerID;
    ProductNode* products;
    struct HashCustomerNode* next;
} HashCustomerNode;

int hashFunction(int customerID);
void setupHashTable(HashCustomerNode* table[]);

HashCustomerNode* createHashCustomerNode(int customerID);
HashCustomerNode* findHashCustomer(HashCustomerNode* table[], int customerID);
void insertHashCustomer(HashCustomerNode* table[], int customerID);

void addPurchasePrototype2(HashCustomerNode* table[], int customerID, int productID);

void printCustomersPrototype2(HashCustomerNode* table[]);
void printProductsForCustomerPrototype2(HashCustomerNode* table[], int customerID);
void printCustomersForProductPrototype2(HashCustomerNode* table[], int productID);

void freeHashTable(HashCustomerNode* table[]);
void testPrototype2();