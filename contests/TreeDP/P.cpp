#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

#define MAX 50010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int res[MAX], child[MAX], n, ans;
struct node
{
    int v;
    node *next;
}*arr[MAX], nodes[2*MAX], *root;

void dfs(int u, int prev)
{
    int v;
    child[u] = 1;
    res[u] = 0;
    for(node *p = arr[u]; p != NULL; p = p->next)
    {
        v = p->v;
        if(v == prev) continue;
        dfs(v, u);
        child[u] += child[v];
        res[u] = res[u] > child[v] ? res[u] : child[v];
    }
    res[u] = res[u] > n-child[u]? res[u] : n-child[u];
    ans = ans < res[u]? ans: res[u];
}

void add_edge(int u, int v)
{
    node *p = root++;
    p->v = v;
    p->next = arr[u];
    arr[u] = p;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int u, v, i;
    while(scanf("%d", &n) == 1)
    {
        ans = infinity;
        for(i = 1; i <= n; i++)
            arr[i] = NULL;
        root = nodes;
        for(i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        dfs(1, -1);
        u = 0;
        for(i = 1; i <= n; i++)
        {
            if(res[i] != ans) continue;
            if(u) printf(" ");
            printf("%d", i);
            u = 1;
        }
        puts("");
    }
    return 0;
}
