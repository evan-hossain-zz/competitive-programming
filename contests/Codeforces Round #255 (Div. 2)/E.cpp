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

#define MAX 300010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL mod = 1000000009;
LL arr[MAX], F[MAX];

namespace fibonacci
{
    void gen(int n)
    {
        F[1] = F[2] = 1;
        for(int i = 3; i <= n; i++)
            F[i] = (F[i-1] + F[i-2]) % mod;
    }

    LL kth_fibo(LL f1, LL f2, LL k)
    {
        if(k == 1) return f1;
        if(k == 2) return f2;
        LL ret = (F[k-1] * f2) % mod;
        ret += (F[k-2] * f1) % mod;
        ret %= mod;
        return ret;
    }

    LL sum(LL f1, LL f2, LL k)
    {
        LL ret = (kth_fibo(f1, f2, k + 2) - f2) % mod;
        ret += mod;
        return ret % mod;
    }
}

struct node{
    LL f1, f2, sum;
    node(LL sum = 0, LL f1 = 0, LL f2 = 0) : sum(sum), f1(f1), f2(f2){};

    void add(LL _f1, LL _f2, LL k)
    {
        f1 += _f1;
        f2 += _f2;
        f1 %= mod;
        f2 %= mod;
        sum += fibonacci::sum(_f1, _f2, k);
        sum %= mod;
    }
};

node segtree[MAX*4];

void build(int l, int r, int cur)
{
    if(l == r)
    {
        segtree[cur] = node(arr[l] % mod);
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l + r) >> 1;
    build(l, m, lchild);
    build(m+1, r, rchild);
    segtree[cur].sum = segtree[lchild].sum + segtree[rchild].sum;
    segtree[cur].sum %= mod;
}

void push_down(int l, int r, int cur)
{
    if(segtree[cur].f1 == 0 && segtree[cur].f2 == 0)
        return;
    if(l == r)
        return;
    int lchild = cur << 1, rchild = lchild | 1, m = (l + r) >> 1;
    LL f1, f2, nf1, nf2;
    f1 = segtree[cur].f1;
    f2 = segtree[cur].f2;
    segtree[lchild].add(f1, f2, m - l + 1);

    nf1 = fibonacci::kth_fibo(f1, f2, max(1, m - l + 2));
    nf2 = fibonacci::kth_fibo(f1, f2, max(2, m - l + 3));
    segtree[rchild].add(nf1, nf2, r - m);
    segtree[cur].sum = segtree[lchild].sum + segtree[rchild].sum;
    segtree[cur].sum %= mod;
    segtree[cur].f1 = segtree[cur].f2 = 0;
}

void update(int L, int R, int l, int r, int cur)
{
    push_down(l, r, cur);
    if(l > R || r < L) return;
    if(l >= L && r <= R)
    {
        LL f1 = F[l - L + 1];
        LL f2 = F[l - L + 2];
        segtree[cur].add(f1, f2, r - l + 1);
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l + r) >> 1;
    update(L, R, l, m, lchild);
    update(L, R, m+1, r, rchild);
    segtree[cur].sum = segtree[lchild].sum + segtree[rchild].sum;
    segtree[cur].sum %= mod;
}

LL query(int L, int R, int l, int r, int cur)
{
    push_down(l, r, cur);
    if(l > R || r < L) return 0;
    if(l >= L && r <= R)
        return segtree[cur].sum;
    int lchild = cur << 1, rchild = lchild | 1, m = (l + r) >> 1;
    return (query(L, R, l, m, lchild) + query(L, R, m+1, r, rchild)) % mod;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int n, m, i, q, l, r;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    fibonacci::gen(n);
    build(1, n, 1);
    while(m--)
    {
        cin >> q >> l >> r;
        if(q==1)
            update(l, r, 1, n, 1);
        else
            cout << query(l, r, 1, n, 1) << "\n";
    }
    return 0;
}
