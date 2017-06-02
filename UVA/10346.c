#include<stdio.h>

int main()
{
    int n, k, i, j, rem;
    while(scanf("%d %d", &n, &k) == 2)
    {
        j = 0;
        i = 1;
        rem = n;
        while(i)
        {
            i = n / k;
            j = j + i;
            n = i + n%k;
        }
        printf("%d\n", rem + j);
    }
    return 0;
}
