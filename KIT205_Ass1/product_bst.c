#include <stdio.h>
#include <stdlib.h>
#include "product_bst.h"

ProductNode* createProductNode(int productID) {
    ProductNode* newNode = (ProductNode*)malloc(sizeof(ProductNode));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->productID = productID;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

ProductNode* insertProduct(ProductNode* root, int productID) {
    if (root == NULL) {
        return createProductNode(productID);
    }

    if (productID < root->productID) {
        root->left = insertProduct(root->left, productID);
    }
    else if (productID > root->productID) {
        root->right = insertProduct(root->right, productID);
    }

    return root;
}

int findProduct(ProductNode* root, int productID) {
    if (root == NULL) {
        return 0;
    }

    if (productID == root->productID) {
        return 1;
    }
    else if (productID < root->productID) {
        return findProduct(root->left, productID);
    }
    else {
        return findProduct(root->right, productID);
    }
}

void printProducts(ProductNode* root) {
    if (root != NULL) {
        printProducts(root->left);
        printf("%d ", root->productID);
        printProducts(root->right);
    }
}

void freeProducts(ProductNode* root) {
    if (root != NULL) {
        freeProducts(root->left);
        freeProducts(root->right);
        free(root);
    }
}