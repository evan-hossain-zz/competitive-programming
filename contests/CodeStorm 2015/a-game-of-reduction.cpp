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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 1000010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int arr[MAX], dp[MAX][6], cum[3][MAX];

bool ok(int n, int step)
{
    if(step < 0 || n < 0) return 0;
    if(step == 0)
        return n < 10;
    if(n < 10)
        return step = 0;
    int &ret = dp[n][step];
    if(ret != -1) return ret;
    ret = 0;
    int l=1, r=1, d=0, tem = n, i;
    while(tem) d++, tem/=10;
    for(i=1; i<d;i++) l*=10;
    for(i=2; i<d;i++) r*=10;
    for(i=1;i<d;i++)
    {
        int ld = (n/l)%10;
        int rd = (n/r)%10;
        int lside = n/(l*10);
        int cur = lside*l+((ld+rd)%10)*r+n%r;
        ret |= ok(cur, step-1);
        l/=10;
        r/=10;
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    clr(dp, -1);
    for(int i = 1; i < MAX; i++)
    {
        int d = 0, tem = i, sum=0;
        while(tem) d++, tem/=10;
        if(ok(i, d-2))
            arr[i] = 2;
        else
            arr[i] = !(d%2);
        for(int j = 0; j < 3; j++)
            cum[j][i] = cum[j][i-1] + (arr[i]==j);
    }
    int test, n, m, i, x;
    cin >> test;
    while(test--)
    {
        cin >> n >> m;
        int cnt[3] = {0};
        for(i = 0; i < m; i++)
        {
            cin >> x;
            cnt[arr[x]]++;
        }
        LL res, mod = 1e9+7, t = cnt[2];
        int tot = 2*cnt[0]+cnt[1];
        cnt[0] = cum[0][n] - cnt[0];
        cnt[1] = cum[1][n] - cnt[1];
        cnt[2] = cum[2][n] - cnt[2];
        if(t%2)
        {
            if(cnt[2] == 0)
                res = 0;
            else
            {
                res = bigmod(2, cnt[0]+cnt[1], mod);
                if(cnt[2])
                    res = (res*bigmod(2, cnt[2]-1, mod))%mod;
                else
                    res--;
                res += mod;
                res %= mod;
            }
            cout << res << "\n";
            continue;
        }
        if(cnt[2] == 0)
        {
            if(tot%2==0)
            {
                res = bigmod(2, cnt[0], mod);
                if(cnt[1])
                    res = (res * bigmod(2, cnt[1]-1, mod))%mod;
                res--;
                res += mod;
                res %= mod;
            }
            else
            {
                res = bigmod(2, cnt[0], mod);
                if(cnt[1])
                    res = (res*bigmod(2, cnt[1]-1, mod))%mod;
                else
                    res--;
            }
            res += mod;
            res %= mod;
        }
        else
        {
            res = (res * bigmod(2, cnt[2]-1, mod))%mod;
            if(t>0)
                res = (res*bigmod(2, cnt[0]+cnt[1], mod))%mod;
            else if(tot%2)
            {
                res = (res*bigmod(2, cnt[0], mod))%mod;
                if(cnt[1])
                    res = (res*bigmod(2, cnt[1]-1, mod))%mod;
                else
                    res--;
                res += mod;
                res %= mod;
            }
            else
            {
                res = (res*bigmod(2, cnt[0], mod))%mod;
                if(cnt[1])
                    res = (res*bigmod(2, cnt[1]-1, mod))%mod;
//                else
                    res--;
                res += mod;
                res %= mod;
            }
        }
        cout << res << "\n";

    }
    return 0;
}
