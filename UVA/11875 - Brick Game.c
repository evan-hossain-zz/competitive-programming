#include<stdio.h>

int main()
{
    int tst, n, age[100], i, players, j, res;
    scanf("%d", &tst);
    for(i = 1; i <= tst; i++)
    {
        scanf("%d", &players);
        for(j = 1; j <= players; j++)
        {
            scanf("%d", &age[j]);
        }
        res = players / 2 + 1;
        printf("Case %d: %d\n",i, age[res]);
    }
    return 0;
}
