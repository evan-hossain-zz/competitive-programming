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

int arr[MAX];

struct node{
    int alive, val;
}segtree[MAX*3];

void build(int l, int r, int cur)
{
    if(l == r)
    {
        segtree[cur] = {1, l};
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    build(l, m, lchild);
    build(m+1, r, rchild);
    segtree[cur].alive = segtree[lchild].alive + segtree[rchild].alive;
}

void update(int l, int r, int cur, int got, int pos)
{
    if(l == r)
    {
        segtree[cur] = {0,0};
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    if(got + segtree[lchild].alive >= pos)
        update(l, m, lchild, got, pos);
    else
        update(m+1, r, rchild, got+segtree[lchild].alive, pos);
    segtree[cur].alive = segtree[lchild].alive + segtree[rchild].alive;
}

int query(int l, int r, int cur, int got, int pos)
{
    if(l == r)
        return segtree[cur].val;
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    if(got + segtree[lchild].alive >= pos)
        return query(l, m, lchild, got, pos);
    return query(m+1, r, rchild, got+segtree[lchild].alive, pos);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int test, n, i, x;
    cin >> test;
    while(test--)
    {
        cin >> n;
        build(1, n, 1);
        for(i = 1; i <= n; i++)
            cin >> arr[i];
        for(i = n; i ; i--)
        {
            x = i - arr[i];
            arr[i] = query(1, n, 1, 0, x);
            update(1, n, 1, 0, x);
        }
        for(i = 1; i <= n; i++)
            cout << arr[i] << " \n"[i==n];
    }
    return 0;
}

