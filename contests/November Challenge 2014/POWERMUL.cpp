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
template <class T> void show(T a){cout << a << endl;}
template <class T> void show(T a, T b){cout << a << ' ' << b << endl;}
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
#define s 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

LL F[MAX];
LL arr[MAX], ans[MAX], add[MAX];
vector <LL> primes, changed;

LL col[s/64+10];
LL ma;

void seive()//1 indexed
{
    long long i,j;
    LL prev=0;
    primes.pb(2);
    for(i=3;i<s;i+=2)
         if(!(col[i/64]&(1LL<<(i%64))))
         {
             primes.pb(i);
               if((i%4)==1)
               {
                    ma=max(ma,i-prev);
                    prev=i;
                }
                for(j=i*i;j<s;j+=2*i)
                    col[j/64]|=(1LL<<(j%64));
         }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    seive();
    LL test, n, m, q, i, r, res, cnt, cur, mx, mn, gun;
    scanf("%lld", &test);
    while(test--)
    {
        scanf("%lld %lld %lld", &n, &m, &q);
        res = 1;
        for(r = 1; r <= n - r; r++)
        {
            changed.clear();
            cur = n - r + 1;
            for(i = 0; primes[i] <= cur; i++)
            {
                if(cur % primes[i] == 0)
                {
                    cnt = 0;
                    while(cur % primes[i] == 0)
                        cnt++, cur /= primes[i];
                    cnt *= (n - r + 1);
                    add[i] = cnt;
                    changed.pb(i);
                }
            }
            cur = r;
            for(i = 0; primes[i] <= cur; i++)
            {
                if(cur % primes[i] == 0)
                {
                    cnt = 0;
                    while(cur % primes[i] == 0)
                        cnt++, cur /= primes[i];
                    cnt *= r;
                    rem[i] = cnt;
                    changed.pb(i);
                }
            }
            for(i = 0; i < SZ(changed); i++)
        }
        for(set <LL> :: iterator it = have.begin(); it != have.end(); it++)
            arr[*it] = 0;
        for(i = 1; i <= q; i++)
        {
            scanf("%lld", &r);
            printf("%lld\n", ans[min(r, n-r)]);
        }

    }
    return 0;
}


