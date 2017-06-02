#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char str[100010], temp[1010];
    int i, l, test, n, j, ls, lt, cnt, k;
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", str);
        ls = strlen(str);
        scanf("%d", &n);
        while(n--)
        {
            cnt = 0;
            scanf(" %s", temp);
            lt = strlen(temp);
            for(i = 0, j = 0; i < ls; i++)
            {
                if(str[i] == temp[j])
                {
                    cnt++;
                    j++;
                }
                else
                {
                    cnt = 0;
                    j = 0;
                }
                if(cnt == lt)break;
            }
            if(cnt == lt)
                printf("y\n");
            else
                printf("n\n");
        }
    }
    return 0;
}
