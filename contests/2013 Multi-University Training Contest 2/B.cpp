#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>

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

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 2000010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

stack <pair <int, int> > s;
vector <int> adj[MAX], nadj[MAX];
int discover[MAX], bedge[MAX], group_id[MAX], discovery_time, bcc, farnode, fardist;
void dfs(int node, int from)
{
    discover[node] = bedge[node] = discovery_time++;
    int i, connected = adj[node].size(), to;
    pair <int, int> e, cur;
    for(i = 0; i < connected; i++)
    {
        to = adj[node][i];
        if(to == from) continue;
        if(!discover[to])
        {
            s.push(make_pair(node, to));
            dfs(to, node);
            bedge[node] = min(bedge[node], bedge[to]);
            if(bedge[to] >= discover[node])
            {
                cur = make_pair(node, to);
                if(cur == s.top())
                {
                    s.pop();
                    continue;
                }
                do {
                    e = s.top(); s.pop();
                    group_id[e.first] = bcc;
                    group_id[e.second] = bcc;
//                    cout << "edge " << e.first+1 << ' ' << e.second+1 << endl;
                } while(e != cur);
                bcc++;
            }
        }
        else if(discover[node] > discover[to])
        {
            s.push(make_pair(node, to));
            bedge[node] = min(discover[to], bedge[node]);
        }
    }
}

void call(int n)
{
    discovery_time = bcc = 0;
    int i;
    while(!s.empty()) s.pop();
    for(i = 0; i < n; i++)
    {
        if(discover[i] == 0)
            dfs(i, -1);
    }
}

void make_new_graph(int n)
{
    int i,j,u,v;

    for(i = 0; i < bcc; i++) nadj[i].clear();

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < SZ(adj[i]); j++)
        {
            u=group_id[i];
            v=group_id[adj[i][j]];
            if(u!=v)
                nadj[u].pb(v);
        }
    }
}

void dfs(int u, int prev, int d)
{
    if(d > fardist)
    {
        farnode = u;
        fardist = d;
    }
    for(int i = 0; i < SZ(nadj[i]); i++)
    {
        int v = nadj[u][i];
        if(prev != v)
            dfs(v, u, d+1);
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, u, v, i;
    while(scanf("%d %d", &n, &m) == 2 && (n|m))
    {
        map<pair<int,int>,int> mpp;
        for(i = 0; i < MAX; i++)
            adj[i].clear(), group_id[i] = -1, discover[i] = bedge[i] = 0;
        while(m--)
        {
            cin >> u >> v;
            if(u > v) swap(u, v);
            u--, v--;
            if(mpp[mp(u, v)] == 1)
            {
                adj[u].pb(n);
                adj[v].pb(n);
                adj[n].pb(u);
                adj[n].pb(v);
                n++;
            }
            else
            {
                adj[u].pb(v);
                adj[v].pb(u);
            }
            mpp[mp(u, v)]++;
        }
        call(n);
        for(i = 0; i < n; i++)
        {
            if(group_id[i] == -1)
                group_id[i] = bcc++;
//            cout << "here " << i << ' ' << group_id[i] << endl;
        }
        make_new_graph(n);
        fardist = 0;
        dfs(0, -1, 0);
        u = farnode;
        fardist = 0;
        dfs(farnode, -1, 0);
        v = farnode;
        nadj[u].pb(bcc);
        nadj[v].pb(bcc);
        nadj[bcc].pb(u);
        nadj[bcc].pb(v);
        bcc++;
        for(i = 0; i < bcc; i++)
            discover[i] = bedge[i] = 0, adj[i] = nadj[i];
        call(bcc);
        printf("%d\n", bcc-1);
    }
    return 0;
}
