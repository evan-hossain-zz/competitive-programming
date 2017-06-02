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

#define MAX 100
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL dp[MAX][2][3][2], N, len;

LL call(int indx, int chhoto, int taken, int start)
{
    if(indx < 0)
        return taken == 1;
    LL &ret = dp[indx][chhoto][taken][start];
    if(ret != -1) return ret;
    ret = call(indx-1, chhoto || (N&(1LL<<indx)), min(2, taken+1)*start, start);
    if((N&(1LL<<indx)) || chhoto)
        ret += call(indx-1, chhoto, taken, 1);
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    cin >> N;
    N--;
    LL tem = N;
    while(tem)
        len++, tem/=2;
    clr(dp, -1);
    LL res = 0;
    if(N)
        res -= call(len-1, 0, 0, 0);
    cin >> N;
    tem = N;
    len = 0;
    while(tem)
        len++, tem/=2;
    clr(dp, -1);
    res += call(len-1, 0, 0, 0);
    cout << res;
    return 0;
}
