#include<stdio.h>


int main()
{
    int tst, n, i, j, l, flag;
    char ch, c;
    scanf("%d", &tst);
    for(i = 1; i <= tst; ++i)
    {
        if(i != 1)
            printf("\n");
        printf("Case %d:\n", i);
        scanf("%d", &n);
        getchar();
        for(j = 0; j < n; ++j)
        {
            if(j != 0)
                printf("\n");
            flag = 0;
            while(scanf("%c", &ch) == 1)
            {
                if(ch == '\n') break;
                if(ch == ' ')
                {
                    if(flag == 1)
                        continue;
                    else
                    {
                        printf(" ");
                        flag = 1;
                    }
                }
                else
                {
                    printf("%c", ch);
                    flag = 0;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
