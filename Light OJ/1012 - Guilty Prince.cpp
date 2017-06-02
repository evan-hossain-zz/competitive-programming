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
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};

using namespace std;

char grid[25][25];

int mx, w, h;
void dfs(int rw, int cl);

int main()
{
    int test, i, j, sr, sc;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        scanf("%d %d", &w, &h);
        mx = 1;
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < w; j++)
            {
                scanf(" %c",&grid[i][j]);
                if(grid[i][j] == '@')
                    sr = i,sc = j;
            }
        }
        grid[sr][sc] = '#';
        dfs(sr, sc);
        printf("Case %d: %d\n", kase, mx);
    }
    return 0;
}

void dfs(int rw, int cl)
{
    int nr, nc;
    for(int p = 0; p < 4; p++)
    {
        nr = rw + row[p];
        nc = cl + col[p];
        if(nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] == '.')
        {
            grid[nr][nc] = '#';
            mx++;
            dfs(nr, nc);
        }
    }
}
