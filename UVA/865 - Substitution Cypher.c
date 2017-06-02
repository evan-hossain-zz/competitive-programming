#include<stdio.h>
#include<string.h>

int main()
{
    char s1[500], s2[500], st[500], ch;
    int i, tst, l1, flag, n;
    scanf("%d", &tst);
    while(tst--)
    {
        flag = 0;
        scanf(" %[^\n] %[^\n]%c", s1, s2, &ch);
        l1 = strlen(s1);
        printf("%s\n%s\n", s2, s1);
        while(scanf("%c", &ch) == 1)
        {
            flag = 0;
            if(ch == '\n' && n == 0)
            {
                printf("\n");
                n = 1;
            }
            else if(ch == '\n' && n == 1)
            {
                printf("\n");
                break;
            }
            else
            {
                for(i = 0; i < l1; i++)
                {
                    if(ch == s1[i])
                    {
                        putchar(s2[i]);
                        flag = 1;
                        n = 0;
                        break;
                    }
                }
                if(flag == 0)
                {
                    putchar(ch);
                    n = 0;
                }
            }
        }
    }
    return 0;
}
