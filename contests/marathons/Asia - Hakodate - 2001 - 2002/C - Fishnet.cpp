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

struct PT
{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p)  const{ return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p)  const{ return PT(x-p.x, y-p.y); }
    PT operator * (double c)  const{ return PT(x*c, y*c ); }
    PT operator / (double c)  const{ return PT(x/c, y/c ); }
};

double dot(PT p, PT q) { return p.x*q.x+p.y*q.y; }
double cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }

PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
    b=b-a;
    d=c-d;
    c=c-a;
    assert(dot(b, b) > eps && dot(d, d) > eps);
    return a + b*cross(c, d)/cross(b, d);
}

double ComputeArea(const vector <PT> &p)
{
    double area = 0;
    for(int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return fabs(area / 2.0);
}

vector <double> a, b, c, d;
vector <PT> pre, cur, intermediate;

int main()
{
    #ifdef Evan
        in;
//        out;
    #endif
    int n, i, j;
    double tem, mx;
    intermediate.resize(4);
    while(scanf("%d", &n) == 1 && n)
    {
        a.resize(n + 2);
        b.resize(n + 2);
        c.resize(n + 2);
        d.resize(n + 2);
        pre.resize(n + 2);
        cur.resize(n + 2);
        mx = -1;
        a[0] = b[0] = c[0] = d[0] = 0;
        pre[0] = PT(0, 0);
        for(i = 1; i <= n; i++)
            scanf("%lf", &a[i]), pre[i] = PT(a[i], 0);
        for(i = 1; i <= n; i++)
            scanf("%lf", &b[i]);
        for(i = 1; i <= n; i++)
            scanf("%lf", &c[i]);
        for(i = 1; i <= n; i++)
            scanf("%lf", &d[i]);
        n++;
        a[n] = b[n] = c[n] = d[n] = 1;
        pre[n] = PT(1, 0);
        for(i = 1; i <= n; i++) // for b-d
        {
            for(j = 0; j <= n; j++) // for a-b
                cur[j] = ComputeLineIntersection(PT(a[j], 0), PT(b[j], 1), PT(0, c[i]), PT(1, d[i]));
            for(j = 1; j <= n; j++)
            {
                intermediate[0] = pre[j - 1];
                intermediate[1] = pre[j];
                intermediate[2] = cur[j];
                intermediate[3] = cur[j - 1];
                mx = max(mx, ComputeArea(intermediate));
            }
            pre = cur;
        }
        printf("%.6lf\n", mx);
    }
    return 0;
}


