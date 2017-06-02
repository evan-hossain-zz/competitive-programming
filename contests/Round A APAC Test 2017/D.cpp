#include <bits/stdc++.h>

#define in freopen("D-small-attempt0.in", "r", stdin);
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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 1010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int L[MAX], dp[12][MAX], C[MAX][MAX], A[MAX][MAX], K[MAX];

int call(int indx, int baki)
{
    if(baki < 0)
        return -infinity;
    if(indx < 1)
        return 0;
    int &ret = dp[indx][baki];
    if(ret != -1)
        return ret;
    ret = call(indx-1, baki) + A[indx][L[indx]];
    int sum = 0;
    for(int i = max(1, L[indx]); i < K[indx]; i++)
    {
        ret = max(ret, call(indx-1, baki-C[indx][i]-sum) + A[indx][i+1]);
        sum += C[indx][i];
    }
    return ret;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, kase = 1, n, m, i, j;
    cin >> test;
    while(test--)
    {
        cin >> m >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> K[i] >> L[i];
            for(j = 1; j <= K[i]; j++)
                cin >> A[i][j];
            for(j = 1; j < K[i]; j++)
                cin >> C[i][j];
        }
        clr(dp, -1);
        cout << "Case #" << kase++ << ": " << call(n, m) << "\n";
        cerr << "Case #" << kase-1 << ": " << call(n, m) << "\n";
    }
    return 0;
}
