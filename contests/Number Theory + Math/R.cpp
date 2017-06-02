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

#define MAX 100000100
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL col[MAX/64+10];
int primes[5800000], k;
unsigned int arr[5800000];

void seive()//1 indexed
{
    long long i,j;
    k=0;
    LL prev=0;
    primes[k++] = 2;
    for(i=3; i<MAX; i+=2)
        if(!(col[i/64]&(1LL<<(i%64))))
        {
            primes[k++] = i;
            if((i%4)==1)
                prev=i;
            for(j=i*i; j<MAX; j+=2*i)
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
    int test, kase = 1, n, i;
    arr[0] = 2;
    for(i = 1; i < k; i++)
        arr[i] = arr[i-1] * primes[i];
    unsigned int res;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        res = 1;
        for(i = 0; primes[i] * primes[i] <= n; i++)
        {
            LL cur = primes[i];
            while(cur * primes[i] <= n)
                cur *= primes[i];
            res *= cur/primes[i];
        }
        int pos = upper_bound(primes+i-1, primes+k, n) - primes;
        pos--;
        res *= arr[pos];
        printf("Case %d: %u\n", kase++, res);
    }
    return 0;
}
