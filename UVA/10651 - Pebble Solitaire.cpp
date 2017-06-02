#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define VI vector <int>
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

#define SZ 1000010
using namespace std;

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;}
//LL Pow(LL B,LL P){  LL R = 1; while(P > 0)  {if(P % 2 == 1) R = (R*B);P /= 2;B = (B*B); } return R;}
//LL bigmod(LL n,LL p){ if(p == 0) return 1; LL a = bigmod(n, p / 2) % mod; if(p % 2 == 1) return (a*a*n) % mod; return (a*a) % mod;}

int dp[1 << 12 + 10];
string s;

int set_bit(int n, int pos)
{
    return n = n | (1 << pos);
}

int reset(int n, int pos)
{
    return n = n & ~(1 << pos);
}

bool check(int n, int pos)
{
    return n & (1 << pos);
}

int call(int mask)
{
    int pebbles, &ret = dp[mask], tem;
    if(ret != -1) return ret;
    ret = pebbles = no_of_ones(mask);
    for(int i = 0; i < 10; i++)
    {
        if(check(mask, i) == 0 && check(mask, i + 1) && check(mask, i + 2))
        {
            tem = reset(mask, i + 1);
            tem = set_bit(tem, i);
            tem = reset(tem, i + 2);
            pebbles = call(tem);
        }
        ret = min(ret, pebbles);
        if(check(mask, i) && check(mask, i + 1) && check(mask, i + 2) == 0)
        {
            tem = reset(mask, i + 1);
            tem = set_bit(tem, i + 2);
            tem = reset(tem, i);
            pebbles = call(tem);
        }
        ret = min(ret, pebbles);
    }
    return ret;
}

int main()
{
    _
    int line, i, mask;
    cin >> line;
    while(line--)
    {
        clr(dp, -1);
        cin >> s;
        mask = 0;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == 'o')
                mask = set_bit(mask, i);
        }
        cout << call(mask) << endl;
    }
    return 0;
}


