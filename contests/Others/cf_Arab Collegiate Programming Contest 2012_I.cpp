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

int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int uni, n, m, color[105];

void check(int r, int c);

int grid[110][110];
int main()
{
    int i, j;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> grid[i][j];
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            check(i, j);
    cout << uni;
    return 0;
}

void check(int r, int c)
{
    int nr, nc, cnt = 0;
    for(int i = 0; i < 8; i++)
        {
            nr = row[i] + r;
            nc = col[i] + c;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && color[grid[nr][nc]] == 0)
            {
                if(grid[nr][nc] > -1 && grid[nr][nc] == grid[r][c])
                {
                    color[grid[nr][nc]] = 1;
                    cnt++;
                }
        }
        }
    if(cnt > 0)
        uni++;
}
