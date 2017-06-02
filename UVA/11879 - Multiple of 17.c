#include<stdio.h>
#include<string.h>

int main()
{
    char num[150];
    register int res, i, l;
    while(scanf(" %s", num) == 1)
    {
        if(strcmp(num, "0") == 0) break;
        l = strlen(num);
        res = 0;
        for(i = 0; i < l; i++)
        {
            res = (res * 10 + num[i] - '0') % 17;
        }
        if(res == 0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
