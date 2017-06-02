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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

double dp[1<<18][19], arr[20][20];
bool visited[1<<18][19];
int n;

double call(int mask, int alive)
{
    if(no_of_ones(mask)+1 == n)
        return alive == 0;
    double &ret = dp[mask][alive];
    bool &visit = visited[mask][alive];
    if(visit)
        return ret;
    visit = 1;
    ret = 0;
    for(int i = 0; i < n; i++)
    {
        if((mask & (1<<i)) || i == alive)
            continue;
        ret = max(ret, call(mask|(1<<i), alive)*arr[alive][i] + call(mask|(1<<alive), i)*arr[i][alive]);
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    cout << setprecision(10) << fixed;
    int i, j;
    cin >> n;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> arr[i][j];
    double res = 0;
    for(i = 0; i < n; i++)
        res = max(res, call(0, i));
    cout << res << endl;
    return 0;
}
