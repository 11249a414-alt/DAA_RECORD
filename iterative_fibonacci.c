#include <stdio.h>

int main()
{
    int n, i;
    int a = 0, b = 1, c;

    printf("Enter the term number: ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("The %dth Fibonacci term is 0", n);
        return 0;
    }

    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    printf("The %dth Fibonacci term is %d", n, b);
    return 0;
}
