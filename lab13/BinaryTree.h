#pragma once
#include "Functions.h"

typedef struct binaryTree {
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
} binaryTree;

void addElement(binaryTree **root, binaryTree *element);
void treeVisualisation(binaryTree *root, int pos);
void deleteElement(binaryTree **root, int data);
int findLastPositive(binaryTree *node, int currentLevel, int lastPositiveLevel);
void createTree(binaryTree** root);