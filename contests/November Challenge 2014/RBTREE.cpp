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
/*************************************************HABIJABI ENDS HERE******************************************************/


bool check(string &s, LL lev, LL tree)
{
    if(tree)
    {
        if(s == "Qb")
            return lev % 2;
        else
            return lev % 2 == 0;
    }
    if(s == "Qr")
        return lev % 2;
    else
        return lev % 2 == 0;
    return false;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    LL q, x, y, lx, ly, tree, minlevel, res;
    string s;
    cin >> q;
    tree = 1; ///root black
    while(q--)
    {
        cin >> s;
        if(s == "Qi")
        {
            tree = !tree;
            continue;
        }
        cin >> x >> y;
        lx = log2(x) + 1;
        ly = log2(y) + 1;
        res = 0;
        minlevel = min(lx, ly);

        while(lx > minlevel)
        {
            res += check(s, lx, tree);
            x /= 2;
            lx--;
        }
        while(ly > minlevel)
        {
            res += check(s, ly, tree);
            y /= 2;
            ly--;
        }

        while(x != y)
        {
            res +=  (2 * check(s, lx, tree));
            x /= 2;
            y /= 2;
            lx--;
        }
        res += check(s, lx, tree);

        cout << res << "\n";
    }
    return 0;
}


