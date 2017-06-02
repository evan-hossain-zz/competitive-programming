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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

struct point
{
    double x;
    double y;
};

struct edge
{
    int u, v;
    double w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

vector <edge> e;
vector <point> p;
int par[110];

int find_set(int node);
double mst(int n);

int main()
{
    int test, i, n;
    point t, k;
    edge te;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%lf %lf", &t.x, &t.y);
            p.pub(t);
        }
        for(int j = 0; j < n; j++)
        {
            for(i = 0; i < n; i++)
            {
                if(i != j)
                {
                    t = p[i], k = p[j];
                    te.u = i;
                    te.v = j;
                    te.w = sqrt(((t.x - k.x) * (t.x - k.x))\
                                +((t.y - k.y) * (t.y - k.y)));
                    e.pub(te);
                }
            }
        }
        printf("%.2lf\n", mst(n));
        if(test)
        {
            e.clear();
            p.clear();
            printf("\n");
        }
    }
    return 0;
}

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

double mst(int n)
{

    double ans = 0;
    int cnt = n - 1;
    sort(e.begin(), e.end());
    for(int i = 0; i < n; i++)
        par[i] = i;
    for(int i = 0; i < e.size() && cnt; i++)
    {
        int u = find_set(e[i].u);
        int v = find_set(e[i].v);
        if(u != v)
        {
            par[u] = v;
            ans += e[i].w;
            cnt--;
        }
    }
    return ans;
}
