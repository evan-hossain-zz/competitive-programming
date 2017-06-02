#include<stdio.h>
#include<string.h>

int main()
{
    char inpt[20];
    int res;
    while(scanf(" %s", inpt) == 1)
    {
        if(inpt[1] == 'x')
        {
            sscanf(inpt, "%X", &res);
            printf("%d\n", res);
        }
        else
        {
            res = atoi(inpt);
            if(res < 0)
                break;
            printf("0x%X\n", res);
        }
    }
    return 0;
}
