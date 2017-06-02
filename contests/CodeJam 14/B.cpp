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

#define MAX 11
/*************************************************HABIJABI ENDS HERE******************************************************/

string arr[MAX];
LL n, valid[MAX][MAX], mod = 1000000007;

//LL call(int indx, int mask, int last)
//{
//    cout << indx << ' ' << mask << ' ' << last << endl;
//    if(indx > n)
//        return 1;
//    LL &ret = dp[indx][mask][last];
//    if(ret != -1) return ret;
//    ret = 0;
//    int flag = 0;
//    for(int i = 1; i <= n; i++)
//    {
//        if(last == 0)
//        {
//            ret = (ret + call(indx + 1, mask | (1 << i), i)) % mod;
//            continue;
//        }
//        if((mask & (1 << i)) || ((arr[i][0] - 'a') != last)) continue;
//        ret = (ret + call(indx + 1, mask | (1 << i), last)) % mod;
//        if(arr[i][0] - 'a' == last || arr[i][SZ(arr[i]) - 1] - 'a' == last)
//            flag++;
//    }
//    if(flag)
//        return ret;
//    for(int i = 1; i <= n; i++)
//    {
//        if(mask & (1 << i)) continue;
//        ret = (ret + call(indx + 1, mask | (1 << i), arr[i][SZ(arr[i]) - 1] - 'a')) % mod;
//    }
//    return ret;
//}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1;
    cin >> test;
    while(test--)
    {
        bool flag = false;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int cnt = 0;
            cin >> arr[i];
            for(int j = 1; j < SZ(arr[i]); j++)
                if(arr[i][j - 1] != arr[i][j])
                    cnt++;
            if(cnt > 1) flag = true;
        }
        if(flag)
            printf("Case #%d: 0\n", kase++);
        else
        {
            vector <int> tem;
            for(int i = 1; i <= n; i++) tem.pb(i);
            LL res = 0;
            do
            {
                string ss;
                for(int i = 0; i < n; i++)
                    ss += arr[tem[i]];
                for(i = 0; i < SZ(tem); tem++)
                res += flag;
                print_all(tem);
                cout << endl;
            }while(next_permutation(all(tem)));
            printf("%lld\n", res);
        }
    }
    return 0;
}

