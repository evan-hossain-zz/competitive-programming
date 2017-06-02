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

LL segtree[SZ * 3], beg, en, sum;
LL add[SZ * 3];

int main()
{
    int n, q, t, i, c, val;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++)
    {
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", kase);
        memset(segtree, 0, n * 24);
        memset(add, 0, n * 24);
        for(i = 0; i < q; i++)
        {
            scanf(" %d", &c);
            if(!c)
            {
                scanf("%d %d %d", &beg, &en, &val);
                beg++, en++;
                lazy_update(1, n, 1, val);
            }
            else
            {
                scanf("%d %d", &beg, &en);
                beg++, en++;
                printf("%lld\n", query(1, n, 1));
            }
        }
    }
    return 0;
}

void lazy_update(int lef, int rig, int cur, int val)
{
    if(add[cur])
    {
        segtree[cur] += (rig - lef + 1) * add[cur];
        if(lef != rig)
        {
            add[cur << 1] += add[cur];
            add[(cur << 1) + 1] += add[cur];
        }
        add[cur] = 0;
    }
    if(lef > en || rig < beg)
        return;
    if(lef >= beg && rig <= en)
    {
        segtree[cur] += (rig - lef + 1) * val;
        if(rig != lef)
        {
            add[cur << 1] += val;
            add[(cur << 1) + 1] += val;
        }
        return;
    }
    lazy_update(lef, (lef + rig) >> 1, cur << 1, val);
    lazy_update(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1, val);
    segtree[cur] = segtree[cur << 1] + segtree[(cur << 1) + 1];
}

LL query(int lef, int rig, int cur)
{
    if(add[cur])
    {
        segtree[cur] += (rig - lef + 1) * add[cur];
        if(lef != rig)
        {
            add[cur << 1] += add[cur];
            add[(cur << 1) + 1] += add[cur];
        }
        add[cur] = 0;
    }
    if(lef > en || rig < beg)
        return 0;
    if(lef >= beg && rig <= en)
        return segtree[cur];
    return query(lef, (lef + rig) >> 1, cur << 1) + query(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1);
}
