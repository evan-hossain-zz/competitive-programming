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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

struct node{
    LL lazy, sum;
    node (LL sum = 0, LL lazy = 0): sum(sum), lazy(lazy){};
};

node segtree[2][MAX*4]; ///0-have, 1-sum

void build(int l, int r, int cur)
{
    if(l == r)
    {
        segtree[0][cur] = node(l);
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l + r) >> 1;
    build(l, m, lchild);
    build(m+1, r, rchild);
    segtree[0][cur].sum = segtree[0][lchild].sum + segtree[0][rchild].sum;
}

void push_down(int tree, int l, int r, int cur)
{
    int lchild = cur << 1, rchild = lchild | 1;
    segtree[tree][lchild] = segtree[tree][cur].lazy;
    segtree[tree][rchild] = segtree[tree][cur].lazy;
    if(tree)
        segtree[tree][cur].sum += (r - l + 1) * segtree[tree][cur].lazy;
    else
        segtree[tree][cur].sum = (r - l + 1) * segtree[tree][cur].lazy;
    segtree[tree][cur].lazy = 0;
}

void update(int tree, int L, int R, int l, int r, int cur, int val)
{
    if(segtree[tree][cur].lazy)
        push_down(tree, l, r, cur);
    if(l > R || r < L)
        return;
    if(l >= L && r <= R)
    {
        segtree[tree][cur].lazy = val;
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l + r) >> 1;
    update(tree, L, R, l, m, lchild, val);
    update(tree, L, R, m+1, r, rchild, val);
    segtree[tree][cur].sum = segtree[tree][lchild].sum + segtree[tree][rchild].sum;
}

LL query(int tree, int L, int R, int l, int r, int cur)
{
    if(segtree[tree][cur].lazy)
        push_down(tree, l, r, cur);
    if(l > R || r < L)
        return 0;
    if(l >= L && r <= R)
        return segtree[tree][cur].sum;
    int lchild = cur << 1, rchild = lchild | 1, m = (l + r) >> 1;
    return query(tree, L, R, l, m, lchild) + query(tree, L, R, m+1, r, rchild);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int n, m, i, q, a, b;
    cin >> n >> m;
    build(1, n, 1);
    while(m--)
    {
        cin >> q;
        if(q == 1)
        {
            cin >> a >> b >> q;
            LL have = query(0, a, b, 1, n, 1);
            LL sum = abs(have - ((b - a + 1) * q));
            update(1, a, b, 1, n, sum);
            update(0, a, b, 1, n, 1, q);
        }
        else
        {
            cin >> a >> b;
            cout << query(1, a, b, 1, n, 1) << endl;
        }
    }
    return 0;
}
