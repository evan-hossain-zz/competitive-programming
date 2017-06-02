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
#define infinity 21474
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[SZ], beg, en, zero, negetive;

struct info
{
    int negetive, zero;
}segtree[SZ << 2];

void build(int lef, int rig, int cur);
void query(int lef, int rig, int cur);
void update(int lef, int rig, int indx, int cur, int amount);

int main()
{
    int n, q, i, pos, amount;
    char c;
    while(scanf("%d %d", &n, &q) == 2)
    {
        string s;
        for(i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        build(1, n, 1);
        for(i = 0; i < q; i++)
        {
            scanf(" %c", &c);
            switch(c)
            {
            case 'P':
                scanf("%d %d", &beg, &en);
                negetive = zero = 0;
                query(1, n, 1);
                if(zero)
                    s += '0';
                else if(negetive % 2 != 0)
                    s += '-';
                else
                    s += '+';
                break;
            case 'C':
                scanf("%d %d", &pos, &amount);
                update(1, n, pos, 1, amount);
                break;
            }
        }
        printf("%s\n", s.c_str());
    }
    return 0;
}

void build(int lef, int rig, int cur)
{
    if(lef == rig)
    {
        if(arr[lef] < 0)
        {
            segtree[cur].negetive = 1;
            segtree[cur].zero = 0;
            return;
        }
        if(arr[lef] == 0)
        {
            segtree[cur].negetive = 0;
            segtree[cur].zero = 1;
            return;
        }
        segtree[cur].negetive = 0;
        segtree[cur].zero = 0;
        return;
    }
    build(lef, (lef + rig) >> 1, cur << 1);
    build(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1);
    segtree[cur].negetive = segtree[cur << 1].negetive + segtree[(cur << 1) + 1].negetive;
    segtree[cur].zero = segtree[cur << 1].zero + segtree[(cur << 1) + 1].zero;
}

void query(int lef, int rig, int cur)
{
    if(lef > en || rig < beg)
        return;
    if(lef >= beg && rig <= en)
    {
        if(segtree[cur].zero > 0)
            zero = 1;
        else
            negetive += segtree[cur].negetive;
        return;
    }
    query(lef, (lef + rig) >> 1, cur << 1);
    query(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1);
}

void update(int lef, int rig, int indx, int cur, int amount)
{
    if(lef == rig)
    {
        if(amount < 0)
        {
            segtree[cur].negetive = 1;
            segtree[cur].zero = 0;
        }
        else if(amount == 0)
        {
            segtree[cur].negetive = 0;
            segtree[cur].zero = 1;
        }
        else
        {
            segtree[cur].negetive = 0;
            segtree[cur].zero = 0;
        }
        return;
    }
    int mid = lef + rig >> 1;
    if(indx <= mid)
        update(lef, mid, indx, cur << 1, amount);
    else
        update(mid + 1, rig, indx, (cur << 1) + 1, amount);
    segtree[cur].negetive = segtree[cur << 1].negetive + segtree[(cur << 1) + 1].negetive;
    segtree[cur].zero = segtree[cur << 1].zero + segtree[(cur << 1) + 1].zero;
}
