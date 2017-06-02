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

int beg, en, res;
char c;
bool str[SZ];
bool segtree[SZ * 3];

void build(int lef, int rig, int cur);
void rangeupdate(int lef, int rig, int cur);
void query(int lef, int rig, int indx, int cur);

int main()
{
    int n, i, q, test, kase, chek;
    scanf("%d ", &test);
    string s;
    for(kase = 1; kase <= test; kase++)
        {
            memset(segtree, 0, sizeof(segtree));
            cin >> s;
            for(int k = 0; k < s.size(); k++)
                str[k + 1] = s[k] - '0';
            n = s.size();
            scanf("%d ", &q);
            build(1, n, 1);
            printf("Case %d:\n", kase);
            for(i = 0; i < q; i++)
            {
                scanf(" %c", &c);
                if(c == 'I')
                {
                    scanf("%d %d", &beg, &en);
                    rangeupdate(1, n, 1);
                }
                else if(c == 'Q')
                {
                    scanf("%d", &chek);
                    query(1, n, chek, 1);
                    printf("%d\n", res);
                }
            }
        }
    return 0;
}

void build(int lef, int rig, int cur)
{
    if(lef == rig)
        {
            segtree[cur] = str[lef];
            return;
        }
    build(lef, (lef + rig) >> 1, cur << 1);
    build(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1);
}

void rangeupdate(int lef, int rig, int cur)
{
    if(lef > en || rig < beg)
        return;
    if(lef >= beg && rig <= en)
        {
            segtree[cur] = !segtree[cur];
            return;
        }
    rangeupdate(lef, (lef + rig) >> 1, cur << 1);
    rangeupdate(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1);
}

void query(int lef, int rig, int indx, int cur)
{
    if(lef == rig)
    {
        res = segtree[cur];
        return;
    }
    if(segtree[cur])
    {
        segtree[cur] = !segtree[cur];
        segtree[cur << 1] = !segtree[cur << 1];
        segtree[(cur << 1) + 1] = !segtree[cur * 2 + 1];
    }
    int mid = lef + rig >> 1;
    if(indx <= mid)
        query(lef, mid, indx, cur << 1);
    else
        query(mid + 1, rig, indx, (cur << 1) + 1);
}
