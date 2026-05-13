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


    CustomerNode* insertCustomer(CustomerNode * head, int customerID); {
        CustomerNode* newNode;
        CustomerNode* current;

        if (findCustomer(head, customerID) != NULL) {
            return head;
        }

        newNode = createCustomerNode(customerID);

        if (head == NULL || customerID < head->customerID) {
            newNode->next = head;
            return newNode;
        }

        current = head;

        while (current->next != NULL && current->next->customerID < customerID) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        return head;
    }