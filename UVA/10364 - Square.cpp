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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 1050000
/*************************************************HABIJABI ENDS HERE******************************************************/

int need, n, arr[21];
vector <int> valid;
bool found, dp[4][1 << 20];

void call(int side, int mask)
{
    if(found) return;

    if(side == 4)
    {
        found = true;
        return;
    }
    bool &ret = dp[side][mask];
    if(ret) return;
    ret = 1;
    for(int i = 0; i < n; i++)
    {
        if(mask & valid[i]) continue;
        call(side + 1, mask | valid[i]);
    }
}

int main()
{
    #ifdef Evan
//        in;
    #endif
    int test, i, total;
    scanf("%d", &test);
    while(test--)
    {
        valid.clear();
        clr(dp, 0);
        scanf("%d", &n);
        total = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            total += arr[i];
        }
        if(total % 4)
        {
            printf("no\n");
            continue;
        }
        need = total / 4;
        for(i = 1; i < (1 << n); i++)
        {
            total = 0;
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j))
                    total += arr[j];
            }
            if(total == need)
                valid.pb(i);
        }
        n = SZ(valid);
        found = 0;
        call(0, 0);
        if(found)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}

