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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

map <LL, pair <LL, pair<LL, LL> > > mpp[2];
map <pair <LL, LL>, LL> visited[2];

void call(LL a, LL b, LL t, int cur)
{
    if(a > b)
        swap(a, b);
    if(visited[cur].find(mp(a, b)) != visited[cur].end())
        return;
    visited[cur][mp(a, b)] = 1;
    mpp[cur][a * b] = mp(t, mp(a, b));
    if(a % 2 == 0)
        call(a / 2, b, t + 1, cur);
    if(b % 2 == 0)
        call(a, b / 2, t + 1, cur);
    if(a % 3 == 0)
        call(a - (a / 3), b, t + 1, cur);
    if(b % 3 == 0)
        call(a, b - (b / 3), t + 1, cur);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    LL a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    call(a1, b1, 0, 0);
    call(a2, b2, 0, 1);
    LL res = 1LL << 60;
    pair <LL, LL> a, b;
    for(auto it = mpp[0].begin(); it != mpp[0].end(); it++)
    {
        if(mpp[1].find(it->first) != mpp[1].end())
        {
            if(mpp[1][it->first].first + it->second.first < res)
            {
                res = mpp[1][it->first].first + it->second.first;
                a = it->second.second;
                b = mpp[1][it->first].second;
            }
        }
    }
    if(res == (1LL << 60))
    {
        cout << "-1";
        return 0;
    }
    cout << res << endl;
    cout << a.first << ' ' << a.second << endl;
    cout << b.first << ' ' << b.second << endl;
    return 0;
}

