#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>

#define in freopen("input.in", "r", stdin);
#define out freopen("control.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
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

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int low[MAX], tim[MAX], col[MAX], no_of_component, n, timer, group_id[MAX];
vector <int> adj[MAX], ulta[MAX];
stack <int> st;

map <pair<int,int>, int> edges;
int res = 0;
void scc(int u)
{
    low[u] = tim[u] = timer++;
    col[u] = 1;
    st.push(u);
    int i, elements = adj[u].size(), v, tem;
    for(i = 0; i < elements; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(col[v] == 0)
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == tim[u])
    {
        if(u == st.top())
        {
            st.pop();
            return;
        }
        no_of_component++;
        do
        {
            tem = st.top();
            st.pop();
            group_id[tem]=no_of_component;
            col[tem] = 2;
        }
        while(tem != u);
    }
}
void call_for_scc_check()
{
    no_of_component = timer = 0;
    clr(col, 0);
    int i;
    while(!st.empty()) st.pop();
    for(i = 0; i < n; i++)
    {
        if(col[i] == 0)
            scc(i);
    }
}


int main()
{
    in;
    int test, i, m, u, v;
    cin >> test;
    while(test--)
    {
        cin >> n >> m;
        for(i = 0; i <= n; i++)
        {
            adj[i].clear();
            ulta[i].clear();
            low[i] = tim[i] = col[i] = group_id[i] = 0;
        }
        edges.clear();
        while(m--)
        {
            cin >> u >> v;
            u--, v--;
            edges[mp(u, v)]++;
            if(edges[mp(u, v)] == 1)
            {
                adj[u].pb(v);
                ulta[v].pb(u);
            }
        }
        res = 0;
        call_for_scc_check();
        // for(i = 0; i < n; i++)
        //     cout << group_id[i] << ' ';
        clr(col, 0);
        queue <int> Q;
        for(i = 0; i < n; i++)
        {
            if(group_id[i])
            {
                Q.push(i);
                col[i] = 1;
            }
        }
        while(!Q.empty())
        {
            u = Q.front();
            Q.pop();
            for(auto v: ulta[u])
            {
                if(col[v] == 0)
                {
                    Q.push(v);
                    col[v] = 1;
                    group_id[v] = group_id[u];
                }
            }
        }
        for(auto edge: edges)
        {
            u = edge.first.first;
            v = edge.first.second;
            if(group_id[v])
                res += edge.second;
        }
        cout << res << "\n";
    }
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 















