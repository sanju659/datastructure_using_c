#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void mirror(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        struct node *swap;

        mirror(root->left);
        mirror(root->right);

        swap = root->left;
        root->left = root->right;
        root->right = swap;
    }
}

int main()
{
    struct node *p = createNode(50);
    struct node *p1 = createNode(45);
    struct node *p2 = createNode(56);
    struct node *p3 = createNode(43);
    struct node *p4 = createNode(48);
    struct node *p5 = createNode(52);
    struct node *p6 = createNode(60);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    inOrderTraversal(p);
    printf("\n");
    mirror(p);
    inOrderTraversal(p);
    return 0;
}