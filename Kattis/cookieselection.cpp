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

#define MAX 600010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int segtree[4*MAX];
int arr[MAX];

map <int,int> mpp, ulta;
set <int> ss;

void update(int l, int r, int cur, int pos, int val)
{
    if(l == r)
    {
        segtree[cur] += val;
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    if(pos <= m)
        update(l, m, lchild, pos, val);
    else
        update(m+1, r, rchild, pos, val);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

void query(int l, int r, int cur, int baki)
{
    if(l == r)
    {
        cout << ulta[l] << "\n";
        segtree[cur]--;
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r) >> 1;
    if(segtree[lchild] >= baki)
        query(l, m, lchild, baki);
    else
        query(m+1, r, rchild, baki - segtree[lchild]);
    segtree[cur] = segtree[lchild] + segtree[rchild];
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    string s;
    int i = -1, n;
    while(cin >> s)
    {
        if(s[0] == '#')
            arr[++i] = -1;
        else
        {
            arr[++i] = extract(s, 1);
            ss.insert(arr[i]);
        }
    }
    n = i+1;
    i = 0;
    for(auto x: ss)
        mpp[x] = ++i, ulta[i] = x;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == -1)
        {
            int k = segtree[1] % 2? (segtree[1]+1)/2 : (segtree[1]/2)+1;
            query(1, SZ(ss), 1, k);
            continue;
        }
        update(1, SZ(ss), 1, mpp[arr[i]], 1);
    }
    return 0;
}


