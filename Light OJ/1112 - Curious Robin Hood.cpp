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

int arr[SZ], segtree[SZ * 3], beg, en;

int build(int b, int e, int cur);
void givemoney(int lef, int rig, int indx, int cur);
void addmoney(int lef, int rig, int indx, int amount, int cur);
int total(int lef, int rig, int cur);

int main()
{
    int n, q, i, test, key, pos, amount;
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
            scanf("%d", &key);
            switch(key)
            {
            case 1:
                scanf("%d", &pos);
                givemoney(1, n, pos + 1, 1);
                break;
            case 2:
                scanf("%d %d", &pos, &amount);
                addmoney(1, n, pos + 1, amount, 1);
                break;
            case 3:
                scanf("%d %d", &beg, &en);
                beg++, en++;
                printf("%d\n", total(1, n, 1));
                break;
            }
        }
    }
    return 0;
}

int build(int lef, int rig, int cur)
{
    if(lef == rig)
        return segtree[cur] = arr[lef];
    return segtree[cur] = build(lef, (lef + rig) >> 1, cur << 1) + build(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1);
}

void givemoney(int lef, int rig, int indx, int cur)
{
    if(lef == rig)
    {
        printf("%d\n", segtree[cur]);
        segtree[cur] = 0;
        return;
    }
    int mid = lef + rig >> 1;
    if(indx <= mid)
        givemoney(lef, mid, indx, cur << 1);
    else
        givemoney(mid + 1, rig, indx, (cur << 1) + 1);
    segtree[cur] = segtree[cur << 1] + segtree[(cur << 1) + 1];
}

void addmoney(int lef, int rig, int indx, int amount, int cur)
{
    if(lef == rig)
    {
        segtree[cur] += amount;
        return;
    }
    int mid = lef + rig >> 1;
    if(indx <= mid)
        addmoney(lef, mid, indx, amount, cur << 1);
    else
        addmoney(mid + 1, rig, indx, amount, (cur << 1) + 1);
    segtree[cur] = segtree[cur << 1] + segtree[(cur << 1) + 1];
}

int total(int lef, int rig, int cur)
{
    if(lef > en || rig < beg)
        return 0;
    if(lef >= beg && rig <= en)
        return segtree[cur];
    int mid = lef + rig >> 1;
    return total(lef, mid, cur << 1) + total(mid + 1, rig, (cur << 1) + 1);
}
