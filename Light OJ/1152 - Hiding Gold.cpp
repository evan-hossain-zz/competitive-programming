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
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 410

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};

using namespace std;

int par[SZ], n, m;
bool color[SZ];
char grid[22][22];
vector <int> adj[SZ];

void make_connections(int r, int c);
int BMP(int n, int m);
int dfs(int u);

int main()
{
    int i, j, test, kase;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++) for(j = 0; j < m; j++) scanf(" %c", &grid[i][j]);
        for(i = 0; i < n; i++) for(j = 0; j < m; j++) make_connections(i, j);
    }
    return 0;
}

void make_connections(int r, int c)
{
    if(grid[r][c] == 'o')
        return;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + row[i];
        int nc = c + col[i];
        if(grid[nr][nc] == '*' && nr >= 0 && nr < n && nc >= 0 && nc < m)
            adj[nr].pub(nc);
    }
}
