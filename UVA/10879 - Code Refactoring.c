#include<stdio.h>

int n, k;
int main()
{
    int i, j, tst, t = 0;
    scanf("%d", &tst);
    while(t < tst)
    {
        scanf("%d", &k);
        printf("Case #%d: %d", ++t, k);
        for(i = 2; i < k; i++)
        {
            if(k % i == 0)
            {
                printf(" = %d * %d", i, k / i);
                break;
            }
        }
        for(i = i + 1; i < k; i++)
        {
            if(k % i == 0)
            {
                printf(" = %d * %d", i, k / i);
                break;
            }
        }
        printf("\n");
    }
    return 0;
}
