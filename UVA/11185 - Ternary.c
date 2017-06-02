#include<stdio.h>
#include<string.h>


int main()
{
    int n, i, j, ter[25];

    while(scanf("%d", &n) == 1 && n >= 0)
    {
        i = 1;
        for(j = 0; i > 0; j++)
        {
            i = n / 3;
            ter[j] = n % 3;
            n = i;
        }
        for(i = j - 1; i >= 0; i--)
            printf("%d", ter[i]);
        printf("\n");
    }
    return 0;
}
