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
    int a, b;
    node(int a = 0, int b = 0): a(a), b(b){}
};

node segtree[MAX*4];

void update(int l, int r, int cur, int pos, int val)
{
    if(l == r)
    {
        segtree[cur] = node(val);
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r)>>1;
    if(pos <= m)
        update(l, m, lchild, pos, val);
    else
        update(m+1, r, rchild, pos, val);
    int tem[4] = {segtree[lchild].a, segtree[lchild].b, segtree[rchild].a, segtree[rchild].b};
    sort(tem, tem+4);
    segtree[cur] = node(tem[2], tem[3]);
}

node query(int L, int R, int l, int r, int cur)
{
    if(l > R || r < L)
        return node(0, 0);
    if(l >= L && r <= R)
        return segtree[cur];
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r)>>1;
    node tem[2];
    tem[0] = query(L, R, l, m, lchild);
    tem[1] = query(L, R, m+1, r, rchild);
    int tem2[4] = {tem[0].a, tem[0].b, tem[1].a, tem[1].b};
    sort(tem2, tem2+4);
    return node(tem2[2], tem2[3]);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int n, x, m, l, r, i;
    char ch;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x;
        update(1, n, 1, i, x);
    }
    cin >> m;
    while(m--)
    {
        cin >> ch >> l >> r;
        if(ch == 'U')
            update(1, n, 1, l, r);
        else
        {
            auto res = query(l, r, 1, n, 1);
            cout << res.a+res.b << "\n";
        }
    }
    return 0;
}

