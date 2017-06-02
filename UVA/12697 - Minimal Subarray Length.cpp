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

using namespace std;

#define MAX 500010
#define infinity 9999999999999999
#define LL long long
#define clr(arr, key) memset(arr, key, sizeof arr)

LL segtree[MAX * 3];

void update(int l, int r, int indx, LL val, int cur)
{
    if(l == r)
    {
        segtree[cur] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(indx <= mid)
        update(l, mid, indx, val, (cur << 1));
    else
        update(mid + 1, r, indx, val, (cur << 1) + 1);
    segtree[cur] = min(segtree[(cur << 1)], segtree[(cur << 1) + 1]);
}

int query(int l, int r, int cur, LL mn)
{
    if(l == r)
        return r;
    if(segtree[(cur << 1) + 1] <= mn)
        return query(((l + r) >> 1) + 1, r, (cur << 1) + 1, mn);
    return query(l, (l + r) >> 1, (cur << 1), mn);
}

int main()
{
    int i, test, res, n;
    LL x, sum, tem, mx;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %lld", &n, &x);
        sum = 0;
        mx = -infinity;
        res = 3 * n;
        for(i = 0; i <= res; i++)
            segtree[i] = infinity;
        for(i = 1; i <= n; i++)
        {
            scanf("%lld", &tem);
            mx = max(tem, mx);
            sum += tem;
            if(sum - x >= segtree[1])
                res = min(res, i - query(1, n, 1, sum - x));
            update(1, n, i, sum, 1);
        }
        if(res > n)
        {
            if(mx < x)
                printf("-1\n");
            else
                printf("1\n");
        }
        else
            printf("%d\n", res);
    }
    return 0;
}

