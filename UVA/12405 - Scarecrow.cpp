#include <stdio.h>

int main()
{
    int test, i, kase = 0, cnt, l;
    char arr[110];
    scanf("%d", &test);
    while(kase < test)
    {
        scanf("%d  %s", &l, arr);
        cnt = 0;
        for(i = 0; i < l; )
        {
            if(arr[i] == '.')
            {
                cnt++;
                i += 3;
            }
            else
                i++;
        }
        printf("Case %d: %d\n", ++kase, cnt);
    }
    return 0;
}
