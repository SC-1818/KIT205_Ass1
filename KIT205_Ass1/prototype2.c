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

void addPurchasePrototype2(HashCustomerNode* table[], int customerID, int productID) {
    HashCustomerNode* customer;

    insertHashCustomer(table, customerID);
    customer = findHashCustomer(table, customerID);

    if (customer != NULL) {
        customer->products = insertProduct(customer->products, productID);
    }
}

void printCustomersPrototype2(HashCustomerNode* table[]) {
    int i;
    HashCustomerNode* current;

    printf("Customers: ");

    for (i = 0; i < TABLE_SIZE; i++) {
        current = table[i];

        while (current != NULL) {
            printf("%d ", current->customerID);
            current = current->next;
        }
    }

    printf("\n");
}

void printProductsForCustomerPrototype2(HashCustomerNode* table[], int customerID) {
    HashCustomerNode* customer = findHashCustomer(table, customerID);

    if (customer == NULL) {
        printf("Customer %d not found.\n", customerID);
        return;
    }

    printf("Products for customer %d: ", customerID);
    printProducts(customer->products);
    printf("\n");
}

void printCustomersForProductPrototype2(HashCustomerNode* table[], int productID) {
    int i;
    int found = 0;
    HashCustomerNode* current;

    printf("Customers who bought product %d: ", productID);

    for (i = 0; i < TABLE_SIZE; i++) {
        current = table[i];

        while (current != NULL) {
            if (findProduct(current->products, productID)) {
                printf("%d ", current->customerID);
                found = 1;
            }

            current = current->next;
        }
    }

    if (found == 0) {
        printf("none");
    }

    printf("\n");
}


void freeHashTable(HashCustomerNode* table[]) {
    int i;
    HashCustomerNode* current;
    HashCustomerNode* temp;

    for (i = 0; i < TABLE_SIZE; i++) {
        current = table[i];

        while (current != NULL) {
            temp = current;
            current = current->next;

            freeProducts(temp->products);
            free(temp);
        }

        table[i] = NULL;
    }
}

void testPrototype2() {
    HashCustomerNode* table[TABLE_SIZE];

    setupHashTable(table);

    printf("----- Prototype 2 Test -----\n");

    addPurchasePrototype2(table, 103, 5002);
    addPurchasePrototype2(table, 101, 5001);
    addPurchasePrototype2(table, 101, 5003);
    addPurchasePrototype2(table, 102, 5001);
    addPurchasePrototype2(table, 103, 5004);

    printCustomersPrototype2(table);

    printProductsForCustomerPrototype2(table, 101);
    printProductsForCustomerPrototype2(table, 102);
    printProductsForCustomerPrototype2(table, 103);

    printCustomersForProductPrototype2(table, 5001);
    printCustomersForProductPrototype2(table, 5002);
    printCustomersForProductPrototype2(table, 9999);

    freeHashTable(table);

    printf("----- End of Prototype 2 Test -----\n");
}