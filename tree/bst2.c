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

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (root->data < key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

void insertInBST(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("\nCan't insert %d in the Tree %d exsist\n", key, key);
            return;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct node *new = createNode(key);
    if (prev->data < key)
    {
        prev->right = new;
    }
    else
    {
        prev->left = new;
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

    printf("Before Insertion\n");
    inOrderTraversal(p);
    insertInBST(p, 44);
    printf("\n");
    printf("After Insertion\n");
    inOrderTraversal(p);

    // struct node *sp = search(p, 100);
    // if (sp != NULL)
    // {
    //     printf("\n\n%d found\n", sp->data);
    // }
    // else
    // {
    //     printf("\n\n%d not found\n", 100);
    // }
    return 0;
}