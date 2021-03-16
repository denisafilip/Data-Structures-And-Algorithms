#include "tree.h"

int main() {
    NodeT *root = createNode(10);
    root = insert(root, 11);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 14);
    root =  insert(root, 7);
    root = insert(root, 13);
    root =  insert(root, 15);
    root =  insert(root, 16);
    root =  insert(root, 17);
    root =  insert(root, 18);
    root = insert(root, 1);
    root =  insert(root, 6);
    prettyPrint(root);
    findWithPrint(root, 8);
    /*root = delete(root, 8);
    root = delete(root, 1);
    root =  delete(root, 10);
    root = delete(root, 11);
    root = delete(root, 13);
    root = delete(root, 16);
    root = delete(root, 17);*/
    //doubleTree(root);
    //inorder(root);
    int *paths = (int *) malloc(sizeof(int) * 100);
    printPaths(root, paths, 0);
    int pathSum = 25;
    int hasPath = hasPathSum(root, pathSum);
    if (hasPath == 1) {
        printf("\n%d is path sum\n", pathSum);
    } else {
        printf("\n%d is not path sum\n", pathSum);
    }
    mirror(root);
    prettyPrint(root);
    inorder(root);
    return 0;
}