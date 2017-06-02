#include<stdio.h>

int main()
{
    int i, j, k, a, f, tst, flag = 1;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d %d", &a, &f);
        for(i = 0; i < f; ++i)
        {
            for(j = 1; j <= a; j++)
            {
                for(k = 1; k <= j; k++)
                    printf("%d", j);
                printf("\n");
            }
            for(j = a - 1; j >= 1; j--)
            {
                for(k = 1; k <= j; k++)
                    printf("%d", j);
                printf("\n");
                if(j == 1 && tst == 0 && i == f - 1)
                    flag = 0;
            }
            if(flag != 0 && i != f)
            printf("\n");
        }
    }
    return 0;
}
