#pragma once


#include "product_bst.h"

typedef struct CustomerNode {
    int customerID;
    ProductNode* products;
    struct CustomerNode* next;
} CustomerNode;

CustomerNode* createCustomerNode(int customerID);
CustomerNode* findCustomer(CustomerNode* head, int customerID);
CustomerNode* insertCustomer(CustomerNode* head, int customerID);
CustomerNode* addPurchasePrototype1(CustomerNode* head, int customerID, int productID);

void printCustomersPrototype1(CustomerNode* head);
void printProductsForCustomerPrototype1(CustomerNode* head, int customerID);
void printCustomersForProductPrototype1(CustomerNode* head, int productID);

void freeCustomersPrototype1(CustomerNode* head);
void testPrototype1();