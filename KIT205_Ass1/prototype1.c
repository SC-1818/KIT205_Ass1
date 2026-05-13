#include <stdio.h>
#include <stdlib.h>
#include "prototype1.h"

CustomerNode* createCustomerNode(int customerID) {
    CustomerNode* newNode = (CustomerNode*)malloc(sizeof(CustomerNode));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->customerID = customerID;
    newNode->products = NULL;
    newNode->next = NULL;

    return newNode;
}

CustomerNode* findCustomer(CustomerNode* head, int customerID) {
    CustomerNode* current = head;

    while (current != NULL) {
        if (current->customerID == customerID) {
            return current;
        }

        current = current->next;
    }

    return NULL;