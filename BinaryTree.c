#include<stdio.h>   
#include<string.h>
#include<stdlib.h>

struct TREE {
    char * parent;
    int num;
    struct TREE * leftchild;
    struct TREE * rightchild;
};

void searchTree(struct TREE * tree, int s);
struct TREE * addTree(struct TREE * tree, int num);
void printTree(struct TREE * tree);

int main()
{
    int num;
    struct TREE * root;
    root = NULL;

    while (scanf("%d", &num) && num != 0)
    {
        root = addTree(root, num);
    }
    //printTree(root);
    int n = 0;
    scanf("%d", &n);
    searchTree(root, n);

    return 0;
}

struct TREE * addTree(struct TREE * tree, int num)
{
    if (tree == NULL)
    {
        tree = (struct TREE *)malloc(1 * sizeof(struct TREE));
        tree->num = num;
        tree->leftchild = NULL;
        tree->rightchild = NULL;
    }

    else if (tree != NULL)
    {
        if (num < tree->num)
            tree->leftchild = addTree(tree->leftchild, num);
        else if (num > tree->num)
            tree->rightchild = addTree(tree->rightchild, num);
    }

    return tree;
}

void printTree(struct TREE * root)
{
    if (root != NULL)
    {
        printf("%d\n", root->num);
        printTree(root->leftchild);
        printTree(root->rightchild);
    }

    return;
}

void searchTree(struct TREE * tree, int s)
{
    if (tree == NULL)
    {
        printf("Not found");
    }

    else if (tree->num > s)
    {
        printf("%d\n", tree->num);
        searchTree(tree->leftchild, s);
    }

    else if (tree->num < s)
    {
        printf("%d\n", tree->num);
        searchTree(tree->rightchild, s);
    }

    else if (tree->num == s)
    {
        printf("%d found\n", s);
    }
}

