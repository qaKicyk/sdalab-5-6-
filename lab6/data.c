#include "data.h"

Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void printCurrentLevel(Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) printf("%d ", root->key);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(Node* node) {
    if (node == NULL) return 0;
    int lheight = height(node->left);
    int rheight = height(node->right);
    return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
}

void bfs(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

Node* findMin(Node* root) {
    while (root && root->left != NULL) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right != NULL) root = root->right;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void saveToFile(Node* root, FILE* fp) {
    if (root == NULL) {
        fprintf(fp, "# ");
        return;
    }
    fprintf(fp, "%d ", root->key);
    saveToFile(root->left, fp);
    saveToFile(root->right, fp);
}

Node* loadFromFile(FILE* fp) {
    char val[20];
    if (fscanf(fp, "%s", val) == EOF || val[0] == '#') return NULL;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = atoi(val);
    newNode->left = loadFromFile(fp);
    newNode->right = loadFromFile(fp);
    return newNode;
}