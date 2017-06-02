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
#define in freopen("D-large.in", "r", stdin);
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

#define MAX 10010
/*************************************************HABIJABI ENDS HERE******************************************************/

struct info
{
    string s, q;
    int num;
}arr[MAX];

int main()
{
    int a = 2000000000, b = 1000000000 - 1;
    a += b;
    cout << a / 2 << endl;
    CF
    int now, i, n;
    cin >> n;
    string s, q;
    set <int> cur;
    for(i = 0; i < n; i++)
    {
        cin >> s >> now >> q;
        arr[i].s = s, arr[i].num = now, arr[i].q = q;
        if(s == ">=")
        {
            if(q == "Y")
                cur.insert(now), cur.insert(now + 1);
            else
                cur.insert(now - 1);
        }
        if(s == ">")
        {
            if(q == "Y")
                cur.insert(now + 1);
            else
                cur.insert(now), cur.insert(now - 1);
        }
        if(s == "<=")
        {
            if(q == "Y")
                cur.insert(now - 1), cur.insert(now);
            else
                cur.insert(now + 1);
        }
        if(s == "<")
        {
            if(q == "Y")
                cur.insert(now - 1);
            else
                cur.insert(now + 1), cur.insert(now);
        }
    }

    set <int> :: iterator it;
    for(it = cur.begin(); it != cur.end(); it++)
    {
        int tem = *it;
        for(i = 0; i < n; i++)
        {
            s = arr[i].s, now = arr[i].num, q = arr[i].q;
            if(s == ">=")
            {
                if(q == "Y")
                {
                    if(tem < now)
                        break;
                }
                else
                    if(tem >= now)
                        break;

            }
            if(s == ">")
            {
                if(q == "Y")
                {
                    if(tem <= now)
                        break;
                }
                else
                    if(tem > now)
                        break;
            }
            if(s == "<=")
            {
                if(q == "Y")
                {
                    if(tem > now)
                        break;
                }
                else
                    if(tem <= now)
                        break;
            }
            if(s == "<")
            {
                if(q == "Y")
                {
                    if(tem >= now)
                        break;
                }
                else
                    if(tem < now)
                        break;
            }
        }
        if(i == n)
        {
            cout << tem << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}

