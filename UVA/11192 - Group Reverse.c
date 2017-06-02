#include<stdio.h>
#include<string.h>

int main()
{
    int num, i, ls, j;
    char string[110], revrs[12];
    while(scanf("%d", &num) == 1 && num != 0)
    {
        scanf(" %[^\n]", string);
        ls = strlen(string);
        num = ls / num;
        for(i = 0; i < ls; i += num)
        {
            for(j = num + i - 1; j >= i; j--)
            {
                printf("%c", string[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
