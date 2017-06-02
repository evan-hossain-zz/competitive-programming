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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 200010
/*************************************************HABIJABI ENDS HERE******************************************************/

char str[32][32];
int h, w, mask, shesh = (1 << 26) - 1;
struct info
{
    int l, r, u, d;
    info(){};
    info(int _l, int _r, int _u, int _d)
    {
        l = _l;
        r = _r;
        u = _u;
        d = _d;
    }
};

info get(char ch)
{
    int i, j;
    info ret(100, -1, 100, -1);
    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(str[i][j] == ch)
            {
                ret.l = min(ret.l, j);
                ret.r = max(ret.r, j);
                ret.u = min(ret.u, i);
                ret.d = max(ret.d, i);
            }
        }
    }
    return ret;
}

info arr[27];
vector <string> res;
string now;

bool ok(char ch)
{
    int i;
    info cur = arr[ch - 'A'];
    for(i = cur.l; i <= cur.r; i++)
    {
        if(!((str[cur.u][i] == ch || (mask & (1 << (str[cur.u][i] - 'A')))) &&
            (str[cur.d][i] == ch || (mask & (1 << (str[cur.d][i] - 'A'))))))
            break;
    }
    if(i <= cur.r)
        return false;
    for(i = cur.u; i <= cur.d; i++)
    {
        if(!((str[i][cur.l] == ch || (mask & (1 << (str[i][cur.l] - 'A')))) &&
            (str[i][cur.r] == ch || (mask & (1 << (str[i][cur.r] - 'A'))))))
            break;
    }
    if(i <= cur.d)
        return false;
    return true;
}

void back_track()
{
    if(mask == shesh)
    {
        res.pb(now);
        return;
    }
    for(int i = 0; i < 26; i++)
    {
        if(mask & (1 << i)) continue;
        char ch = i + 'A';
        if(ok(ch))
        {
            now = ch + now;
            mask |= (1 << i);
            back_track();
            now.erase(0, 1);
            mask &= ~(1 << i);
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j;
    while(scanf("%d %d", &h, &w) == 2)
    {
        res.clear();
        mask = shesh;
        for(i = 0; i < h; i++)
        {
            scanf(" %s", str[i]);
            for(j = 0; j < w; j++)
                if(str[i][j] != '.') mask &= ~(1 << (str[i][j] - 'A'));
        }
        for(i = 0; i < 26; i++)
            if(!(mask & (1 << i))) arr[i] = get(i + 'A');
        back_track();
        sort(all(res));
        for(i = 0; i < SZ(res); i++)
            printf("%s\n", res[i].c_str());
    }
    return 0;
}



