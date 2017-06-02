#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;
struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> e;
vector <int> vc[405];
map <string, int> m;

int par[405], total, color[405][405], cnt;

int find_set(int node);
void mst(int n);
void dfs(int node);

int main()
{
    int c, s, w, i;
    string str, sstr;
    edge t;
    while(scanf("%d %d", &c, &s) == 2 && (c | s))
    {
        for(i = 0; i < c; i++)
        {
            cin >> str;
            m[str] = i;
            par[i] = i;
        }
        for(i = 0; i < s; i++)
        {
            cin >> str >> sstr >> w;
            t.u = m[str], t.v = m[sstr], t.w = w;
            e.pub(t);
        }
        total = 0;
        mst(c);
        cin >> str;
        cnt = c - 1;
        dfs(m[str]);
        if(!cnt)
            printf("%d\n", total);
        else
            printf("Impossible\n");
        for(i = 0; i < c; i++)
        {
            for(s = 0; s < c; s++)
                color[i][s] = 0;
            vc[i].clear();
        }
        e.clear();
        m.clear();
    }
    return 0;
}

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

void mst(int n)
{
    int cnt = n - 1, u, v, i;
    sort(e.begin(), e.end());
    for(i = 0; i < e.size() && cnt; i++)
    {
        u = find_set(e[i].u);
        v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            vc[u].pub(v);
            vc[v].pub(u);
            color[u][v] = color[v][u] = 1;
            cnt--;
            total += e[i].w;
        }
    }
    return;
}

void dfs(int node)
{
    for(int i = 0; i < vc[node].size(); i++)
    {
        if(color[node][vc[node][i]])
        {
            color[node][vc[node][i]] = color[vc[node][i]][node] =  0;
            cnt--;
            dfs(vc[node][i]);
        }
    }
    return;
}
