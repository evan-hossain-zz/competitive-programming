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

int n, y, X[MAX], res[MAX], m;
bool visited[MAX][10*MAX];
float dp[MAX][10*MAX];

float call(int indx, int baki)
{
    if(indx == n)
        return baki?1e9:0.0;
    float &ret = dp[indx][baki];
    if(visited[indx][baki]) return ret;
    visited[indx][baki] = 1;
    ret = call(indx+1, baki) + abs((1.0*X[indx]/y) - (1.0*res[indx]/m));
    if(baki)
        ret = min(ret, call(indx+1, baki-1) + (float) abs((1.0*X[indx]/y) - ((1.0*res[indx]+1)/m)));
    return ret;
}

void go(int indx, int baki)
{
    if(baki == 0 || indx == n)
        return;
    if(abs(dp[indx][baki] - (call(indx+1, baki) + abs((1.0*X[indx]/y) - (1.0*res[indx]/m)))) < 1e-6)
    {
        go(indx+1, baki);
        return;
    }
    go(indx+1, baki-1);
    res[indx] += 1;
}

int main()
{
        in;
        out;
    int i, M;
    cin >> n >> m >> y;
    M = m;
    for(i = 0; i < n; i++)
        cin >> X[i];
    for(i = 0; i < n; i++)
    {
        res[i] = (int) (1.0*X[i]*m/y);
        M -= res[i];
    }
    call(0, M);
    go(0, M);
    for(i = 0; i < n; i++)
        cout << res[i] << ' ';
    return 0;
}
