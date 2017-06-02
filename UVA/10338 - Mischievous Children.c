#include<stdio.h>
#include<string.h>


int comp(const void *a, const void *b)
{
    int *p = (int *) a;
    int *q = (int *) b;
    return (*q - *p);
}
int main()
{
    long long n, res, cnt, j;
    char array[22];
    int tst, i, l, data = 0;
    scanf("%d", &tst);
    while(tst--)
    {
        res = n = 1;
        cnt = 0;
        scanf(" %[^\n]", array);
        l = strlen(array);
        qsort(array, l, sizeof(char), comp);
        printf("%s", array);
        for(j = l; j > 1; j--)
            n *= j;
        printf("Data set %d: %lld\n", ++data, n / res);
    }
    return 0;
}
