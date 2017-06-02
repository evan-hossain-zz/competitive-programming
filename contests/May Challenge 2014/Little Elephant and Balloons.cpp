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

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}}; // for coordinates;

template <class T> T sqr(T a){return a * a;} // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;} // n to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));} // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;} // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();} // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;} // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';} // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 41
/*************************************************HABIJABI ENDS HERE******************************************************/

int n, m;
pair <int, int> arr[MAX];
double dp[MAX][MAX][MAX], sum[MAX][MAX][MAX];

double call(int indx, int taken, int last)
{
    if(indx == n)
        return taken >= m;
    double &ret = dp[indx][taken][last];
    if(ret > -.5) return ret;
    ret = call(indx + 1, taken + (arr[indx].first != last), arr[indx].first);
    ret += call(indx + 1, taken, last);
    return ret;
}

double get_sum(int indx, int taken, int last)
{
    if(indx == n) return 0;
    double &ret = sum[indx][taken][last];
    if(ret > -.5) return ret;
    ret = (call(indx + 1, taken + (arr[indx].first != last), arr[indx].first) * arr[indx].second) + get_sum(indx + 1, taken + (arr[indx].first != last), arr[indx].first);
    ret += get_sum(indx + 1, taken, last);
    return ret;
}

int main()
{
    #ifdef Evan
    // in;
    // out;
    #endif
    int test, i;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
            scanf("%d %d", & arr[i].first, &arr[i].second);
        sort(arr, arr + n);
        clr(dp, -1);
        clr(sum, -1);
        double way = call(0, 0, 0), total = get_sum(0, 0, 0);
        if(abs(way - 0) > eps)
            printf("%.8lf\n", total / way);
        else
            printf("0.000000000\n");
    }
    return 0;
}
