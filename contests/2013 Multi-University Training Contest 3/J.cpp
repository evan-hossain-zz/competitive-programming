#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <set>

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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 50010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

vector <int> divisors[MAX];

int res[MAX], segtree[MAX*6], arr[MAX], position[MAX];

int n;

struct query{
    int no, l, r;
}Q[MAX];

bool comp(const query &a, const query &b)
{
    return a.r < b.r;
}

void build(int l, int r, int cur)
{
    if(l == r)
    {
        segtree[cur] = 1;
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r)>>1;
    build(l, m, lchild);
    build(m+1, r, rchild);
    segtree[cur] = max(segtree[lchild], segtree[rchild]);
}

void update(int l, int r, int cur, int pos, int val)
{
    if(l == r)
    {
        segtree[cur] = max(segtree[cur], val);
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r)>>1;
    if(pos <= m)
        update(l, m, lchild, pos, val);
    else
        update(m+1, r, rchild, pos, val);
    segtree[cur] = max(segtree[lchild], segtree[rchild]);
}

int query(int l, int r, int cur, int L, int R)
{
    if(l > R || r < L)
        return 1;
    if(l >= L && r <= R)
        return segtree[cur];
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r)>>1;
    return max(query(l, m, lchild, L, R), query(m+1, r, rchild, L, R));
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int q, i, test=0, j, k;
    for(i = 1; i < MAX; i++)
    {
        for(int j = i; j < MAX; j += i)
            divisors[j].pb(i);
    }
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &q);
        for(i = 0; i < q; i++)
        {
            scanf("%d %d", &Q[i].l, &Q[i].r);
            Q[i].l--, Q[i].r--;
            Q[i].no = i;
        }
        build(0, n-1, 1);
        clr(position, -1);
        sort(Q, Q+q, comp);
        for(i = k = 0; i < n; i++)
        {
            for(j = 0; j < SZ(divisors[arr[i]]); j++)
            {
                int num = divisors[arr[i]][j];
                if(position[num] != -1)
                    update(0, n-1, 1, position[num], num);
                position[num] = i;
            }
            while(k < q && Q[k].r == i)
            {
                if(Q[k].l == Q[k].r)
                    res[Q[k].no] = 0;
                else
                    res[Q[k].no] = query(0, n-1, 1, Q[k].l, Q[k].r);
                k++;
            }
        }
        for(i = 0; i < q; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}


