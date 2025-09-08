#include<stdio.h>

int main()
{
    int rear, size, op;
    printf("Enter the value of rear\n");
    scanf("%d", &rear);
    printf("Enter the value of size\n");
    scanf("%d", &size);
    op = ((rear+1) % size);
    printf("%d\n", op);
    return 0;
}