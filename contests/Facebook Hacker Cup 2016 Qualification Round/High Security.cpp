#include <bits/stdc++.h>

#define in freopen("high_security.txt", "r", stdin);
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

#define MAX 1010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int dp[MAX][3][3], n;
string s[2];

int call(int indx, int up, int down)
{
    if(indx==n)
    {
        if(up==1|down==1) return infinity;
        return 0;
    }
    int &ret = dp[indx][up][down];
    if(ret != -1) return ret;
    ret = infinity;
    if(s[0][indx] == 'X' && up == 1)
        return ret;
    if(s[1][indx] == 'X' && down == 1)
        return ret;
    if(s[0][indx] == 'X')
    {
        if(s[1][indx] == 'X')
            ret = min(ret, call(indx+1, 0, 0));
        else
        {
            ret = min(ret, call(indx+1, 0, max(down, 1)));
            if(down<2)
                ret = min(ret, call(indx+1, 0, 2)+1);
        }
    }
    if(s[0][indx] == '.')
    {
        if(s[1][indx] == 'X')
        {
            ret = min(ret, call(indx+1, max(up, 1), 0));
            if(up < 2)
                ret = min(ret, call(indx+1, 2, 0)+1);
        }
        else
        {
            ret = min(ret, call(indx+1, max(up, 1), max(down, 1)));
            if(up < 2)
                ret = min(ret, call(indx+1, 2, down)+1);
            if(down<2)
                ret = min(ret, call(indx+1, up, 2)+1);
            if(up < 2 && down < 2)
                ret = min(ret, call(indx+1, 2, 2)+2);
        }
    }
    return ret;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, kase = 1, i;
    cin >> test;
    while(test--)
    {
        cin >> n;
        cin >> s[0] >> s[1];
        clr(dp, -1);
        cout << "Case #" << kase++ << ": " << call(0, 0, 0) << "\n";
    }
    return 0;
}
