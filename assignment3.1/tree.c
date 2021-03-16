//
// Created by Denisa on 3/14/2020.
//

#include "tree.h"

NodeT *createTreeNode(char *c) {
    NodeT *node = (NodeT *) malloc(sizeof(NodeT));
    node->id = (char *) malloc(sizeof(char));
    node->left = NULL;
    node->right = NULL;
    strcpy(node->id, c);
    return node;
}

NodeT *createBinTree() {
    char *c = (char *) malloc(sizeof(char));
    scanf("%s", c);
    if (strcmp(c, "*") == 0) {
        return NULL;
    }
    NodeT *currentNode = createTreeNode(c);
    currentNode->left = createBinTree();
    currentNode->right = createBinTree();
    free(c);
    return currentNode;
}

int getMaxDepth(NodeT *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = getMaxDepth(root->left);
        int rightDepth = getMaxDepth(root->right);
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

    }
}

void prettyPrint(NodeT *currentRoot, int level) {
    if (currentRoot != NULL) {
        for (int i = 0; i < level; i++) {
            printf(" ");
        }
        printf("%s", currentRoot->id);
        prettyPrint(currentRoot->left, level + 1);
        prettyPrint(currentRoot->right, level + 1);
    }
}

void postorder(NodeT *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->id);
    }
}

void inorder(NodeT *currentRoot) {
    if (currentRoot != NULL) {
        inorder(currentRoot->left);
        printf("%s ", currentRoot->id);
        inorder(currentRoot->right);
    }
}

void preorder(NodeT *root) {
    if (root != NULL) {
        printf("%s ", root->id);
        preorder(root->left);
        preorder(root->right);
    }
}
int search(NodeT *root, char *content) {
    if (root == NULL) {
        return 0;
    } else {
        if (strcmp(root->id, content) == 0) {
            return 1;
        } else {
            if (strcmp(root->id, content) > 0) {
                return search(root->left, content);
            } else {
                return search(root->right, content);
            }
        }
    }
}

