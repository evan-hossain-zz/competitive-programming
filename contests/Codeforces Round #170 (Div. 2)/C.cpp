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
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int par[1000], cnt;

int find_par(int node);
void make_set(int a, int b);

int main()
{
    map <int, int> m;
    int n, i, j, l, f, c;
    cin >> n >> l;
    cnt = l;
    for(i = 1; i <= n; i++)
        par[i] = 200 + i;
    for(i = 201; i <= 200 + n; i++)
    {
        cin >> f;
        while(f--)
        {
            cin >> c;
            make_set(i, c);
        }
    }
    for(i = 1; i <= l; i++)
        cout << par[i] << endl;
//    cout << cnt;
    return 0;
}

int find_par(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_par(par[node]);
}

void make_set(int a, int b)
{
    int u = find_par(a);
    int v = find_par(b);
    if(u == v)
        return;
    cout << u << ' ' << v << endl;
    par[u] = v;
}
