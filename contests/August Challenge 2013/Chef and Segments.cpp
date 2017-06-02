#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
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

#define SZ 100010
using namespace std;

LL arr[SZ][110];
struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;}
//LL Pow(LL B,LL P){  LL R = 1; while(P > 0)  {if(P % 2 == 1) R = (R*B);P /= 2;B = (B*B); } return R;}
LL mod, ans;
//LL bigmod(LL n,LL p){ if(p == 0) return 1; LL a = bigmod(n, p / 2) % mod; if(p % 2 == 1) return (a*a*n) % mod; return (a*a) % mod;}
LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P >>= 1LL;B=(B*B)%M;} return R;}

LL primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};


int main()
{
    _
//    in;
//    out;
//    clr(arr, 0);
    LL n, i, j, l, r, t, num;
    scanf("%lld", &n);
    for(i = 1; i <= n; i++)
    {
        set <LL> S;
        scanf("%lld", &num);
        while(num > 1)
        {
            for(j = 0; j < 25; j++)
            {
                while(num % primes[j] == 0)
                {
                    arr[i][primes[j]]++;
                    num /= primes[j];
                }
            }
        }
    }
    for(i = 0; i < 25; i++)
    {
        for(j = 1; j <= n; j++)
            arr[j][primes[i]] += arr[j - 1][primes[i]];
    }
//    for(i = 0; i < 10; i++)
//    {
//        for(j = 0; j < 25; j++)
//            cout << arr[i][primes[j]] << ' ';
//        cout << endl;
//    }
    scanf("%lld", &t);
    while(t--)
    {
        ans = 1;
        scanf("%lld %lld %lld", &l, &r, &mod);
        for(i = 0; i < 25; i++)
        {
            LL total_occurrence = arr[r][primes[i]] - arr[l - 1][primes[i]];
            if(total_occurrence > 0)
            {
                LL tem = bigmod(primes[i], total_occurrence, mod);
                ans = (tem * ans) % mod;
            }
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}
