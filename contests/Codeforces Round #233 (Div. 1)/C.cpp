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

#define MAX 500010
/*************************************************HABIJABI ENDS HERE******************************************************/

LL x[MAX], o[MAX];

int main()
{
    string ss, sf;
    LL a, b, i, A, B;
    cin >> a >> b;
    A = a, B = b;
    LL fs = 0, sc = 0;
    for(i = 0; i < a + b; i++)
        sf += '0';
    for(i = 0; i < A - B; i++)
    {
        sf[i] = 'o';
        o[i] = 1;
        a--;
    }
    while(a > 0 && b > 0)
    {
        sf[i] = 'o';
        o[i] = 1;
        sf[i + 1] = 'x';
        x[i + 1] = 1;
        a--, b--, i += 2;
    }
    while(a > 0) sf[i] = 'o', o[i] = 1, a--, i++;
    while(b > 0) sf[i] = 'x', x[i] = 1, b--, i++;
    for(i = 1; i < SZ(sf); i++)
    {
        if(o[i])
            o[i] += o[i - 1], o[i - 1] = 0;
        if(x[i])
            x[i] += x[i - 1], x[i - 1] = 0;
    }
    for(i = 0; i < SZ(sf); i++)
    {
        fs -= (sqr(x[i]));
        fs += (sqr(o[i]));
    }

    clr(x, 0);
    clr(o, 0);

    a = A, b = B;
    for(i = 0; i < a + b; i++)
        ss += '0';
    for(i = 0; i < A - B; i++)
    {
        ss[i] = 'o';
        o[i] = 1;
        a--;
    }
    while(a > 0 && b > 0)
    {
        ss[i + 1] = 'o';
        o[i + 1] = 1;
        ss[i] = 'x';
        x[i] = 1;
        a--, b--, i += 2;
    }
    while(a > 0) ss[i] = 'o', o[i] = 1, a--, i++;
    while(b > 0) ss[i] = 'x', x[i] = 1, b--, i++;
    for(i = 1; i < SZ(ss); i++)
    {
        if(o[i])
            o[i] += o[i - 1], o[i - 1] = 0;
        if(x[i])
            x[i] += x[i - 1], x[i - 1] = 0;
    }
    for(i = 0; i < SZ(ss); i++)
    {
        sc -= (sqr(x[i]));
        sc += (sqr(o[i]));
    }

    if(fs > sc)
        cout << fs << endl << sf << endl;
    else
        cout << sc << endl << ss << endl;
    return 0;
}

