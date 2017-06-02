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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 33
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

string s;
pair<LL, LL> dp[MAX][2][2];

pair<LL, LL> call(int indx, bool start, bool chhoto)
{
    if(indx == SZ(s))
        return mp(0, start);
    pair<LL, LL> &ret = dp[indx][start][chhoto], tem;
    if(ret.first != -1) return ret;
    ret = mp(0, 0);
    char lim = chhoto?'9':s[indx], i;
    for(i = '0'; i <= lim; i++)
    {
        tem = call(indx+1, start|(i>'0'), chhoto|(i < lim));
        if((start|(i>'0')) && (i == '0'))
            ret.first += tem.second;
        ret.second += tem.second;
        ret.first += tem.first;
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1;
    char l[MAX], r[MAX];
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s %s", l, r);
        clr(dp, -1);
        s = r;
        LL res = call(0, 0, 0).first;
        if(strcmp(l, "0"))
        {
            s = tostring(extract(l, 1)-1);
            clr(dp, -1);
            res -= call(0, 0, 0).first;
        }
        else
            res++;
        printf("Case %d: %lld\n", kase++, res);
    }
    return 0;
}
