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

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

int low[MAX], tim[MAX], col[MAX], n, timer;
vector <int> adj[MAX];
stack <int> st;
LL res, mod = 1000000007;

bool is_prime[MAX];
vector <int> primes;

void sieve()
{
    int i, j;
    is_prime[1] = 1;
    for(i = 4; i <= MAX; i += 2)
        is_prime[i] = 1;
    for(i = 3; i < MAX / i; i += 2)
    {
        if(is_prime[i] != 1)
        {
            for(j = 2; j * i < MAX; j++)
                is_prime[i * j] = 1;
        }
    }
    for(i = 2; i < MAX; i++)
        if(!is_prime[i]) primes.pb(i);
}

int cnt[MAX];

void scc(int u)
{
    low[u] = tim[u] = timer++;
    col[u] = 1;
    st.push(u);
    int i, elements = adj[u].size(), v, tem;
    for(i = 0; i < elements; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(col[v] == 0)
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == tim[u])
    {
        LL items = 0;
        do
        {
            tem = st.top();
            st.pop();
            col[tem] = 2;
            items++;
        }
        while(tem != u);
        for(i = 0; primes[i] * primes[i] <= items; i++)
        {
            if(items % primes[i] == 0)
            {
                tem = 0;
                while(items % primes[i] == 0)
                    items /= primes[i], tem++;
                cnt[primes[i]] = max(cnt[primes[i]], tem);
            }
        }
        if(items > 1)
            cnt[items] = max(cnt[items], 1);
    }
}

void call_for_scc_check()
{
    timer = 0;
    clr(col, 0);
    int i;
    while(!st.empty()) st.pop();
    for(i = 1; i <= n; i++)
    {
        if(col[i] == 0)
            scc(i);
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    sieve();
    int test, i, j;
    scanf("%d", &test);
    while(test--)
    {
        clr(cnt, 0);
        res = 1;
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            adj[i].clear();
        for(i = 1; i <= n; i++)
            scanf("%d", &j), adj[i].pb(j);
        call_for_scc_check();
        for(i = 0; primes[i] <= n; i++)
            if(cnt[primes[i]]) res = (res * bigmod(primes[i], cnt[primes[i]], mod)) % mod;
        printf("%lld\n", res);
    }
    return 0;
}


