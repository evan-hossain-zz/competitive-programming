#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 80

int main()
{
    int n, i, len, tst;
    char ans[SIZE], res;
    scanf("%d", &tst);
    for(i = 0; i < tst; i++)
    {
        scanf("%d", &n);
        res = (((((n * 567) / 9) + 7492) * 235) / 47) - 498;
        printf("%d", res);
        itoa(res, ans, 10);

        len = strlen(ans);

    }
}

