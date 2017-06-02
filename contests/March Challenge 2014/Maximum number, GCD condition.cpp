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

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast_input_output ios_base::sync_with_stdio(0);cin.tie(0);
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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

bool is_prime[100005];
vector <int> primes;
void sieve()
{
    int i, j;
    is_prime[1] = 1;
    for(i = 4; i <= 100005; i += 2)
        is_prime[i] = 1;
    for(i = 3; i < 100005 / i; i += 2)
    {
        if(is_prime[i] != 1)
        {
            for(j = 2; j * i < 100005; j++)
                is_prime[i * j] = 1;
        }
    }
    for(i = 2; i < 100005; i++)
        if(!is_prime[i])
            primes.pb(i);
}

vector <int> occur[MAX], segtree[MAX], freq[MAX], G;
int arr[MAX], now;

void update(int L, int R, int indx, int val, int cur)
{
    if(L == R)
    {
        segtree[now][cur] = val;
        return;
    }
    int mid = (L + R) >> 1;
    if(indx <= mid)
        update(L, mid, indx, val, cur << 1);
    else
        update(mid + 1, R, indx, val, (cur << 1) + 1);
    segtree[now][cur] = max(segtree[now][cur << 1], segtree[now][(cur << 1) + 1]);
}

int query(int L, int R, int lb, int rb, int cur)
{
    if(L > rb || R < lb)
        return 0;
    if(L >= lb && R <= rb)
        return segtree[now][cur];
    int mid = (L + R) >> 1;
    return max(query(L, mid, lb, rb, cur << 1),
    query(mid + 1, R, lb, rb, (cur << 1) + 1));
}

int main()
{
    sieve();
    int n, m, i, j, tem, l, r, val, L, R;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        tem = arr[i];
        freq[tem].pb(i);
        for(j = 0; primes[j] <= sqrt(tem); j++)
        {
            if(tem % primes[j] == 0)
            {
                occur[primes[j]].pb(i);
                while(tem % primes[j] == 0)
                    tem /= primes[j];
            }
        }
        if(tem > 1)
            occur[tem].pb(i);
    }

    for(i = 0; i < SZ(primes); i++)
    {
        now = primes[i];
        segtree[now].resize(4 * SZ(occur[now]));
        n = SZ(occur[now]);
        for(j = 0; j < n; j++)
            update(1, n, j + 1, arr[occur[now][j]], 1);
    }
    int mx;
    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d", &val, &l, &r);
        L = l, R = r;
        mx = 0;
        for(j = 0; primes[j] <= sqrt(val); j++)
        {
            if(val % primes[j] == 0)
            {
                now = primes[j];
                l = lower_bound(occur[now].begin(), occur[now].end(), L) - occur[now].begin();
                r = upper_bound(occur[now].begin(), occur[now].end(), R) - occur[now].begin();
                mx = max(mx, query(1, SZ(occur[now]), l + 1, r, 1));
                while(val % now == 0)
                    val /= now;
            }
        }
        if(val > 1)
        {
            now = val;
            l = lower_bound(occur[now].begin(), occur[now].end(), L) - occur[now].begin();
            r = upper_bound(occur[now].begin(), occur[now].end(), R) - occur[now].begin();
            mx = max(mx, query(1, SZ(occur[now]), l + 1, r, 1));
        }
        if(mx)
            printf("%d %d\n", mx, upper_bound(all(freq[mx]), R) - lower_bound(all(freq[mx]), L));
        else
            printf("-1 -1\n");
    }
    return 0;
}

