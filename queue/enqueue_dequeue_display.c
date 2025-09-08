#include <stdio.h>
#include <malloc.h>

struct queue
{
    int size;
    int f;
    int b;
    int *arr;
};

int isEmpty(struct queue *sp)
{
    if (sp->f == sp->b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *sp)
{
    if (sp->b == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int enqueue(struct queue *sp, int num)
{
    if (isFull(sp))
    {
        printf("Queue is full.\n");
        return -1;
    }
    else
    {
        sp->b++;
        sp->arr[sp->b] = num;
        printf("%d is enqueued \n", sp->arr[sp->b]);
        return sp->b;
    }
}

int dequeue(struct queue *sp)
{
    if (isEmpty(sp))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        sp->f++;
        int val = sp->arr[sp->f];
        printf("%d is dequeued \n", val);
        return sp->f;
    }
}

int main()
{
    int numof, value;
    struct queue *s = (struct queue *)malloc(sizeof(struct queue));
    s->size = 20;
    s->f = 0;
    s->b = 0;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // printf("%d\n", isEmpty(s));
    // printf("%d\n", isFull(s));

    s->b = enqueue(s, 10);
    s->b = enqueue(s, 20);
    s->b = enqueue(s, 30);
    s->b = enqueue(s, 40);
    s->b = enqueue(s, 50);
    s->b = enqueue(s, 60);
    s->b = enqueue(s, 70);
    s->b = enqueue(s, 80);
    s->b = enqueue(s, 90);
    s->b = enqueue(s, 100);

    printf("Queue elements are\n");
    for (int i = s->f + 1; i <= s->b; i++)
    {
        printf("%d ", s->arr[i]);
    }

    s->f = dequeue(s);
    s->f = dequeue(s);
    s->f = dequeue(s);
    s->f = dequeue(s);

    printf("Queue elements are\n");
    for (int i = s->f + 1; i <= s->b; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");

    return 0;
}