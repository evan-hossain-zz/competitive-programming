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

#define MAX 5010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL dp[MAX][MAX][2], m, cum[MAX];
int visited[MAX][MAX][2], kase;
int n, d, arr[MAX];

LL call(int k, int period, int must)
{
    if(period >= n)
        return k == 0? 0 : -(1LL<<40);
    LL &ret = dp[k][period][must];
    if(visited[k][period][must] == kase) return ret;
    visited[k][period][must] = kase;
    ret = -(1LL<<40);
    if(!must)
        ret = call(k, period+1, must) + arr[period];
    int i;
//    for(i = 1; i <= d+1 && period+i <= n && k; i++)
    int t = min(period+d, n);
    ret = max(ret, call(k-1, t, 0) + (cum[t-1] - cum[period])*m);
    ret = max(ret, call(k-1, period+1, 1) + (cum[period+1-1] - cum[period])*m);
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, k, i;
    cin >> test;
    while(test--)
    {
        ++kase;
//        clr(dp, -1);
        cin >> n >> k >> d >> m;
        for(i = 0; i < n; i++)
            cin >> arr[i];
        cum[0] = arr[0];
        for(i = 1; i < n; i++)
            cum[i] = cum[i-1] + arr[i];
        LL res = 0, jog = 0;
        for(i = n-1; i >= 0; i--)
        {
            if(n-i < k) continue;
            res = max(res, call(k, i, 1) + (i > 0?cum[i-1]:0));
        }
        cout << res << "\n";
    }
    return 0;
}
