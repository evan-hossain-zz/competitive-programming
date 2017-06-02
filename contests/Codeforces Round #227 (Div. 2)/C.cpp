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

#define MAX 500010
/*************************************************HABIJABI ENDS HERE******************************************************/

int cnt;

bool isBig(string a, string b)
{
    cout << "first" << a << ' ' << b << endl;
    int i, j;
    string tem;
    for(i = 0; i < SZ(a); i++)
    {
        if(a[i] == '0')
            continue;
        tem = a.substr(i);
        break;
    }
    a = tem;
    tem.clear();
    for(i = 0; i < SZ(b); i++)
    {
        if(b[i] == '0')
            continue;
        tem = b.substr(i);
        break;
    }
    b = tem;
    cout << "infunc" << a << ' ' << b <<  cnt << endl;
    if(a.empty() || b.empty()) return false;
    for(i = 0, j = 0; i < min(SZ(a), SZ(b)); i++)
    {
        cout << "infunc" << a << ' ' << b <<  cnt << endl;
        if(a[i] < b[i] && ((SZ(a) - i) <= SZ(b) - i))
            return false;
        if(j == SZ(b) - 1)
            return true;
        if(i == SZ(a) - 1)
            return false;
    }
    return true;
}

int main()
{
    string s, a, b, last;
    int n, i, j, k;
    cin >> s;
    for(i = SZ(s) - 2, k = 1; SZ(s) > 1 && i >= 0; i--, k++)
    {
        a.clear();
        b.clear();
        for(j = 0; j <= i; j++)
            a += s[j];
        for(; j < SZ(s); j++)
            b += s[j];
        if(a.empty() || b.empty())
            continue;
        cout << a << ' ' << b << ' ' << cnt << endl;
        if(isBig(a, b))
            cnt++, s.resize(SZ(s) - k), k = 0, last = b;
        cout << "now S" << s << endl;
    }
    if(!cnt) cnt++;
    cout << cnt << endl;
    return 0;
}


