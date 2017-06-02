#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

char grid[32][32][32], col[32][32][32];
int dist[32][32][32];
int x, y, z, flag;
struct pos
{
    int r;
    int c;
    int l;
};
queue <pos> q;
pos s;

void bfs(pos in);

int main()
{
    int i, j, k;
    while(cin >> z >> y >> x && x && y && z)
    {
        memset(grid, -1, sizeof(grid));
        memset(dist, 0, sizeof(dist));
        memset(col, -1, sizeof(col));
        flag = 1;
        for(i = 0; i < z; i++)
            for(j = 0; j < y; j++)
                for(k = 0; k < x; k++)
                {
                    cin >> grid[i][j][k];
                    if(grid[i][j][k] == 'S')
                    {
                        col[i][j][k] = 0;
                        s.l = i;
                        s.r = j;
                        s.c = k;
                    }
                }
        bfs(s);
        if(flag)
            cout << "Trapped!\n";
    }
    return 0;
}

void bfs(pos in)
{
    int l, m, n;
    q.push(in);
    while(!q.empty())
    {
        in = q.front();
        q.pop();
        l = in.l;
        m = in.r;
        n = in.c;
        if(grid[l][m][n] == 'E' && col[l][m][n] == 0)
        {
            cout << "Escaped in " <<\
                 dist[l][m][n] << " minute(s).\n";
            if(!q.empty())
            {
                while(!q.empty())
                    q.pop();
            }
            flag = 0;
            return;
        }
        if(m - 1 >= 0)
        {
            if((grid[l][m - 1][n] != '#')
                    && col[l][m - 1][n] != 0)
            {
                col[l][m - 1][n] = 0;
                in.l = l;
                in.r = m - 1;
                in.c = n;
                q.push(in);
                dist[l][m - 1][n] = dist[l][m][n] + 1;
            }
        }
        if(n - 1 >= 0)
        {
            if((grid[l][m][n - 1] != '#')
                    && col[l][m][n - 1] != 0)
            {
                col[l][m][n - 1] = 0;
                in.l = l;
                in.r = m;
                in.c = n - 1;
                q.push(in);
                dist[l][m][n - 1] = dist[l][m][n] + 1;
            }
        }
        if(n + 1 < x)
        {
            if((grid[l][m][n + 1] != '#')
                    && col[l][m][n + 1] != 0)
            {
                col[l][m][n + 1] = 0;
                in.l = l;
                in.r = m;
                in.c = n + 1;
                q.push(in);
                dist[l][m][n + 1] = dist[l][m][n] + 1;
            }
        }
        if(m + 1 < y)
        {
            if((grid[l][m + 1][n] != '#')
                    && col[l][m + 1][n] != 0)
            {
                col[l][m + 1][n] = 0;
                in.l = l;
                in.r = m + 1;
                in.c = n;
                q.push(in);
                dist[l][m + 1][n] = dist[l][m][n] + 1;
            }
        }
        if(l - 1 >= 0)
        {
            if((grid[l - 1][m][n] != '#')
                    && col[l - 1][m][n] != 0)
            {
                col[l - 1][m][n] = 0;
                in.l = l - 1;
                in.r = m;
                in.c = n;
                q.push(in);
                dist[l - 1][m][n] = dist[l][m][n] + 1;
            }
        }
        if(l + 1 < z)
        {
            if((grid[l + 1][m][n] != '#')
                    && col[l + 1][m][n] != 0)
            {
                col[l + 1][m][n] = 0;
                in.l = l + 1;
                in.r = m;
                in.c = n;
                q.push(in);
                dist[l + 1][m][n] = dist[l][m][n] + 1;
            }
        }
    }
    return;
}
