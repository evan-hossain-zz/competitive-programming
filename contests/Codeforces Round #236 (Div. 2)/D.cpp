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

#define MAX 5010
/*************************************************HABIJABI ENDS HERE******************************************************/

bool is_prime[1010];
vector <int> primes;
void sieve()
{
    int i, j;
    is_prime[1] = 1;
    for(i = 4; i <= 1010; i += 2)
        is_prime[i] = 1;
    for(i = 3; i < 1010 / i; i += 2)
    {
        if(is_prime[i] != 1)
        {
            for(j = 2; j * i < 1010; j++)
                is_prime[i * j] = 1;
        }
    }
    for(i = 2; i < 1010; i++)
        if(!is_prime[i])
            primes.pb(i);
}
vector < pair<int, int> > good_prime[MAX], bad_prime[MAX];
int arr[MAX];
map <int, int> bad;

int main()
{
    sieve();
    int n, bd, i, j, tem;
    cin >> n >> bd;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    for(i = 0; i < bd; i++)
    {
        cin >> j;
        bad[j] = 1;
    }

    for(i = 0; i < n; i++)
    {
        tem = arr[0];
        int gdp, cnt;
        for(j = 0; primes[j] <= tem; j++)
        {
            if(tem % primes[j] == 0)
            {
                cnt = 0;
                while(tem % primes[j] == 0)
                {
                    cnt++;
                    tem /= primes[j];
                }
                if(bad.find(primes[j]) == bad.end())
                    good_prime[i].pb(make_pair(primes[j], cnt));
                else
                    bad_prime[i].pb(make_pair(primes[j], cnt));
            }
        }
        sort(all(good_prime[i]));
        sort(all(bad_prime[i]));
    }
    for(i = 0; i < n; i++)
    {
        int bhag = 1, r;
        if(bad_prime[j].empty() || bad_prime[j][0].first == 1)
            break;
        bhag = arr[0];
        for(j = 1; j < n; j++)
        {
            if(gcd(bhag, arr[j]) == 1)
                break;
            bhag = gcd(bhag, arr[j]);
        }
        r = j;
        for(j = 0; j < r; j++)
        {
            arr[j] /= bhag;
            for(int k = 0; k < SZ(bad_prime); k++)
            {
                if(bad_prime[k].first)
            }
        }
    }
    return 0;
}

