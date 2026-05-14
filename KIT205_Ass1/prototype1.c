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

    CustomerNode* addPurchasePrototype1(CustomerNode * head, int customerID, int productID); {
        CustomerNode* customer;

        head = insertCustomer(head, customerID);
        customer = findCustomer(head, customerID);

        if (customer != NULL) {
            customer->products = insertProduct(customer->products, productID);
        }

        return head;
    }
    void printCustomersPrototype1(CustomerNode * head); {
        CustomerNode* current = head;

        printf("Customers: ");

        while (current != NULL) {
            printf("%d ", current->customerID);
            current = current->next;
        }

        printf("\n");
    }

    void printProductsForCustomerPrototype1(CustomerNode * head, int customerID); {
        CustomerNode* customer = findCustomer(head, customerID);

        if (customer == NULL) {
            printf("Customer %d not found.\n", customerID);
            return;
        }

        printf("Products for customer %d: ", customerID);
        printProducts(customer->products);
        printf("\n");
    }

    void printCustomersForProductPrototype1(CustomerNode * head, int productID); {
        CustomerNode* current = head;
        int found = 0;

        printf("Customers who bought product %d: ", productID);

        while (current != NULL) {
            if (findProduct(current->products, productID)) {
                printf("%d ", current->customerID);
                found = 1;
            }

            current = current->next;
        }

        if (found == 0) {
            printf("none");
        }

        printf("\n");
    }

    void freeCustomersPrototype1(CustomerNode * head); {
        CustomerNode* current = head;
        CustomerNode* temp;

        while (current != NULL) {
            temp = current;
            current = current->next;

            freeProducts(temp->products);
            free(temp);
        }
    }


