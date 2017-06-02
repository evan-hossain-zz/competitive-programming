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
#define eps 1e-7

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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 15
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int health[MAX], shot[MAX][MAX], dp[1 << 15], n;

int call(int mask)
{
    if(mask == (1 << n) - 1)
        return 0;
    int &ret = dp[mask], i, j, need;
    if(ret != -1) return ret;
    ret = infinity;
    for(i = 0; i < n; i++)
    {
        if(mask & (1 << i)) continue;
        need = 1;
        for(j = 0; j < n; j++)
        {
            if(shot[j][i] && (mask & (1 << j)))
                need = max(need, shot[j][i]);
        }
        need = (health[i] / need) + (health[i] % need != 0);
        ret = min(ret, call(mask | (1 << i)) + need);
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int test, kase = 1, i, j;
    char ch;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> health[i];
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                cin >> ch;
                shot[i][j] = ch - '0';
            }
        }
        memset(dp, -1, 1 << (n + 2));
        cout << "Case " << kase++ << ": " << call(0) << "\n";
    }
    return 0;
}

