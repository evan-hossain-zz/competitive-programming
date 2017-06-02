#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
    char c;
    int i, j, n, m, k, cnt;
    typedef struct
    {
        char ch;
        int value;
    } data;
    double sum;
    data pc[110];
    scanf("%d", &n);
    while(n--)
    {
        sum = 0;
        scanf("%d", &k);
        for(i = 0; i < k; i++)
            scanf(" %c %d", &pc[i].ch, &pc[i].value);
        scanf("%d\n", &m);
        cnt = 0;
        while(scanf("%c", &c) == 1)
        {
            if(c == '\n')
                cnt++;
            else
            {
                for(j = 0; j < k; j++)
                {
                    if(c == pc[j].ch)
                        sum += pc[j].value;
                }
            }
            if(cnt == m) break;
        }
        printf("%.02lf$\n", sum / 100);
    }
    return 0;
}
