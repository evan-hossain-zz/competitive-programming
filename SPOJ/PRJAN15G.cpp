#include <bits/stdc++.h>

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

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int par[MAX];

int root(int v)
{
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}
void merge(int x,int y) 	//	x and y are some tools (vertices)
{
    x = root(x), y = root(y);
    if(par[y] < par[x])	// balancing the height of the tree
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

stack <pair <int, int> > s;
vector <int> adj[MAX];
int discover[MAX], bedge[MAX], discovery_time;
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
                if(root(cur.first) != root(cur.second))
                    merge(cur.first, cur.second);
                do {
                    e = s.top(); s.pop();
                    if(root(e.first) != root(cur.first))
                        merge(e.first, cur.first);
                    if(root(e.second) != root(cur.first))
                        merge(e.second, cur.first);
                } while(e != cur);
            }
        }
        else if(discover[node] > discover[to])
        {
            s.push(make_pair(node, to));
            bedge[node] = min(discover[to], bedge[node]);
        }
    }
}

vector <int> nadj[MAX];

void make_new_graph(int n)
{
    int i,j,u,v;

    for(i = 0; i <= n; i++) nadj[i].clear();

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < SZ(adj[i]); j++)
        {
            u=root(i);
            v=root(adj[i][j]);
            if(u!=v)
                nadj[u].pb(v), nadj[v].pb(u);
        }
    }
}

int level[MAX], pwr[MAX][22];
int arr[MAX][22];
queue <int> Q;

void bfs(void)
{
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int elements = nadj[u].size();
        for(int i = 0; i < elements; i++)
        {
            int v = nadj[u][i];
            if(level[v] == 0)
            {
                level[v] = level[u] + 1;
                pwr[v][0] = u;
                arr[v][0] = 1;
                Q.push(v);
            }
        }
    }
}

void process(int n)
{
    int h, i, lev;
    for(h = 0; (1 << h) < n; h++);

    for(lev = 1; lev <= h; lev++)
    {
        for(i = 1; i <= n; i++)
        {
            if(pwr[i][lev - 1] != -1)
            {
                arr[i][lev] = arr[i][lev - 1] + arr[pwr[i][lev - 1]][lev - 1];
                pwr[i][lev] = pwr[pwr[i][lev - 1]][lev - 1];
            }
        }
    }
}

int query(int high, int low)
{
    int ret = 0;
    if(level[low] < level[high]) swap(low, high);
    int h, i, diff;
    for(h = 1; (1 << h) < level[low]; h++);
    diff = level[low] - level[high];
    for(i = 0; i <= h; i++)
    {
        if(diff & (1 << i))
        {
            ret += arr[low][i];
            low = pwr[low][i];
        }
    }
    if(low == high) return ret;
    for(i = h; i >= 0; i--)
    {
        if(pwr[low][i] != -1 && pwr[low][i] != pwr[high][i])
        {
            ret += arr[high][i];
            ret += arr[low][i];
            low = pwr[low][i];
            high = pwr[high][i];
        }
    }
    ret += arr[low][0] + arr[high][0];
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int test, n, kase = 1, m, i, j, u, v;
    cin >> test;
    while(test--)
    {
        while(!s.empty()) s.pop();
        discovery_time = 1;
        clr(arr, 0);
        clr(level, 0);
        clr(pwr, -1);
        clr(par, -1);
        clr(discover, 0);
        clr(bedge, 0);
        cin >> n >> m;
        for(i = 1; i <= n; i++)
            adj[i].clear();
        while(m--)
        {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1, -1);
        make_new_graph(n);
        Q.push(root(1));
        level[root(1)] = 1;
        bfs();
        process(n+1);
        cout << "Case " << kase++ << ":\n";
        cin >> m;
        while(m--)
        {
            cin >> u >> v;
            if(root(u) == root(v))
                cout << "0\n";
            else
                cout << query(root(u), root(v)) << "\n";
        }
    }
    return 0;
}

/*
1
8 10 1 2 2 3 3 1 2 4 3 5 4 5
3 7
7 6
3 6
6 8
*/

