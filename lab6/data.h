#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;      
    struct Node *right;     
} Node;


Node* insert(Node* root, int key);
Node* search(Node* root, int key);
void preorder(Node* root); 
void inorder(Node* root);  
void postorder(Node* root);
void bfs(Node* root);
void freeTree(Node* root);
int height(Node* node);
Node* deleteNode(Node* root, int key);
Node* findMin(Node* root);
Node* findMax(Node* root);
void saveToFile(Node* root, FILE* fp);
Node* loadFromFile(FILE* fp);

#endif