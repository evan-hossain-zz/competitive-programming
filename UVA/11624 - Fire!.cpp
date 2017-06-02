#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define SZ 1010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};

using namespace std;

queue <int> q;
char grid[SZ][SZ];
int fire[SZ][SZ], jane[SZ][SZ], N, M;

int bfs(void)
{
    int nodex, nodey, i, newrow, newcol;
    while(!q.empty())
    {
        nodex = q.front(), q.pop();
        nodey = q.front(), q.pop();
        for(i = 0; i < 4; i++)
        {
            newrow = nodex + row[i];
            newcol = nodey + col[i];
            if(grid[newrow][newcol] == '#' || grid[newrow][newcol] == 'F' || newrow < 0 || newrow == N || newcol < 0 || newcol == M)
                continue;
            if(grid[nodex][nodey] == 'F' && grid[newrow][newcol] != 'J')
            {
                grid[newrow][newcol] = 'F';
                q.push(newrow), q.push(newcol);
            }
            else if(grid[nodex][nodey] == 'J' && grid[newrow][newcol] == '.')
            {
                grid[newrow][newcol] = 'J';
                jane[newrow][newcol] = 1 + jane[nodex][nodey];
                q.push(newrow), q.push(newcol);
            }
        }
        if(((nodex == N - 1 || nodex == 0) ||
        (nodey == M - 1 || nodey == 0)) &&
        grid[nodex][nodey] == 'J')
        {
            while(!q.empty()) q.pop();
            return jane[nodex][nodey];
        }
    }
    return infinity;
}

int main()
{
    int test, kase, i, j, ans, x, y;
    scanf("%d", &test);
    char c;
    while(test--)
    {
        scanf("%d %d", &N, &M);
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                scanf(" %c", &c);
                grid[i][j] = c;
                if(c == 'F')
                {
                    q.push(i), q.push(j);
                }
                if(c == 'J')
                    x = i, y = j;
            }
        }
        jane[x][y] = 1;
        q.push(x), q.push(y);
        ans = bfs();
        if(ans == infinity)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
