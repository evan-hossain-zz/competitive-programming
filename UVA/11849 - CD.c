#include<stdio.h>

int jack[1000000];

int main()
{
    int jc, jl, cnt, i, c, j;
    while(scanf("%d %d", &jc, &jl) == 2 && (jc != 0 && jl != 0))
    {
        cnt = 0;
        i = 0;
        while(i < jc)
            scanf("%d", &jack[i++]);

        for(i = 0, j = 0; i < jl; i++)
        {
            scanf("%d", &c);
            for(; c >= jack[j] && j < jc; j++)
            {
                if(jack[j] == c)
                {
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
