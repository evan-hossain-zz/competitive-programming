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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

pair <LL, LL> arr[65], dp[65][65][2];
LL num;
int n;

pair <LL, LL> call(int indx, int last)
{
    if(indx < 0) return make_pair(1, 0);
    pair <LL, LL> &ret = dp[n][indx][last], tem;
    if(ret.first != -1) return ret;
    if(last == -1)
    {
        tem = call(indx - 1, 1);
        ret.first = tem.first;
        ret.second = tem.second + tem.first;
    }
    if(last == 0)
    {
        ret = call(indx - 1, 0);
        tem = call(indx - 1, 1);
        ret.first += tem.first;
        ret.second += tem.second + tem.first;
    }
    if(last == 1)
        ret = call(indx - 1, 0);
    return ret;
}


LL baki(int indx, int last, LL need)
{
    if(indx < 0 || !need) return 0;
    LL ret = 0;
    if(last == -1)
        return baki(indx - 1, 1, need) + need;
    if(last == 1)
        return baki(indx - 1, 0, need);
    if(call(indx - 1, 0).first <= need)
    {
        need -= call(indx - 1, 0).first;
        ret += call(indx - 1, 0).second;
    }
    else
        return baki(indx - 1, 0, need);
    if(!need) return ret;
    if(call(indx - 1, 1).first <= need)
    {
        ret += call(indx - 1, 1).second + need;
        need -= call(indx - 1, 1).first;
    }
    else
        return baki(indx - 1, 1, need) + ret + need;
    return ret;
}

LL aro_baki(int indx, int last, LL tomo, int left)
{
    if(indx < 0 || !left) return 0;
    left--;
    LL tem;
    if(last == -1)
        return 1 + aro_baki(indx - 1, 1, tomo, left);

    if(last == 0)
    {
        tem = call(indx - 1, 0).first;
        if(tem >= tomo)
            return aro_baki(indx - 1, 0, tomo, left);
        else
            tomo -= tem;
        return aro_baki(indx - 1, 1, tomo, left) + 1;
    }
    if(last == 1)
    {
        tem = call(indx - 1, 0).first;
        if(tem >= tomo)
            return aro_baki(indx - 1, 0, tomo, left);
    }
    return 0;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL total_length, cur, res, need, now;
    clr(dp, -1);
    arr[0].first = arr[0].second = 1;
    while(scanf("%lld", &num) == 1)
    {
        if(num == 0)
        {
            printf("0\n");
            continue;
        }
        res = 1;
        total_length = 1;
        for(n = 1; n < 64; n++)
        {
            arr[n] = call(n, -1);
            cur = arr[n].first * (n + 1);
            if(total_length + cur >= num)
                break;
            total_length += cur;
            res += arr[n].second;
        }
        need = ((num - total_length) - ((num - total_length) % (n + 1))) / (n + 1);
        if(need)
        {
            now = baki(n, -1, need);
            res += now;
        }
        if((num - total_length) % (n + 1))
            res += aro_baki(n, -1, need + 1, (num - total_length) % (n + 1));
        printf("%lld\n", res);
    }
    return 0;
}
