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
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define SZ(v) (int)(v.size())
#define eps 10e-7

#define F(i, n) for(i = 0; i < n; i++)

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 50010
/*************************************************HABIJABI ENDS HERE******************************************************/

int low[MAX], tim[MAX], col[MAX], no_of_component, n, timer, group_id[MAX], connections[MAX], indeg[MAX], start[MAX];
vector <int> adj[MAX], dag[MAX];
stack <int> st;

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
    int cnt = 0;
    if(low[u] == tim[u])
    {
        start[no_of_component] = st.top();
        do
        {
            tem = st.top();
            start[no_of_component] = min(start[no_of_component], tem);
            st.pop();
            cnt++;
            group_id[tem] = no_of_component;
            col[tem] = 2;
        }
        while(tem != u);
        connections[no_of_component] = cnt;
        no_of_component++;
    }
}

void call_for_scc_check(void)
{
    no_of_component = timer = 0;
    clr(col, 0);
    clr(start, 0);
    int i;
    while(!st.empty()) st.pop();
    for(i = 1; i <= n; i++)
    {
        if(col[i] == 0)
            scc(i);
    }
}

void make_dag(void)
{
    int i, j, u, v;
    for(i = 0; i <= no_of_component; i++)
        dag[i].clear(), indeg[i] = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < SZ(adj[i]); j++)
        {
            u = group_id[i];
            v = group_id[adj[i][j]];
            if(u != v)
            {
                indeg[v]++;
                dag[u].pb(v);
            }
        }
    }
}

int dfs(int node)
{
    col[node] = 3;
    int ret = connections[node];
    for(int i = 0; i < SZ(dag[node]); i++)
    {
        int v = dag[node][i];
        if(col[v] != 3)
            ret += dfs(v);
    }
    return ret;
}

int main()
{
    int i, u, v, test, res;
    cin >> test;
    for(int kase = 1; kase <= test; kase++)
    {
        cin >> n;
        for(i = 0; i <= n; i++)
        {
            adj[i].clear();
            group_id[i] = connections[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            cin >> u >> v;
            adj[u].pb(v);
        }
        call_for_scc_check();
        make_dag();
        res = 0;
        for(i = 0; i < no_of_component; i++)
        {
            if(indeg[i] == 0)
            {
                v = dfs(i);
                if(res < v)
                {
                    res = v;
                    u = start[i];
                }
            }
        }
        printf("Case %d: %d\n", kase, u);
    }
    return 0;
}



