#include "BinaryTree.h"

void addElement(binaryTree **root, binaryTree *element) {
    binaryTree *lastNode = *root;
    if (element) {
        while (lastNode) {
            if (element->data < lastNode->data) {
                if (lastNode->left) lastNode = lastNode->left;
                else {
                    lastNode->left = element; return;
                }
            } else if (element->data > lastNode->data) {
                if (lastNode->right) lastNode = lastNode->right;
                else {
                    lastNode->right = element; return;
                }
            }
        }
        *root = element;
    }
}

void createTree(binaryTree **root) {
    puts("Enter count of nodes:");
    int n = tryInt(true);

    puts("Enter elements:");
    for (int i = 0; i < n; ++i) {
        binaryTree *element = (binaryTree*)malloc(sizeof(binaryTree));
        element->data = tryInt(false);
        element->right = element->left = NULL;
        addElement(root, element);
    }
}

void printTree(binaryTree *root) {
    if (root) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

void deleteElement(binaryTree **root, int data) {
    if (!*root || !(*root)->left && !(*root)->right) {
        puts("Element was not found");
    } else {
        if ((*root)->left && (*root)->left->data == data || (*root)->right && (*root)->right->data == data) {
            binaryTree *deletedNode;
            if ((*root)->left && (*root)->left->data == data) {
                deletedNode = (*root)->left;
                (*root)->left = NULL;
            } else {
                deletedNode = (*root)->right;
                (*root)->right = NULL;
            }
            addElement(root, deletedNode->left);
            addElement(root, deletedNode->right);
            free(deletedNode);
        } else if ((*root)->data > data && (*root)->left) {
            deleteElement(&(*root)->left, data);
        } else if ((*root)->data < data && (*root)->right)
            deleteElement(&(*root)->right, data);
    }
}

int findLastPositive(binaryTree *node, int currentLevel, int lastPositiveLevel) {
    if (node) {
        int nextLevel = currentLevel + 1, last = lastPositiveLevel;
        if (node->data > 0) last = currentLevel;
        int leftDeepest = findLastPositive(node->left, nextLevel, last);
        int rightDeepest = findLastPositive(node->right, nextLevel, last);
        return leftDeepest > rightDeepest ? leftDeepest : rightDeepest;
    } else return lastPositiveLevel;
}