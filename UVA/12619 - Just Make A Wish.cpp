#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define in freopen("output.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 1000010
/*************************************************HABIJABI ENDS HERE******************************************************/

bool flag[MAX];
vector <int> primes;

void sieve()
{
    int i, j, r;
    flag[0] = flag[1] = 1;
    primes.pb(2);
    for(i = 3; i < MAX; i += 2)
    {
        if(!flag[i])
        {
            primes.pb(i);
            r = i * 2;
            if(MAX / i >= i) for(j = i * i; j < MAX; j += r) flag[j] = 1;
        }
    }
}

vector <pair <LL, LL> > factor[MAX];

bool is_prime(int n)
{
    if(n == 2)
        return 1;
    if(n % 2 == 0)
        return 0;
    return !flag[n];
}

void factorize(int n)
{
    int i, c, N = n;
    for(i = 0; primes[i] <= n / primes[i]; i++)
    {
        if(n % primes[i] == 0)
        {
            c = 0;
            while(n % primes[i] == 0)
            {
                n /= primes[i];
                c++;
            }
            factor[N].pb(make_pair(primes[i], c));
        }
    }
    if(n > 1)
    {
        factor[N].pb(make_pair(n, 1));
    }
}

const LL mod = 1000000007;

LL cnt[MAX];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    sieve();
    for(int i = 1; i < MAX; i++)
        factorize(i);
    int test, d, x, i, kase = 1;
    scanf("%d", &test);
    while(test--)
    {
        clr(cnt, 0);
        scanf("%d", &d);
        LL res = 1;
        LL ans = 0;
        while(d--)
        {
            scanf("%d", &x);
            if(x > 0)
            {
                for(i = 0; i < SZ(factor[x]); i++)
                {
                    res = (res * bigmod(cnt[factor[x][i].first] + 1, mod - 2, mod)) % mod;
                    cnt[factor[x][i].first] += factor[x][i].second;
                    res = (res * (cnt[factor[x][i].first] + 1)) % mod;
                }
            }
            else
            {
                x = -x;
                for(i = 0; i < SZ(factor[x]); i++)
                {
                    res = (res * bigmod(cnt[factor[x][i].first] + 1, mod - 2, mod)) % mod;
                    cnt[factor[x][i].first] -= factor[x][i].second;
                    res = (res * (cnt[factor[x][i].first] + 1)) % mod;
                }
            }
            ans = (ans + res) % mod;
        }
        printf("Case %d: %lld\n", kase++, ans);
    }
    return 0;
}


