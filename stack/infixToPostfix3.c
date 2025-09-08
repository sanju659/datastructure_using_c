#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *data;
};

char top(struct stack *s)
{
    return s->data[s->top];
}

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, char val)
{
    if (isFull(s))
    {
        printf("Stack over flow");
    }
    else
    {
        s->top++;
        s->data[s->top] = val;
    }
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Under Flow");
        return -1;
    }
    else
    {
        char val = s->data[s->top];
        s->top--;
        return val;
    }
}

int isOperator(char val)
{
    if (val == '*' || val == '/' || val == '+' || val == '-')
    {
        return 1;
    }
    return 0;
}

int operatorPrecedence(char val)
{
    if (val == '*' || val == '/')
    {
        return 3;
    }
    else if (val == '+' || val == '-')
    {
        return 2;
    }
    return 0;
}

char *infixToPostfix(struct stack *s, char *infix)
{
    char *postfix = (char *)malloc(strlen(infix) * sizeof(char));

    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if (operatorPrecedence(infix[i]) > operatorPrecedence(top(s)))
        {
            push(s, infix[i]);
            i++;
        }
        else
        {
            postfix[j] = pop(s);
            j++;
        }
    }

    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    return postfix;
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->data = (char *)malloc(sp->size * sizeof(char));

    // char infix[20] = ("x-y/z-k*d");
    char *infix = (char *)malloc(sp->size * sizeof(char));
    printf("Enter Expression\n");
    scanf("%s", infix);

    printf("Postfix opeartion is %s\n", infixToPostfix(sp, infix));
    return 0;
}