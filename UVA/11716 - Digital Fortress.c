#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char df[10001];
    int i, j, l, tst;
    float k;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf(" %[^\n]", df);
        l = strlen(df);
        k = sqrt(l);
        if(k - (int)k == 0)
        {
            for(i = 0; i < k; ++i)
            {
                for(j = i; j < l; j = j + k)
                    printf("%c", df[j]);
            }
        }
        else
            printf("INVALID");
        printf("\n");
    }
    return 0;
}
