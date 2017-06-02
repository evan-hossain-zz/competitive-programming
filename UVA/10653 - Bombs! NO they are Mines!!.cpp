#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int path[1010][1010];
char grid[1010][1010];
int row[4] = {0, 1, -1, 0}, col[4] = {1, 0, 0, -1};
int maR, maC, er, ec;
queue <int> q;

int bfs(void);

int main()
{
    int i, j, no_of_rows, no_of_cols, Rn, Cn, sr, sc;
    while(scanf("%d %d", &maR, &maC) == 2 && maR)
    {
        scanf("%d", &no_of_rows);
        while(no_of_rows--)
        {
            scanf("%d", &Rn);
            scanf("%d", &no_of_cols);
            for(i = 0; i < no_of_cols; i++)
            {
                scanf("%d", &Cn);
                grid[Rn][Cn] = 1;
            }
        }
        scanf("%d %d", &sr, &sc);
        scanf("%d %d", &er, &ec);
        q.push(sr), q.push(sc);
        printf("%d\n", bfs());
        for(i = 0; i <= maR; i++)
            for(j = 0; j <= maC; j++)
            {
                grid[i][j] = 0;
                path[i][j] = 0;
            }
    }
    return 0;
}

int bfs(void)
{
    int R, C, paR, paC, i;
    while(true)
    {
        paR = q.front();
        q.pop();
        paC = q.front();
        q.pop();
        for(i = 0; i < 4; i++)
        {
            R = paR + row[i];
            C = paC + col[i];
            if((R >= 0 && R < maR) &&
            (C >= 0 && C < maC) &&
            (grid[R][C] != 1 && path[R][C] == 0))
            {
                path[R][C] = path[paR][paC] + 1;
                if(R == er && C == ec)
                {
                    while(!q.empty())
                        q.pop();
                    return path[R][C];
                }
                q.push(R), q.push(C);
            }
        }
    }
}
