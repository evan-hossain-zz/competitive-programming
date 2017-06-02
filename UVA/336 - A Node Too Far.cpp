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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

long long int grid[40][40];
int nodes;

void initialize(int n);
void floyed(int n);

//int bfs(int rw, int cl);

int main()
{
    //out;
    map <int, int> mp;
    int i, j, n, a, b, cnt, kase = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        nodes = 0;
        initialize(35);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            if(mp.find(a) == mp.end())
                mp[a] = nodes++;
            if(mp.find(b) == mp.end())
                mp[b] = nodes++;
            if(a != b)
                grid[mp[a]][mp[b]] = grid[mp[b]][mp[a]] = 1;
        }
        floyed(nodes);
        while(scanf("%d %d", &a, &b) == 2 && (a | b))
        {
            cnt = 0;
            for(i = 0; i < nodes; i++)
            {
                if(grid[mp[a]][i] > b)
                    cnt++;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++kase, cnt, a, b);
        }
        mp.clear();
    }
    return 0;
}

void initialize(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            grid[i][j] = infinity;
        grid[i][i] = 0;
    }
    return;
}

void floyed(int n)
{
    int i, j, k;
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
    return;
}
