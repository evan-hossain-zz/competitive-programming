#include<stdio.h>
#include<string.h>

int main()
{
    int i, j, k, l, m, num = 0, ara[257];
    char str[150];
    ara['>'] = 8, ara['<'] = 9,\
    ara['+'] = 10, ara['-'] = 11, ara['.'] = 12, ara[','] = 13,\
    ara['['] = 14, ara[']'] = 15;
    while(scanf("%s", &str) == 1)
    {
        num = 0;
        l = strlen(str);
        for(i = 0; i < l; i++)
        {
            num = ((num << 4) + ara[str[i]]) % 1000003;
        }
        printf("%d\n", num % 1000003);
    }
    return 0;
}
