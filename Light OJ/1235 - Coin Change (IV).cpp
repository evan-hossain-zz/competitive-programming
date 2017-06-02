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
#define gcd(a, b) __gcd(a, b)
#define fast_input_output ios_base::sync_with_stdio(0);cin.tie(0);
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

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

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

#define MAX 60000
/*************************************************HABIJABI ENDS HERE******************************************************/
int more_bit[12], dp[MAX], visited[MAX], cur, lef[12], rig[12], n;
map <int, int> mp;

int get_bit(int mask , int pos)
{
    return (mask / more_bit[pos]) % 3;
}

int set_bit(int mask, int pos , int bit)
{
    int tmp = (mask / more_bit[pos]) % 3;
    mask -= tmp * more_bit[pos];
    mask += bit * more_bit[pos];
    return mask;
}

void init(void)
{
    more_bit[0] = 3;
    for(int i = 1; i < 10; i++) more_bit[i] = 3 * more_bit[i - 1];
}

void left_call(int mask)
{
    if(mask == more_bit[n] - 1)
        return;
    int &ret = dp[mask], bit, i, &vis = visited[mask];
    if(vis == cur) return;
    vis = cur;
    ret = 0;
    for(i = 0; i < n; i++)
    {
        bit = get_bit(mask, i);
        ret += (lef[i] * bit);
        if(bit == 0) left_call(set_bit(mask, i, 1));
        if(bit < 2) left_call(set_bit(mask, i, 2));
    }
    mp[ret] = 1;
}
void right_call(int mask)
{
    if(mask == more_bit[n] - 1)
        return;
    int &ret = dp[mask], bit, i, &vis = visited[mask];
    if(vis == cur) return;
    vis = cur;
    ret = 0;
    for(i = 0; i < n; i++)
    {
        bit = get_bit(mask, i);
        ret += (rig[i] * bit);
        if(bit == 0) right_call(set_bit(mask, i, 1));
        if(bit < 2) right_call(set_bit(mask, i, 2));
    }
}

int main()
{
    init();
    int k, i, test, kase = 1, tot, lim;
    scanf("%d", &test);
    while(test--)
    {
        mp.clear();
        scanf("%d %d", &tot, &k);
        lim = tot >> 1;
        for(i = 0; i < lim; i++)
            scanf("%d", &lef[i]);
        for(; i < tot; i++)
            scanf("%d", &rig[i - lim]);
        n = tot >> 1;
        cur++;
        left_call(0);
        n = tot - n;
        cur++;
        right_call(0);
        for(i = 0; i <= more_bit[n]; i++)
        {
            if(mp.find(k - dp[i]) != mp.end())
                break;
        }
        if(i <= more_bit[n])
            printf("Case %d: Yes\n", kase++);
        else
            printf("Case %d: No\n", kase++);
    }
    return 0;
}
