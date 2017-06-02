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
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
//#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
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
template <class T> int getdist(T a, T b){return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

struct info
{
    int a, b, c;
    info(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
};

int main()
{
    point arr[20], p;
    pair <int, int> pp[20];
    vector <info> v;
    int i, j, k, n, a, b, c;
    while(scanf("%d", &n) == 1 && n)
    {
        v.clear();
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &pp[i].first, &pp[i].second);
        }
        sort(pp, pp + n);
        i = 0;
        arr[i].x = pp[0].first, arr[i].y = pp[0].second;
        for(j = 1; j < n; j++)
        {
            if(pp[j].first != arr[i].x || pp[j].second != arr[i].y)
            {
                i++;
                arr[i].x = pp[j].first, arr[i].y = pp[j].second;
            }
        }
        n = i + 1;
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
                for(k = j + 1; k < n; k++)
                {
                    a = getdist(arr[i], arr[j]);
                    b = getdist(arr[j], arr[k]);
                    c = getdist(arr[i], arr[k]);
                    vector <int> tem;
                    tem.pb(a);
                    tem.pb(b);
                    tem.pb(c);
                    sort(all(tem));
                    double d1 = (double) sqrt((double)tem[0]) + (double) sqrt((double)tem[1]);
                    double d2 = (double) sqrt((double)tem[2]);
                    if(d1 <= d2 + eps)
                        continue;
                    v.pb(info(tem[0], tem[1], tem[2]));
                }
        int ans = 0;
        for(i = 0; i < SZ(v); i++)
        {
            int cnt = 1;
            for(j = i + 1; j < SZ(v); j++)
            {
                int g = gcd(v[j].a, v[i].a), aa, bb, cc, aaa, bbb, ccc;
                aa = v[i].a / g;
                aaa = v[j].a / g;
                g = gcd(v[j].b, v[i].b);
                bb = v[i].b / g;
                bbb = v[j].b / g;
                g = gcd(v[j].c, v[i].c);
                cc = v[i].c / g;
                ccc = v[j].c / g;
                if((aa == bb && bb == cc) &&
                    (aaa == bbb && bbb == ccc))
                    cnt++;
            }
            ans = max(cnt, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}

