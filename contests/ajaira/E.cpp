#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int low[MAX], tim[MAX], col[MAX], no_of_component, n, timer, group_id[MAX];
vector <int> adj[MAX], dag[MAX];
stack <int> st;
string toName[MAX], vset[MAX];
bool done[MAX], okGroup[MAX];
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
        do
        {
            tem = st.top();
            st.pop();
            group_id[tem]=no_of_component;
            if(done[tem])
                okGroup[no_of_component] = true;
            col[tem] = 2;
        }
        while(tem != u);
        no_of_component++;
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

void make_new_DAG()
{
    int i,j,u,v;

    for(i = 0; i < no_of_component; i++) dag[i].clear();

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < SZ(adj[i]); j++)
        {
            u=group_id[i];
            v=group_id[adj[i][j]];
            if(u!=v)
                dag[u].pb(v);
        }
    }
}

void dfs(int u)
{
    if(col[u]) return;
    col[u] = 1;
    for(auto v: dag[u])
        dfs(v);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, u, v, m, i;
    string from, to;
    cin >> test;
    map<string,int> mpp;
    while(test--)
    {
        cin >> u >> v >> m;
        for(i = 0; i < MAX; i++)
            adj[i].clear(), dag[i].clear();
        clr(low, 0);
        clr(tim, 0);
        clr(col, 0);
        clr(group_id, 0);
        clr(done, 0);
        clr(okGroup, 0);
        mpp.clear();
        int mc = 0;
        for(i = 0; i < u; i++)
        {
            cin >> from;
            if(mpp.find(from) == mpp.end())
                mpp[from] = mc++;
            done[mpp[from]] = true;
        }
        for(i = 0; i < v; i++)
        {
            cin >> from;
            if(mpp.find(from) == mpp.end())
                mpp[from] = mc++;
            vset[i] = from;
        }
        while(m--)
        {
            cin >> from >> to;
            if(mpp.find(from) == mpp.end())
                mpp[from] = mc++;
            if(mpp.find(to) == mpp.end())
                mpp[to] = mc++;
            adj[mpp[from]].pb(mpp[to]);
        }
        n = mc;
        call_for_scc_check();
        make_new_DAG();
        clr(col, 0);
        for(i = 0; i < no_of_component; i++)
        {
            if(okGroup[i])
                dfs(i);
        }
        vector <string> res;
        for(i = 0; i < v; i++)
        {
            int id = mpp[vset[i]];
            if(done[id] || col[group_id[id]])
                res.pb(vset[i]);
        }
        sort(all(res));
        for(auto x: res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
