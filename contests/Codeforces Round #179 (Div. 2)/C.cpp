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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct op
{
    LL l, r, d;
} marr[SZ];

LL arr[SZ], xy[SZ], cnt[SZ];

int main()
{
    int n, m, k, j, i, p, q;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    for(i = 1; i <= m; i++)
    {
        cin >> marr[i].l >> marr[i].r >> marr[i].d;
    }
    for(i = 1; i <= k; i++)
    {
        cin >> p >> q;
        xy[p]++, xy[q + 1]--;
    }
    LL tem = 0;
    for(i = 1; i <= m; i++)
    {
        tem += xy[i];
        xy[i] = tem;
        marr[i].d *= tem;
    }
    for(i = 1; i <= m; i++)
    {
        cnt[marr[i].l] += marr[i].d;
        cnt[marr[i].r + 1] -= marr[i].d;
    }
    tem = 0;
    for(i = 1; i <= n; i++)
    {
        tem += cnt[i];
        cnt[i] = tem;
        arr[i] += tem;
        cout << arr[i] << ' ';
    }
    return 0;
}

