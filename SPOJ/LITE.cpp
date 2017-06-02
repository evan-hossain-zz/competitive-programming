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

struct node{
    bool lazy;
    int on, off;
    node operator + (const node &p) const{
        return {lazy, on + p.on, off + p.off};
    }
}segtree[MAX*4];

void build(int l, int r, int cur)
{
    if(l == r)
    {
        segtree[cur] = {0, 0, 1};
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    build(l, m, lchild);
    build(m+1, r, rchild);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

void push_down(int cur)
{
    if(!segtree[cur].lazy) return;
    segtree[cur].lazy = 0;
    swap(segtree[cur].on, segtree[cur].off);
    int lchild = cur << 1, rchild = lchild | 1;
    segtree[lchild].lazy = !segtree[lchild].lazy;
    segtree[rchild].lazy = !segtree[rchild].lazy;
}

void update(int L, int R, int l, int r, int cur)
{
    push_down(cur);
    if(l > R || r < L) return;
    if(l >= L && r <= R)
    {
        segtree[cur].lazy = !segtree[cur].lazy;
        push_down(cur);
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    update(L, R, l, m, lchild);
    update(L, R, m+1, r, rchild);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

int query(int L, int R, int l, int r, int cur)
{
    push_down(cur);
    if(l > R || r < L) return 0;
    if(l >= L && r <= R)
        return segtree[cur].on;
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    return query(L, R, l, m, lchild) + query(L, R, m+1, r, rchild);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int n, m, q, l, r;
    cin >> n >> m;
    build(1, n, 1);
    while(m--)
    {
        cin >> q >> l >> r;
        if(q)
            cout << query(l, r, 1, n, 1) << "\n";
        else
            update(l, r, 1, n, 1);
    }
    return 0;
}

