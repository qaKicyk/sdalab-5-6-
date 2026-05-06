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

#endif