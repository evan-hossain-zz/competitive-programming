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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
#define LN 20
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int depth[MAX], par[MAX][LN];
vector <int> adj[MAX];

void dfs(int cur, int prev, int d)
{
    par[cur][0] = prev;
    depth[cur] = d;
    for(int i = 0; i < SZ(adj[cur]); i++)
    {
        int v = adj[cur][i];
        if(v == prev) continue;
        dfs(v, cur, d + 1);
    }
}

void process(int n)
{
    int h, i, lev;
    h = log2(n) + 1;

    for(lev = 1; lev <= h; lev++)
    {
        for(i = 0; i < n; i++)
        {
            if(par[i][lev - 1] != -1)
                par[i][lev] = par[par[i][lev - 1]][lev - 1];
        }
    }
}


int LCA(int high, int low)
{
    if(depth[low] < depth[high]) swap(low, high);
    int h, i, diff;
    h = log2(depth[low]) + 1;
    diff = depth[low] - depth[high];
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
            low = par[low][i];
    if(low == high) return low;
    for(i = h; i >= 0; i--)
    {
        if(par[low][i] != -1 && par[low][i] != par[high][i])
        {
            low = par[low][i];
            high = par[high][i];
        }
    }
    return par[low][0];
}

int main()
{
    int n, x, k, i, j, q, c, test;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(i = 0; i <= n; i++)
        {
            adj[i].clear();
            for(j = 0; j < LN; j++)
                par[i][j] = -1;
        }
        for(i = 1; i < n; i++)
        {
            cin >> j >> q;
            j--, q--;
            adj[j].pb(q);
            adj[q].pb(j);
        }
        dfs(0, -1, 0);
        process(n);
        cin >> q;
        queue <int> nodes;
        while(q--)
        {
            bool flag = 1;
            cin >> k;
            while(!nodes.empty()) nodes.pop();
            set <int> seen;
            for(i = 0; i < k; i++)
            {
                cin >> x;
                if(seen.find(x) == seen.end())
                    nodes.push(x-1), seen.insert(x);
            }
            while(flag && SZ(nodes) > 2)
            {
                int a, b, l;
                a = nodes.front();
                nodes.pop();
                b = nodes.front();
                nodes.pop();
                l = LCA(a, b);
                if(l == a || l == b)
                    nodes.push(l);
                else
                {
                    c = nodes.front();
                    nodes.pop();
                    l = LCA(b, c);
                    if(l == b || l == c)
                        nodes.push(l), nodes.push(a);
                    else
                    {
                        l = LCA(a, c);
                        if(l == a || l == c)
                            nodes.push(l), nodes.push(b);
                        else
                            flag = 0;
                    }
                }
            }
            if(flag)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}
