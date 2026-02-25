#include "tree.h"

// --- FUNGSI HELPER DASAR ---

int getHeight(struct Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalance(struct Node* n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

// --- OPERASI SEARCH ---

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->value == key) return root;
    if (key < root->value) return search(root->left, key);
    return search(root->right, key);
}

// --- FUNGSI ROTASI ---

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

// --- LOGIKA BST BIASA (NO AVL) ---

struct Node* insertBST(struct Node* node, int value) {
    if (node == NULL) return createNode(value);
    if (value < node->value) node->left = insertBST(node->left, value);
    else if (value > node->value) node->right = insertBST(node->right, value);
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    return node;
}

struct Node* deleteBST(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->value) root->left = deleteBST(root->left, key);
    else if (key > root->value) root->right = deleteBST(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) { temp = root; root = NULL; }
            else *root = *temp;
            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteBST(root->right, temp->value);
        }
    }
    if (root == NULL) return root;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    return root;
}

// --- LOGIKA AVL (WITH SELF-BALANCING) ---

struct Node* insertAVL(struct Node* node, int value) {
    if (node == NULL) return createNode(value);
    if (value < node->value) node->left = insertAVL(node->left, value);
    else if (value > node->value) node->right = insertAVL(node->right, value);
    else return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && value < node->left->value) return rightRotate(node);
    if (balance < -1 && value > node->right->value) return leftRotate(node);
    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct Node* deleteAVL(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->value) root->left = deleteAVL(root->left, key);
    else if (key > root->value) root->right = deleteAVL(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) { temp = root; root = NULL; }
            else *root = *temp;
            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteAVL(root->right, temp->value);
        }
    }
    if (root == NULL) return root;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// --- VISUALISASI ---

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

void displayAVL(struct Node* root, char* prefix, bool isLeft) {
    if (root == NULL) return;
    printf("%s%s[%d]\n", prefix, (isLeft ? "├── " : "└── "), root->value);
    char newPrefix[255];
    sprintf(newPrefix, "%s%s", prefix, (isLeft ? "│   " : "    "));
    if (root->left || root->right) {
        if (root->left) displayAVL(root->left, newPrefix, true);
        else printf("%s├── [NULL]\n", newPrefix);
        if (root->right) displayAVL(root->right, newPrefix, false);
        else printf("%s└── [NULL]\n", newPrefix);
    }
}