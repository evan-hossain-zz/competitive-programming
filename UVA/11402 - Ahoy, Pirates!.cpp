#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 1024010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct node
{
    int buc, bar, command;
};
node segtree[SZ * 3];
int beg, en;
string tree;

void build(int lef, int rig, int cur);
void lazy_update(int lef, int rig, int cur, int command);
int query(int lef, int rig, int cur);
void make_tree(void)
{
    int totalpair, t, i, j;
    string tem;
    scanf("%d", &totalpair);
    for(i = 0; i < totalpair; i++)
    {
        scanf("%d", &t);
        cin >> tem;
        for(j = 0; j < t; j++)
            tree += tem;
    }
    build(0, tree.size() - 1, 1);
}

int main()
{
    int t, kase, q, i, cnt;
    char key;
    scanf("%d", &t);
    for(kase = 1; kase <= t; kase++)
    {
        cnt = 1;
        make_tree();
        scanf("%d", &q);
        for(i = 0; i < q; i++)
        {
            scanf(" %c %d %d", &key, &beg, &en);
            if(key == 'F')
                lazy_update(0, tree.size() - 1, 1, 1);
            else if(key == 'E')
                lazy_update(0, tree.size() - 1, 1, 0);
            else if(key == 'I')
                lazy_update(0, tree.size() - 1, 1, 2);
            else
                printf("Q%d: %d", cnt++, query(0, tree.size() - 1, 1);
        }
    }
    return 0;
}

void build(int lef, int rig, int cur)
{
    if(lef == rig)
    {
        if(tree[lef] == '0')
            segtree[cur].bar = 1, segtree[cur].buc = 0, segtree[cur].command = -1;
        else
            segtree[cur].bar = 0, segtree[cur].buc = 1, segtree[cur].command = -1;
        return;
    }
    int mid = (lef + rig) / 2;
    build(lef, mid, cur * 2);
    build(mid + 1, rig, cur * 2 + 1);
    segtree[cur].bar = segtree[cur * 2].bar + segtree[cur * 2 + 1].bar;
    segtree[cur].buc = segtree[cur * 2].buc + segtree[cur * 2 + 1].buc;
}

void lazy_update(int lef, int rig, int cur, int command)
{
    if(segtree[cur].command != -1)
    {
        int com = segtree[cur].command;
        if(com == 0)
            segtree[cur].bar = segtree[cur].buc = 0;
        else if(com == 1)
            segtree[cur].bar = segtree[cur].buc = 1;
        else
            swap(segtree[cur].bar, segtree[cur].buc);
        if(lef != rig)
        {
            if(com != 2)
                segtree[cur * 2].command = segtree[cur * 2 + 1].command = cur;
            else
            {
                if(segtree[cur * 2].command != -1)
                {
                    swap(segtree[cur].bar, segtree[cur].buc);
                }
            }
        }
    }
}
