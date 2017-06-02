#include<stdio.h>
#include<string.h>

int main()
{
    char s[1000000], t[1000000];
    int i, l, cnt, j, l2;
    while(scanf("%s %s", s, t) == 2)
    {
        l = strlen(s);
        l2 = strlen(t);
        cnt = 0;
        j = 0;
        for(i = 0; i < l; i++)
        {
            while(j < l2)
            {
                if(s[i] == t[j++])
                {
                    cnt++;
                    break;
                }
            }
        }
        if(cnt == l)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
