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

int beg, en, arr[SZ], segtree[SZ * 3], mn;

int build(int b, int e, int cur);
void query(int curntbeg, int curntend, int cur);

int main()
{
    int n, q, i, test;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        scanf("%d %d", &n, &q);
        for(i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        beg = 1, en = n;
        build(1, n, 1);
        printf("Case %d:\n", kase);
        for(i = 1; i <= q; i++)
        {
            scanf("%d %d", &beg, &en);
            mn = SZ;
            query(1, n, 1);
            printf("%d\n", mn);
        }
    }
    return 0;
}

int build(int b, int e,int cur)
{
    if(b == e)
        return segtree[cur] = arr[b];
    return segtree[cur] = min(build(b, (b + e) >> 1, cur << 1), build(((b + e) >> 1) + 1 , e, (cur << 1) + 1));
}

void query(int curntbeg, int curntend, int cur)
{
    if(curntbeg > en || curntend < beg)
        return;
    if(curntbeg >= beg && curntend <= en)
    {
        mn = min(segtree[cur], mn);
        return;
    }
    query(curntbeg, (curntbeg + curntend) >> 1, cur << 1);
    query(((curntbeg + curntend) >> 1) + 1, curntend, (cur << 1) + 1);
    return;
}
