#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *createnode(int value)
{
    treenode* result = malloc(sizeof(treenode));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }

    return result;
}

void printtabs(int numtabs)
{
    for (int i=0; i < numtabs; i++) {
        printf("\t");
    }
}

void printtree_rec(treenode *root, int level)
{
    if (root == NULL) {
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    printtabs(level);
    printf("value = %d\n", root->value);
    printtabs(level);
    printf("left\n");

    printtree_rec(root->left, level + 1);
    printtabs(level);
    printf("right\n");

    printtree_rec(root->right, level + 1);

    printtabs(level);
    printf("done\n");
}

void printtree(treenode *root)
{
    printtree_rec(root, 0);
}




int main (int argc, char *argv[])
{
    treenode *node1 = createnode(10);
    treenode *node2 = createnode(11);
    treenode *node3 = createnode(12);
    treenode *node4 = createnode(13);
    treenode *node5 = createnode(14);

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    printtree(node1);



    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    return 0;
}
