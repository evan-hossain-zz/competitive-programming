#include <stdio.h>
#include <string.h>


int main()
{
    char string[1000010];
    int i, l, cnt, j, limit;
    while(gets(string))
    {
        if(strcmp(".", string) == 0) break;
        l = strlen(string);
        cnt = 1;
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
                    cnt = l / (i + 1);
                    break;
                }
            }
        }

        printf("%d\n", cnt);
    }
    return 0;
}
