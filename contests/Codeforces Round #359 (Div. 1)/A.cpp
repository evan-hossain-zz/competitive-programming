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

LL ncnt[1<<7], mcnt[1<<7];

LL to7(LL n)
{
    string s;
    while(n)
    {
        s += tostring(n%7);
        n /= 7;
    }
    reverse(all(s));
    return extract(s, 1LL);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, nlen = 0, mlen = 0, cur, mask, i, j, len;
    cin >> n >> m;
    int tem = n-1;
    while(tem)
        nlen++, tem /= 7;
    tem = m-1;
    while(tem)
        mlen++, tem /= 7;
    nlen = max(1, nlen);
    mlen = max(1, mlen);
    if(nlen+mlen > 7)
    {
        cout << "0";
        return 0;
    }
    for(i = 0; i < n; i++)
    {
        tem = i;
        len = 0;
        string s;
        while(tem)
            len++, s += tostring(tem%7), tem/=7;
        if(len > 7)
            break;
        mask = 0;
        while(len < nlen) s += "0", len++;
        reverse(all(s));
        for(j = 0; j < len; j++)
        {
            if(mask & (1<<(s[j]-'0')))
                break;
            mask |= (1<<(s[j]-'0'));
        }
        if(j == len)
            ncnt[mask]++;
    }
    for(i = 0; i < m; i++)
    {
        tem = i;
        len = 0;
        string s;
        while(tem)
            len++, s += tostring(tem%7), tem/=7;
        if(len > 7)
            break;
        mask = 0;
        while(len < mlen) s += "0", len++;
        reverse(all(s));
        for(j = 0; j < len; j++)
        {
            if(mask & (1<<(s[j]-'0')))
                break;
            mask |= (1<<(s[j]-'0'));
        }
        if(j == len)
            mcnt[mask]++;
    }
    LL res = 0;
    for(i = 1; i < (1<<7); i++)
        for(j = 1; j < (1<<7); j++)
            if((i & j) == 0)
                res += ncnt[i]*mcnt[j];
    cout << res;
    return 0;
}
