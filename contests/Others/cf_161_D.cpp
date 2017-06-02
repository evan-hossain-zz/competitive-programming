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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int par[SZ], flag, cnt, k, n;

int find_set(int node);
void make_set(int a, int b);
void print(int r);

int main()
{
    int i, a, b, m, j;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++)
        par[i] = i;
    flag = 1;
    for(i = 1; i <= n && flag; i++)
    {
        for(j = 1; j <= m && flag; j++)
        {
            cin >> a >> b;
            make_set(a, b);
        }
    }
    return 0;
}

int find_set(int node)
{
    if(node == par[node])
        return node;
    return par[node] = find_set(par[node]);
}

void make_set(int a, int b)
{
    int u = find_set(a);
    int v = find_set(b);
    if(u != v)
    {
        par[u] = v;
        cnt++;
    }
    else
    {
        if(cnt >= k)
            print(u);
        else
            return;
    }
}

void print(int r)
{
    int i;
    cnt = 0;
    for(i = 1; i <= n; i++)
    {
        if(par[i] == r)
            cnt++;
    }
    cout << cnt << endl;
    for(i = 1; i <= n; i++)
    {
        if(par[i] == r)
            printf("%d ", i);
        flag = 0;
    }
}
