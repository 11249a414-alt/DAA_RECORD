#include <stdio.h>
void TOH(int n, char source, char auxiliary, char destination);

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    TOH(n, 'A', 'B', 'C');
    return 0;
}
void TOH(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    TOH(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    TOH(n - 1, auxiliary, source, destination);
}
