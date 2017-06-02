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
#define in freopen("basketball_game.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

struct player
{
    string name;
    int shot, height, minute_played, ranked;
}arr[35];

bool comp(const player &a, const player &b)
{
    if(a.shot != b.shot)
        return a.shot > b.shot;
    return a.height > b.height;
}
bool comp_now(const player &a, const player &b)
{
    if(a.minute_played != b.minute_played)
        return a.minute_played < b.minute_played;
    return a.ranked < b.ranked;
}

int main()
{
//    in;
//    out;
    int test, p, n, m, i;
    cin >> test;
    for(int kase = 1; kase <= test; kase++)
    {
        vector <player> nowa, nowb, resta, restb;
        cin >> n >> m >> p;
        for(i = 0; i < n; i++)
            cin >> arr[i].name >> arr[i].shot >> arr[i].height, arr[i].minute_played = 0;
        sort(arr, arr + n, comp);
        for(i = 0; i < n; i++)
            arr[i].ranked = i + 1;
        for(i = 0; i < 2 * p; i += 2)
        {
            nowa.pb(arr[i]);
            nowb.pb(arr[i + 1]);
        }
        for(; i < n; i++)
        {
            resta.pb(arr[i++]);
            if(i < n)
                restb.pb(arr[i]);
        }
        while(m--)
        {
            for(i = 0; i < SZ(nowa); i++)
                nowa[i].minute_played++;
            for(i = 0; i < SZ(nowb); i++)
                nowb[i].minute_played++;
            sort(nowa.begin(), nowa.end(), comp_now);
            sort(nowb.begin(), nowb.end(), comp_now);
            resta.pb(nowa[SZ(nowa) - 1]);
            restb.pb(nowb[SZ(nowb) - 1]);
            nowa.pop_back();
            nowb.pop_back();
            sort(resta.begin(), resta.end() - 1, comp_now);
            sort(restb.begin(), restb.end() - 1, comp_now);
            nowa.pb(resta[0]);
            resta.erase(resta.begin());
            nowb.pb(restb[0]);
            restb.erase(restb.begin());
        }
        vector <string> ans;
        for(i = 0; i < SZ(nowa); i++)
            ans.pb(nowa[i].name);
        for(i = 0; i < SZ(nowb); i++)
            ans.pb(nowb[i].name);
        sort(all(ans));
        printf("Case #%d:", kase);
        for(i = 0; i < SZ(ans) - 1; i++)
            cout << ' ' << ans[i];
        cout << ' ' << ans[i] << endl;
    }
    return 0;
}
