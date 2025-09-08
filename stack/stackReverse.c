#include <stdio.h>
#include <stdlib.h>

struct node
{
    int size;
    int top;
    int *arr;
};

// push in the first stack
void push(int val, struct node *s)
{
    if (s->top == s->size - 1)
    {
        printf("\nStack is full.\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
        printf("%d pushed\n", s->arr[s->top]);
    }
}

// pop for first stack
int pop(struct node *s)
{
    if (s->top == -1)
    {
        printf("stack under flow\n");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

// peek for the first stack
void peek(struct node *s, int i)
{
    if (s->top - i + 1 < 0)
    {
        printf("Invalid Operation\n");
    }
    else
    {
        printf("value at %d is %d\n", i, s->arr[s->top - i + 1]);
    }
}

// push in the second stack
void push2(int val, struct node *s)
{
    if (s->top == s->size - 1)
    {
        printf("\nStack is full.\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
        printf("%d pushed\n", s->arr[s->top]);
    }
}

// peek for the second stack
void peek2(struct node *s, int i)
{
    if (s->top - i + 1 < 0)
    {
        printf("Invalid Operation\n");
    }
    else
    {
        printf("value at %d is %d\n", i, s->arr[s->top - i + 1]);
    }
}

int main()
{
    int num;

    // initialize for the first stack
    struct node *sp = (struct node *)malloc(sizeof(struct node));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    // initialize for the second stack
    struct node *sp2 = (struct node *)malloc(sizeof(struct node));
    sp2->size = 5;
    sp2->top = -1;
    sp2->arr = (int *)malloc(sp2->size * sizeof(struct node));

    // push and peek opeartion in the first stack
    printf("How many element do you want to insert ?");
    scanf("%d", &num);
    int A[num];
    if (num <= 5 && num > 0)
    {
        printf("Enter the number\n");
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < num; i++)
        {
            push(A[i], sp);
        }

        for (int i = 1; i <= sp->top + 1; i++)
        {
            peek(sp, i);
        }
    }
    else
    {
        printf("number should be less than or equal to 5 and greater than 0");
        return 0;
    }

    // push and peek operation for the second stack
    for (int i = 0; i < num; i++)
    {
        push2(pop(sp), sp2);
    }
    for (int i = 1; i <= sp2->top + 1; i++)
    {
        peek2(sp2, i);
    }

    return 0;
}