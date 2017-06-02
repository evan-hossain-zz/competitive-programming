#include <stdio.h>
#include <string.h>


int main()
{
    char string[100];
    int i, l, cnt, j, limit, test;
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", string);
        l = strlen(string);
        cnt = 0;
        for(i = 0; i < l - 1; i++)
        {
            if(string[0] == string[i + 1] && (l % (i + 1) == 0))
            {
                for(j = i + 1; j < l; j++)
                {
                    if(string[j] != string[j % (i + 1)])
                        break;
                }
                if(j == l)
                {
                    cnt = i + 1;
                    break;
                }
            }
        }
        if(cnt == 0) cnt = l;
        printf("%d\n", cnt);
        if(test != 0)
            printf("\n");
    }
    return 0;
}
