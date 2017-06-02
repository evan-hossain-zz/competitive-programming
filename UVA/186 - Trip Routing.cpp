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
#define infinity 2147483647 >> 1

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

struct edge
{
    string route;
    int dist;
};

int nodes;
edge grid[110][110];
int pred[110][110];
map <int, string> itos;

void initialize(void);
void floyed(int n);
void path(int a, int b);

int main()
{
    char c;
    string a, b, r;
    int n;
    map <string, int> mp;
    initialize();
    while(true)
        {
            if((c = getchar()) == '\n')
                break;
            a.clear(), b.clear(), r.clear();
            a += c;
            while((c = getchar()) != ',')
                a += c;
            if(mp.find(a) == mp.end())
                {
                    mp[a] = nodes;
                    itos[nodes] = a;
                    nodes++;
                }
            while((c = getchar()) != ',')
                b += c;
            if(mp.find(b) == mp.end())
                {
                    mp[b] = nodes;
                    itos[nodes] = b;
                    nodes++;
                }
            while((c = getchar()) != ',')
                r += c;
            scanf("%d", &n);
            getchar();
            if(a != b && grid[mp[a]][mp[b]].dist > n)
                {
                    grid[mp[a]][mp[b]].dist = grid[mp[b]][mp[a]].dist = n;
                    grid[mp[a]][mp[b]].route = grid[mp[b]][mp[a]].route = r;
                }
        }
    floyed(nodes);
    while(scanf("%c", &c) == 1)
        {
            printf("\n\nFrom                 To                   Route      Miles\n");
            printf("-------------------- -------------------- ---------- -----\n");
            a.clear(), b.clear();
            a += c;
            while((c = getchar()) != ',')
                a += c;
            while(scanf("%c", &c) == 1)
                {
                    if(c == '\n')
                        break;
                    b += c;
                }
            path(mp[a], mp[b]);
            printf("                                                     -----\n");
            printf("                                          Total      %5d\n", grid[mp[a]][mp[b]].dist);
        }
    return 0;
}

void initialize(void)
{
    int i, j;
    for(i = 0; i < 105; i++)
        {
            for(j = 0; j < 105; j++)
                grid[i][j].dist = infinity;
            grid[i][i].dist = 0;
        }
}

void floyed(int n)
{
    int i, j, k;
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                {
                    if(grid[i][j].dist > grid[i][k].dist + grid[k][j].dist)
                        {
                            grid[i][j].dist = grid[i][k].dist + grid[k][j].dist;
                            pred[i][j] = k;
                        }
                }
    return;
}

void path(int a, int b)
{
    if(pred[a][b] == 0)
        {
            printf("%-20s %-20s %-10s %5d\n", itos[a].c_str(), itos[b].c_str(), grid[a][b].route.c_str(), grid[a][b].dist);
            return;
        }
    path(a, pred[a][b]);
    path(pred[a][b], b);
}
