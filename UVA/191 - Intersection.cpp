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


bool on_segment(point p, point q, point r) // q point lies between p and r
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

int check(const point &O, const point &A, const point &B) //checks rotation
{
        int rotation = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
        if(rotation == 0) return 0;
        return rotation > 0? 1 : -1;
}

bool intersects(point p1, point p2, point q1, point q2)
{
    int d1 = check(p1, p2, q1);
    int d2 = check(p1, p2, q2);
    int d3 = check(q1, q2, p1);
    int d4 = check(q1, q2, p2);
    if(d1 != d2 && d3 != d4)
        return true;
    if(!d1 && on_segment(p1, q1, p2)) return true;
    if(!d2 && on_segment(p1, q2, p2)) return true;
    if(!d3 && on_segment(q1, p1, q2)) return true;
    if(!d4 && on_segment(q1, p2, q2)) return true;
    return false;
}

void fix(point &a, point &b)
{
    if(a.x > b.x)
        swap(a, b);
}

int main()
{
    point l, r, a, b, c, d;
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d %d %d %d %d %d %d", &l.x, &l.y, &r.x, &r.y, &a.x, &a.y, &c.x, &c.y);
        fix(l, r);
        fix(a, c);
        b.x = a.x, b.y = c.y;
        d.x = c.x, d.y = a.y;
        if(intersects(l, r, a, b) ||
           intersects(l, r, a, d) ||
           intersects(l, r, b, c) ||
           intersects(l, r, c, d) ||
           (check(a, b, l) == check(b, c, l) &&
           check(c, d, l) == check(d, a, l) &&
           check(c, d, l) == check(a, b, l)) )
            printf("T\n");
        else
            printf("F\n");
    }
    return 0;
}

