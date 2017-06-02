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
template <class T> int getdist(T a, T b){return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 5000010
/*************************************************HABIJABI ENDS HERE******************************************************/

point arr_a[MAX], arr_b[MAX];

int main()
{
    #ifdef Evan
//        in;
    #endif
    int i, j, a, b, na, nb;
    cin >> a >> b;
    int cnt = 0;
    for(i = -a; i <= a; i++)
    {
        for(j = -a; j <= a; j++)
            if(sqr(i) + sqr(j) == sqr(a))
                arr_a[cnt].x = i, arr_a[cnt].y = j, cnt++;
    }
    na = cnt;
    cnt = 0;
    for(i = -b; i <= b; i++)
    {
        for(j = -b; j <= b; j++)
            if(sqr(i) + sqr(j) == sqr(b))
                arr_b[cnt].x = i, arr_b[cnt].y = j, cnt++;
    }
    nb = cnt;
    point zero(0, 0);
    for(i = 0; i < na; i++)
    {
//        cout << arr_a[i].x << ' ' << arr_a[i].y << endl;
        for(j = 0; j < nb; j++)
        {
            if(arr_a[i].x == 0 || arr_a[i].y == 0 || arr_b[j].x == 0 || arr_b[j].y == 0 ||
               arr_a[i].x == arr_b[j].x || arr_a[i].y == arr_b[j].y)
                continue;
            if(getdist(zero, arr_a[i]) + getdist(zero, arr_b[j]) == getdist(arr_a[i], arr_b[j]))
            {
                cout << "YES\n";
                cout << 0 << ' ' << 0 << endl;
                cout << arr_a[i].x << ' ' << arr_a[i].y << endl;
                cout << arr_b[j].x << ' ' << arr_b[j].y << endl;
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}

