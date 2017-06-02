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
    int tem[3];
}arr[MAX];
int segtree[MAX*4];

bool comp(const node &a, const node &b){
    return a.tem[0] < b.tem[0];
}

void update(int l, int r, int cur, int pos, int val)
{
    if(l == r)
    {
        segtree[cur] = val;
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    if(pos <= m) update(l, m, lchild, pos, val);
    else update(m+1, r, rchild, pos, val);
    segtree[cur] = min(segtree[lchild], segtree[rchild]);
}

int query(int L, int R, int l, int r, int cur)
{
    if(l > R || r < L) return segtree[0];
    if(l >= L && r <= R) return segtree[cur];
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    return min(query(L, R, l, m, lchild), query(L, R, m+1, r, rchild));
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int test, i, j, res, n;
    cin >> test;
    while(test--)
    {
        clr(segtree, 63);
        res = 0;
        cin >> n;
        for(i = 0; i < n; i++)
            for(j = 0; j < 3; j++)
                cin >> arr[i].tem[j];
        sort(arr, arr + n, comp);
        for(i = 0; i < n; i++)
        {
            if(query(1, arr[i].tem[1], 1, n, 1) > arr[i].tem[2]) /// no score <= this one
                res++;
            update(1, n, 1, arr[i].tem[1], arr[i].tem[2]);
        }
        cout << res << "\n";
    }
    return 0;
}

