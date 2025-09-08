#include<stdio.h>

int main()
{
    int n1, n2, sum = 0;

    printf("\nEnter the value of n1\n");
    scanf("%d", &n1);
    printf("Enter the value of n2\n");
    scanf("%d", &n2);

    sum = n1 + n2;
    printf("Sum of n1 and n2 is: %d\n", sum);
    return 0;
}