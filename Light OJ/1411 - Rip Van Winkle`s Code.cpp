#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 250001
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

struct node{
    LL inc, dec, C, sum;
};
node segtree[MAX*6];

LL get_head(LL sum, LL n, bool inc)
{
    LL a_b = sum*2/n, a;
    if(inc)
        a = a_b/2-(n/2)+(n%2==0);
    else
        a = a_b/2+(n/2);
    return a;
}

LL get_sum(LL a, LL b)
{
    return (a+b)*(b-a+1)/2;
}

void push_down(int cur, int l, int r)
{
    int lchild = cur << 1, rchild = lchild|1, m = (l+r)>>1;
    if(segtree[cur].C)
    {
        segtree[lchild].C = segtree[rchild].C = segtree[cur].C;
        segtree[lchild].inc = segtree[rchild].dec = 0;
        segtree[cur].sum = (r-l+1)*segtree[cur].C;
        segtree[cur].C = 0;
    }
    segtree[cur].sum += segtree[cur].inc + segtree[cur].dec;
    if(l == r)
    {
        segtree[cur].inc = segtree[cur].dec = 0;
        return;
    }
    LL head, tail, ninc;
    if(segtree[cur].inc)
    {
        head = get_head(segtree[cur].inc, r-l+1, 1);
        tail = head + m-l;
        ninc = (head+tail) * (m-l+1) / 2;
        segtree[lchild].inc += ninc;
        segtree[rchild].inc += segtree[cur].inc - ninc;
    }

    if(segtree[cur].dec)
    {
        head = get_head(segtree[cur].dec, r-l+1, 0);
        tail = head + r-(m+1);
        ninc = (head+tail) * (r-m) / 2;
        segtree[rchild].dec += ninc;
        segtree[lchild].dec += segtree[cur].dec - ninc;
    }

    segtree[cur].inc = segtree[cur].dec = 0;
}


void update(int cur, int l, int r, int L, int R, int x)
{
    push_down(cur, l, r);
    if(l > R || r < L)
        return;
    if(l >= L && r <= R)
    {
        segtree[cur].inc = segtree[cur].dec = 0;
        segtree[cur].C = x;
        push_down(cur, l, r);
        return;
    }
    int lchild = cur << 1, rchild = lchild|1, m = (l+r)>>1;
    update(lchild, l, m, L, R, x);
    update(rchild, m+1, r, L, R, x);
    segtree[cur].sum = segtree[lchild].sum + segtree[rchild].sum;
}

void update(int cur, int l, int r, int L, int R, bool type)
{
    push_down(cur, l, r);
    if(l > R || r < L)
        return;
    if(l >= L && r <= R)
    {
        LL nsum;
        if(type)
        {
            int nr = R - l+1, nl = nr - r+l;
            nsum = get_sum(nl, nr);
            segtree[cur].dec += nsum;
        }
        else
        {
            int nl = l - L + 1, nr = nl + r - l;
            nsum = get_sum(nl, nr);
            segtree[cur].inc += nsum;
        }
        push_down(cur, l, r);
        return;
    }
    int lchild = cur << 1, rchild = lchild|1, m = (l+r)>>1;
    update(lchild, l, m, L, R, type);
    update(rchild, m+1, r, L, R, type);
    segtree[cur].sum = segtree[lchild].sum + segtree[rchild].sum;
}

LL query(int cur, int l, int r, int L, int R)
{
    push_down(cur, l, r);
    if(l > R || r < L)
        return 0;
    if(l >= L && r <= R)
        return segtree[cur].sum;
    int lchild = cur << 1, rchild = lchild|1, m = (l+r)>>1;
    return query(lchild, l, m, L, R) + query(rchild, m+1, r, L, R);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1, l, r, x, q, N = MAX-1;
    char ch;
    scanf("%d", &test);
    while(test--)
    {
        clr(segtree, 0);
        scanf("%d", &q);
        printf("Case %d:\n", kase++);
        while(q--)
        {
            scanf(" %c %d %d", &ch, &l, &r);
            if(ch == 'S')
                printf("%lld\n", query(1, 1, N, l, r));
            else if(ch == 'A')
                update(1, 1, N, l, r, false);
            else if(ch == 'B')
                update(1, 1, N, l, r, true);
            else
            {
                scanf("%d", &x);
                update(1, 1, N, l, r, x);
            }
        }
    }
    return 0;
}
