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
#define infinity (1<<28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 500010


pair <int, int> dp[2][205];
vector <int> adj[205];

pair <int, int> call(bool take, int indx)
{
    pair <int, int> &ret = dp[take][indx];
    if(ret.first != -1)
        return ret;
    pair <int, int> ret1, ret2, tem;
    ret1.first = ret2.first = ret1.second = ret2.second = 0;
    int i, lim = SZ(adj[indx]);
    for(i = 0; i < lim; i++)
    {
        tem = call(1, adj[indx][i]);
        ret1.first += tem.first;
        ret1.second = max(ret1.second, tem.second);
    }
    if(take)
    {
        ret2.first = 1;
        for(i = 0; i < lim; i++)
        {
            tem = call(0, adj[indx][i]);
            ret2.first += tem.first;
            ret2.second = max(ret2.second, tem.second);
        }
    }
    if(ret1.first > ret2.first)
        ret = ret1;
    else
        ret = ret2;
    if(ret1.first == ret2.first) ret.second = 1;
    return ret;
}

int main()
{
    int a, b, cntr, n;
    char str[110], str2[110];
    string s;
    while(scanf("%d", &n) == 1 && n)
    {
        for(cntr = 0; cntr <= n; cntr++)
            adj[cntr].clear();
        map<string, int> mp;
        cntr = 1;
        scanf(" %s", str);
        s = str;
        mp[s] = cntr++;
        n--;
        while(n--)
        {
            scanf(" %s %s", str, str2);
            s = str;
            if(mp.find(s) == mp.end())
                mp[s] = cntr++;
            a = mp[s];
            s = str2;
            if(mp.find(s) == mp.end())
                mp[s] = cntr++;
            b = mp[s];
            adj[b].pb(a);
        }
        clr(dp, -1);
        printf("%d ", call(1, 1).first);
        if(dp[1][1].second != 1)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

