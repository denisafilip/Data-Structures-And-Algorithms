#include "tree.h"
#include "list.h"

int main() {
    NodeT *root = createBinTree();
    NodeL *firstFromList = getListFromTree(root);
    traverseList(firstFromList);
    root = getTreeFromList(&firstFromList);
    prettyPrint(root, 0);

    int maxDepth = getMaxDepth(root);
    printf("\n%d \n", maxDepth);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    int found = search(root, "1");
    if (found == 1) {
        printf("Yes! \n");
    } else {
        printf("No! \n");
    }
    return 0;
}