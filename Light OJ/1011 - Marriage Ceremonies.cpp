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

int dp[17][(1 << 16) + 5], n, arr[17][17];

int set_bit(int n, int pos)
{
    return n = n | (1 << pos);
}

int reset(int n, int pos)
{
    return n = n | ~(1 << pos);
}

bool check(int n, int pos)
{
    return n & (1 << pos);
}

int call(int row, int mask)
{
    int &ret = dp[row][mask], tem, i;
    if(mask == (1 << n) - 1) return ret = 0;
    if(ret != -1) return ret;
    for(i = 0; i < n; i++)
    {
        if(check(mask, i) == 0)
        {
            tem = call(row + 1, set_bit(mask, i)) + arr[row][i];
            ret = max(tem, ret);
        }
    }
    return ret;
}

int main()
{
    _
    int i, j, test, kase;
//    cin >> test;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        clr(dp, -1);
//        cin >> n;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
//                cin >> arr[i][j];
                scanf("%d", &arr[i][j]);
//        cout << "Case " << kase << ": " << call(0, 0) << endl;
        printf("Case %d: %d\n", kase, call(0, 0));
    }
    return 0;
}

