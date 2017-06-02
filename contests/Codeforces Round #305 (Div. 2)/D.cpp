#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (2e9)
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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int segtree[MAX*6], arr[MAX], stable[MAX][40];

void build2(int l, int r, int cur)
{
    if(l == r)
    {
        segtree[cur] = arr[l];
        return;
    }
    int lchild = cur << 1, rchild = lchild|1, m = (l+r) >> 1;
    build2(l, m, lchild);
    build2(m+1, r, rchild);
    segtree[cur] = max(segtree[lchild], segtree[rchild]);
}

void preprocess(int n)
{
    int i, j;
    for(i = 0; i < n; i++) stable[i][0] = arr[i];
    for(j = 1; (1<<j) <= n; j++)
    {
        for(i = 0; i + (1<<j) - 1 < n; i++)
            stable[i][j] = min(stable[i][j-1], stable[i+(1<<(j-1))][j-1]);
    }
}

int query2(int l, int r, int cur, int L, int R)
{
    if(l > R || r < L) return 0;
    if(l >= L && r <= R)
        return segtree[cur];
    int lchild = cur << 1, rchild = lchild|1, m = (l+r) >> 1;
    return max(query2(l, m, lchild, L, R), query2(m+1, r, rchild, L, R));
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    preprocess(n);
    map <int,int> mpp;
    for(i = 0; i < n; i++)
    {
        int r, l;
        int low = i, high = n-1, mid;
        while(low <= high)
        {
            mid = (low+high) / 2;
            int lg = log2(mid-i+1);
            if(min(stable[i][lg], stable[mid-(1<<lg)+1][lg]) >= arr[i])
                low = mid+1,r = mid;
            else
                high = mid-1;
        }
        low = 0, high = i;
        while(low <= high)
        {
            mid = (low+high) / 2;
            int lg = log2(i-mid+1);
            if(min(stable[mid][lg], stable[i-(1<<lg)+1][lg]) >= arr[i])
                high = mid-1, l = mid;
            else
                low = mid+1;
        }
        if(mpp.find(arr[i]) == mpp.end())
            mpp[arr[i]] = r-l+1;
        else
            mpp[arr[i]] = max(mpp[arr[i]], r-l+1);
    }
    clr(arr, 0);
    for(auto x: mpp)
        arr[x.second] = max(arr[x.second], x.first);
    build2(1, n, 1);
    for(i = 1; i <= n; i++)
        cout << query2(1, n, 1, i, n) << "\n";
    return 0;
}


