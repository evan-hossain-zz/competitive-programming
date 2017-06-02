#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int bfs(void);

int row[4] = {0, 1, -1, 0}, col[4] = {1, 0, 0, -1};

int m, cnt, ans;
queue <int> q;
int path[1000][1000];
char grid[1000][1000];

int main()
{
    int i, j;
    vector <int> ones;
    while(scanf("%d", &m) == 1)
    {
        ans = 0;
        for(i = 0; i < m; i++)
            for(j = 0; j < m; j++)
            {
                scanf(" %c", &grid[i][j]);
                path[i][j] = 0;
                if(grid[i][j] == '1')
                {
                    ones.push_back(i);
                    ones.push_back(j);
                }
            }
        int l = ones.size();
        for(int p = 0; p < l;)
        {
            q.push(ones[p++]);
            q.push(ones[p++]);
            ans = max(ans, bfs());
            for(i = 0; i < m; i++)
                for(j = 0; j < m; j++)
                    path[i][j] = 0;
        }
        ones.clear();
        printf("%d\n", ans);
    }
    return 0;
}

int bfs(void)
{
    int X, Y, r, c;
    while(true)
    {
        r = q.front();
        q.pop();
        c = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            X = c + col[i];
            Y = r + row[i];
            if((X >= 0 && X < m) &&
                    (Y >= 0 && Y < m))
            {
                if(path[Y][X] == 0)
                {
                    path[Y][X] = path[r][c] + 1;
                    if(grid[Y][X] == '3')
                    {
                        while(!q.empty())
                            q.pop();
                        return path[Y][X];
                    }
                    q.push(Y), q.push(X);
                }
            }
        }
    }
}
