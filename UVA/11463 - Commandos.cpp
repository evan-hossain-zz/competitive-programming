#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t, n, r, u, v, s, d, i, j, k, c;
    int path[110][110];
    scanf("%d", &t);
    for(c = 1; c <= t; c++)
    {
        scanf("%d %d", &n, &r);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                path[i][j] = 9000000;
        while(r--)
        {
            scanf("%d %d", &u, &v);
            path[u][v] = 1;
            path[v][u] = 1;
            path[u][u] = path[v][v] = 0;
        }
        scanf("%d %d", &s, &d);
        for(k = 0; k < n; k++)
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                    path[i][j] = min(path[i][j]\
                                     ,path[i][k] + path[k][j]);
        j = i =0;
        for(k = 0; k < n; k++)
        {
            i = max(j, path[s][k] + path[d][k]);
            if(i < 9000000)
                j = i;
        }
        printf("Case %d: %d\n", c, j);
    }
    return 0;
}
