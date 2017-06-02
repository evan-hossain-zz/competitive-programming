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

#define MAX 75001
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int res[MAX], arr[MAX], sorted[MAX], segtree[MAX*4], lazy[MAX*4], mark[MAX];
pair<int,int> Q[MAX];

void build(int l, int r, int cur)
{
    lazy[cur] = -1;
    if(l == r)
    {
        segtree[cur] = mark[l] == 0;
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, mid = (l+r) >> 1;
    build(l, mid, lchild);
    build(mid+1, r, rchild);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

void push_down(int l, int r, int cur)
{
    if(lazy[cur] == -1)
        return;
    if(l == r)
    {
        segtree[cur] = lazy[cur] == 0;
        lazy[cur] = -1;
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, mid = (l+r) >> 1;
    lazy[lchild] = lazy[rchild] = lazy[cur];
    segtree[cur] = (r-l+1) * (lazy[cur] == 0);
    lazy[cur] = -1;
}

void update(int l, int r, int cur, int L, int R, int val)
{
    push_down(l, r, cur);
    if(l > R || r < L)
        return;
    if(l >= L && r <= R)
    {
        lazy[cur] = val;
        push_down(l, r, cur);
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, mid = (l+r) >> 1;
    update(l, mid, lchild, L, R, val);
    update(mid+1, r, rchild, L, R, val);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

int query(int l, int r, int cur, int L, int R)
{
    push_down(l, r, cur);
    if(l > R || r < L)
        return 0;
    if(l >= L && r <= R)
        return segtree[cur];
    int lchild = cur << 1, rchild = lchild | 1, mid = (l+r) >> 1;
    return query(l, mid, lchild, L, R) + query(mid+1, r, rchild, L, R);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, q, i, k;
    cin >> n >> q >> k;
    for(i = 0; i < n; i++)
        cin >> arr[i], sorted[i] = arr[i];
    sort(sorted, sorted+n);
    for(i = 0; i < q; i++)
        cin >> Q[i].first >> Q[i].second;
    int low = 0, high = n-1, mid, res = -1;
    while(low <= high)
    {
        mid = (low+high) / 2;
        cout << mid << endl;
        for(i = 0; i < n; i++)
            mark[i] = arr[i] >= sorted[mid];
        build(0, n-1, 1);
        for(i = 0; i < q; i++)
        {
            int small = query(0, n-1, 1, Q[i].first, Q[i].second);
            update(0, n-1, 1, Q[i].first, Q[i].first+small-1, 0);
            update(0, n-1, 1, Q[i].first+small, Q[i].second, 1);
        }
        if(query(0, n-1, 1, k, k))
            high = mid-1;
        else
            low = mid+1, res = mid;
    }
    cout << res << endl;
    cout << sorted[res] << "\n";
    return 0;
}


