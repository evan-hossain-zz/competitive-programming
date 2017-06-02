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
template <class T> void show(T a){cout << a << endl;}
template <class T> void show(T a, T b){cout << a << ' ' << b << endl;}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 5000010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

pair <LL, LL> arr[MAX];
LL hit[MAX];

bool comp(const pair <LL, LL> &a, const pair <LL, LL> &b)
{
    return a.first * b.second < a.second * b.first;
}

bool iseq(int i, int j)
{
    auto a = arr[i];
    auto b = arr[j];
    return a.first * b.second == a.second * b.first;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    LL n, x, y, i;
    cin >> n >> x >> y;
    for(i = 1; i <= x; i++)
        arr[i] = mp(i, x);
    for(i = 1; i <= y; i++)
        arr[i+x] = mp(i, y);
    sort(arr + 1, arr + x + y + 1, comp);
    for(i = 1; i <= n; i++)
    {
        cin >> hit[i];
        hit[i] %= (x + y);
        if(hit[i] == 0)
            hit[i] = x + y;
        if(arr[hit[i]].second == x)
        {
            if(arr[hit[i] - 1].second == y && iseq(hit[i], hit[i] - 1))
            {
                cout << "Both" << "\n";
            }
            else if(arr[hit[i] + 1].second == y && iseq(hit[i], hit[i] + 1))
            {
                cout << "Both" << "\n";
            }
            else
                cout << "Vanya" << "\n";
        }
        else if(arr[hit[i]].second == y)
        {
            if(arr[hit[i] - 1].second == x && iseq(hit[i], hit[i] - 1))
            {
                cout << "Both" << "\n";
            }
            else if(arr[hit[i] + 1].second == x && iseq(hit[i], hit[i] + 1))
            {
                cout << "Both" << "\n";
            }
            else
                cout << "Vova" << "\n";
        }
    }
    return 0;
}

