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
#define infinity 214748364
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define SZ(v) (int)(v.size())
#define eps 10e-7

#define F(i, n) for(i = 0; i < n; i++)

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
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 17
/*************************************************HABIJABI ENDS HERE******************************************************/


int pre[MAX][MAX], dp[1 << 16], n;
point arr[MAX];
int check(point o, point a, point b)
{
    return ((a.x - o.x) * (b.y - o.y)) - ((a.y - o.y) * (b.x - o.x)) == 0;
}

int call(int mask)
{
    int &ret = dp[mask];
    if(ret != -1)
        return ret;
    if((mask == ((1 << n) - 1)))
        return 0;
    ret = infinity;
    for(int i = 0; i < n; i++)
    {
        if(mask&(1<<i))
            continue;
        for(int j=i;j<n;j++)
        {
            if(mask & (1 << j))
                continue;
//            cout << i << ' ' << j << ' ' << call(i + 1, mask | pre[i][j]) << endl;
            ret = min(ret, call(mask | pre[i][j]) + 1);
        }
        break;
    }
    return ret;
}

int main()
{
    _
    int i, test, kase, j, k;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf("%d", &n);
        clr(pre, 0);
        clr(dp, -1);
        for(i = 0; i < n; i++)
            scanf("%d %d", &arr[i].x, &arr[i].y);
        for(i = 0; i < n; i++)
        {
            pre[i][i] = 1;
            for(j = i + 1; j < n; j++)
            {
//                pre[i][j] |= (1 << i) | (1 << j);
                for(k = 0; k < n; k++)
                {
                    if(check(arr[i], arr[k], arr[j]))
                        pre[i][j] |= (1 << k);
                }
                pre[j][i] = pre[i][j];
            }
        }
//        cout << "pre" << pre[0][0] << endl;
        printf("Case %d: %d\n", kase, call(0));
    }
    return 0;
}
