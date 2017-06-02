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
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

struct info
{
    double dist, consumption;
    string type;
    info()
    {
        type.clear();
    }
}events[55];

bool check(int n, double tanksize)
{
    int i, leaks = 0;
    double cons = events[0].consumption, tank = tanksize;
    double travel = 0;
    for(i = 1; i < n; i++)
    {
        tank -= ((events[i].dist - travel) * cons / 100.0);
        if(0.0 > tank)
            return false;
        travel = events[i].dist;
        if(events[i].type == "consumption")
        {
            cons = events[i].consumption + (leaks * 100.0);
            continue;
        }
        if(events[i].type == "Leak")
        {
            cons += 100;
            leaks++;
            continue;
        }
        if(events[i].type == "station")
        {
            tank = tanksize;
            continue;
        }
        if(events[i].type == "Mechanic")
        {
            cons -= (leaks * 100);
            leaks = 0;
        }
        if(events[i].type == "Goal")
            return true;
    }
}

int main()
{
    _
    int i, x, y, n;
    while(cin >> events[0].dist >> events[0].type >> events[0].type >> events[0].consumption)
    {
        if(events[0].dist == 0.0 && events[0].consumption == 0.0)
            break;
        int i = 1;
        double low = 0, high, mid;
        while(cin >> events[i].dist >> events[i].type)
        {
            if(events[i].type == "Goal")
                break;
            if(events[i].type == "Fuel")
            {
                cin >> events[i].type;
                cin >> events[i].consumption;
            }
            else if(events[i].type == "Gas")
                cin >> events[i].type;
            i++;
        }
        high = 100000000;
        n = i + 1;
        for(i = 0; i < 50; i++)
        {
            mid = (low + high) / 2.0;
            if(check(n, mid))
                high = mid;
            else
                low = mid;
        }
        printf("%.3lf\n", mid);
    }
    return 0;
}

