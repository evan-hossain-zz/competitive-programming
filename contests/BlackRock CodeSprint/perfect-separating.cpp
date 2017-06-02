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

map <tuple<int,int,int>, LL> dp;
string s;
int cnt[200];
LL ncr[55][55];
LL call(int indx, int a, int hashA, int b, int hashB)
{
    if(a > SZ(s)/2 || b > SZ(s)/2)
        return 0;
    if(indx == SZ(s))
        return hashA == hashB;
    tuple<int,int,int> f = mt(a, hashA, b);
//    cout << indx << ' ' << a << ' ' << hashA << ' ' << b << ' ' << hashB << endl;
    if(dp.find(f) != dp.end())
        return dp[f];
    LL &ret = dp[f];
    ret = 0;
    if(s[indx] == 'a')
    {
        ret += call(indx+1, a+1, hashA, b, hashB);
        ret += call(indx+1, a, hashA, b+1, hashB);
    }
    else
    {
        ret += call(indx+1, a+1, hashA+(1<<a), b, hashB);
        ret += call(indx+1, a, hashA, b+1, hashB+(1<<b));
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j;
    for(i = 1; i < 55; i++)
    {
        ncr[i][1] = i;
        for(j = 2; j <= i; j++)
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
    }
    cin >> s;
    for(auto x: s)
        cnt[x]++;
    if(cnt['a']%2 || cnt['b']%2)
    {
        cout << 0;
        return 0;
    }
//    if(cnt['a'] == SZ(s) || cnt['b'] == SZ(s))
//    {
//        cout << ncr[SZ(s)][SZ(s)/2];
//        return 0;
//    }
    cout << call(0, 0, 0, 0, 0);
    return 0;
}
