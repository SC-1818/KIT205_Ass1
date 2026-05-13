#pragma once

typedef struct ProductNode {
    int productID;
    struct ProductNode* left;
    struct ProductNode* right;
} ProductNode;

ProductNode* createProductNode(int productID);
ProductNode* insertProduct(ProductNode* root, int productID);
int findProduct(ProductNode* root, int productID);
void printProducts(ProductNode* root);
void freeProducts(ProductNode* root);
