#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>

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

#define MAX 50010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int segtree[MAX*6], lazy[MAX*6], n;

void build(int l, int r, int cur)
{
    lazy[cur] = -1;
    if(l == r)
    {
        segtree[cur] = 1;
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r)>>1;
    build(l, m, lchild);
    build(m+1, r, rchild);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

void push_down(int l, int r, int cur)
{
    if(lazy[cur] == -1)
        return ;
    segtree[cur] = (r-l+1)*lazy[cur];
    int lchild = cur << 1, rchild = lchild | 1;
    lazy[lchild] = lazy[rchild] = lazy[cur];
    lazy[cur] = -1;
}

void update(int L, int R, int val, int l, int r, int cur)
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
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r)>>1;
    update(L, R, val, l, m, lchild);
    update(L, R, val, m+1, r, rchild);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

int query(int L, int R, int l, int r, int cur)
{
    push_down(l, r, cur);
    if(l > R || r < L)
        return 0;
    if(l >= L && r <= R)
        return segtree[cur];
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r)>>1;
    int ret = query(L, R, l, m, lchild) +
     query(L, R, m+1, r, rchild);
     segtree[cur] = segtree[lchild] + segtree[rchild];
     return ret;
}

int getL(int l)
{
    int low = l, high = n-1, mid, ret = -1;
    while(low <= high)
    {
        mid = (low+high) / 2;
        if(query(l, mid, 0, n-1, 1) < 1)
            low = mid+1;
        else
            high = mid-1, ret = mid;
    }
    return ret;
}

int getR(int l, int cnt)
{
    int low = l, high = n-1, mid, ret = -1;
    cnt = min(cnt, query(l, n-1, 0, n-1, 1));
    while(low <= high)
    {
        mid = (low+high) / 2;
        if(query(l, mid, 0, n-1, 1) < cnt)
            low = mid+1;
        else
            high = mid-1, ret = mid;
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, m, k, a, b;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);
        build(0, n-1, 1);
        while(m--)
        {
            scanf("%d %d %d", &k, &a, &b);
            if(k == 1)
            {
                int l = getL(a), r = getR(a, b);
                if(l == -1)
                {
                    printf("Can not put any one.\n");
                    continue;
                }
                printf("%d %d\n", l, r);
                update(l, r, 0, 0, n-1, 1);
            }
            else
            {
                printf("%d\n", b-a+1-query(a, b, 0, n-1, 1));
                update(a, b, 1, 0, n-1, 1);
            }
        }
        printf("\n");
    }
    return 0;
}
