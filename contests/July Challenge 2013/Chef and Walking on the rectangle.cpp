#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 1000000010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL grid[120][120];
int N, M;

void dfs(int r, int c)
{
//    cout << r << ' ' << c << endl;
    if((r | c) && !(r == N - 1 && c == M - 1))
        grid[r][c]++;
    if(c + 1 >= M && r + 1 < N)
        dfs(r + 1, c);
    else if(r + 1 >= N && c + 1 < M)
        dfs(r, c + 1);
    else if(r + 1 < N && c + 1 < M)
    {
        if(grid[r + 1][c] < grid[r][c + 1])
            dfs(r + 1, c);
        else
            dfs(r, c + 1);
    }
}

int main()
{
    int T, k, i, j;
    LL mx;
    scanf("%d", &T);
    while(T--)
    {
        mx = 0;
        scanf("%d %d %d", &N, &M, &k);
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++)
                grid[i][j] = 0;
        for(i = 0; i < k; i++)
            dfs(0, 0);
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++)
                mx = max(mx, grid[i][j]);
        printf("%lld\n", mx);
    }
    return 0;
}

