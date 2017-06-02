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
#define LMAX 18
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int weights[MAX], level[MAX], par[MAX][LMAX], orgVal[MAX];
vector <int> adj[MAX];
map <int,int> mpp;

struct node{
    node *left, *right;
    int val;

    node(int v, node *l, node *r)
    {
        val = v;
        left = l;
        right = r;
    }

    node * insert(int l, int r, int pos)
    {
        if(l > pos || r < pos) /// completely out of range
            return this;
        if(l == r)
            return new node(this->val+1, NULL, NULL); ///create new node
        int m = (l+r)/2;
        return new node(this->val+1, this->left->insert(l, m, pos), this->right->insert(m+1, r, pos)); ///go to childs
    }
};

node *rootOf[MAX], *root = new node(0, NULL, NULL);

void dfs(int node, int prev)
{
    par[node][0] = prev;
    level[node] = prev == -1? 0 : level[prev]+1;
    rootOf[node] = (prev == -1?root:rootOf[prev])->insert(0, SZ(mpp)-1, weights[node]);
    for(int i = 0; i < SZ(adj[node]); i++)
        if(adj[node][i] != prev)
            dfs(adj[node][i], node);
}

void process(int n)
{
    int h, i, lev;
    h = log2(n) + 1;

    for(lev = 1; lev <= h; lev++)
    {
        for(i = 1; i <= n; i++)
        {
            if(par[i][lev - 1] != -1)
                par[i][lev] = par[par[i][lev - 1]][lev - 1];
        }
    }
}

int LCAquery(int high, int low)
{
    if(level[low] < level[high]) swap(low, high);
    int h, i, diff;
    h = log2(level[low]) + 1;
    diff = level[low] - level[high];
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

int query(node *a, node *b, node *c, node *d, int l, int r, int k)
{
    if(l == r)
        return l;
    int tot = a->left->val + b->left->val - c->left->val - d->left->val;
    int m = (l+r) >> 1;
    if(tot >= k)
        return query(a->left, b->left, c->left, d->left, l, m, k);
    return query(a->right, b->right, c->right, d->right, m+1, r, k-tot);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, i, u, v, k, mc = 0, lca, res;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> weights[i], mpp[weights[i]];
    for(map<int,int> :: iterator it = mpp.begin(); it != mpp.end(); it++)
        mpp[it->first] = mc++;
    for(i = 0; i < n; i++)
    {
        orgVal[mpp[weights[i]]] = weights[i];
        weights[i] = mpp[weights[i]];
    }
    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    clr(par, -1);
    root->left = root->right = root;
    dfs(0, -1);
    process(n);
    while(m--)
    {
        cin >> u >> v >> k;
        u--, v--;
        lca = LCAquery(u, v);
        res = query(rootOf[u], rootOf[v], rootOf[lca], par[lca][0] == -1? root: rootOf[par[lca][0]], 0, SZ(mpp)-1, k);
        cout << orgVal[res] << "\n";
    }
    return 0;
}
