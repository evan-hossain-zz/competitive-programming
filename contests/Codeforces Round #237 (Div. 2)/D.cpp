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

#define MAX 1000010
/*************************************************HABIJABI ENDS HERE******************************************************/

char arr[MAX];
const LL mod = 1000000007;
LL dp[MAX][4][4], n;

LL call(int indx, int keep, int last)
{
//    cout << indx << ' ' << keep << ' ' << last << endl;
    if(indx == n)
    {
        if((keep == 0 && (arr[indx] == '0' || arr[indx] == '?')) ||
           (keep == 1 && (arr[indx] == '1' || arr[indx] == '?') && last == 3) ||
           (keep == 3 && (arr[indx] == '*' || arr[indx] == '?')))
            return 1;
        else
            return 0;
    }
    LL &ret = dp[indx][keep][last];
    if(ret != -1) return ret;
    ret = 0;
    if(keep == 0 && (arr[indx] == '0' || arr[indx] == '?'))
        ret = (call(indx + 1, 0, 0) + call(indx + 1, 1, 0)) % mod;
    if(keep == 1 && (arr[indx] == '1' || arr[indx] == '?'))
    {
        if(last <= 1)
            ret = call(indx + 1, 3, 1);
        if(last == 3)
            ret = (call(indx + 1, 0, 1) + call(indx + 1, 1, 1)) % mod;
    }
    if(keep == 2 && (arr[indx] == '2' || arr[indx] == '?'))
    {
        if(last == 3)
            ret = call(indx + 1, 3, 2);
    }
    if(keep == 3 && (arr[indx] == '*' || arr[indx] == '?'))
    {
        if(last == 0)
            ret = call(indx + 1, 1, 3);
        else
            ret = (call(indx + 1, 1, 3) + call(indx + 1, 2, 3) + call(indx + 1, 3, 3)) % mod;
    }
    return ret;
}

int main()
{
    fast_input_output
    clr(dp, -1);
    int i;
    string s;
    cin >> s;
    n = SZ(s);
    for(i = 0; i < SZ(s); i++)
        arr[i + 1] = s[i];
    LL ans = 0;

    if(arr[1] == '0' || arr[1] == '?')
        ans = (call(2, 0, 0) + call(2, 1, 0)) % mod;
    if(arr[1] == '1' || arr[1] == '?')
        ans = (ans + call(2, 3, 1)) % mod;
    if(arr[1] == '*' || arr[1] == '?')
        ans = (ans + call(2, 1, 3) + call(2, 2, 3) + call(2, 3, 3)) % mod;

    if(s == "?")
        cout << 2 << endl;
    else if(s == "0" || s == "*")
        cout << 1 << endl;
    else
        cout << ans << endl;
    return 0;
}
