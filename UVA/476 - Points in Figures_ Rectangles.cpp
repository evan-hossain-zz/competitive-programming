#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{double x, y;};    // for coordinates

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str;}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define SZ 1000010
/*************************************************HABIJABI ENDS HERE******************************************************/

struct rectangle
{
    double a, b, c, d;
    int fig;
};

bool check(point a, point b, point c)
{
    point p, q;
    p.x = b.x - a.x, p.y = b.y - a.y;
    q.x = c.x - a.x, q.y = c.y - a.y;
    double ret = (p.x * q.y) - (p.y * q.x);
    if(ret > 0 + 10e-7)
        return true;
    return false;
}

int main()
{
    _
    vector <rectangle> rect;
    vector <int> ans;
    rectangle rtem;
    point p;
    char ch;
    int n, i, fig = 1, point_no = 1;
    while(cin >> ch && ch != '*')
    {
        if(ch == 'r')
        {
            cin >> rtem.a >> rtem.b >> rtem.c >> rtem.d;
            rtem.fig = fig++;
            rect.pb(rtem);
        }
    }
    while(cin >> p.x >> p.y && !(p.x == 9999.9 && p.y == 9999.9))
    {
        ans.clear();
        for(i = 0; i < rect.size(); i++)
        {
            point a, b, c, d;
            d.x = rect[i].a, d.y = rect[i].b;
            b.x = rect[i].c, b.y = rect[i].d;
            a.x = d.x, a.y = b.y;
            c.x = b.x, c.y = d.y;
            if(check(a, b, p) && check(b, c, p) && check(c, d, p) && check(d, a, p))
                ans.pb(rect[i].fig);
        }
        if(ans.empty())
        {
            printf("Point %d is not contained in any figure\n", point_no++);
            continue;
        }
        sort(all(ans));
        for(i = 0; i < ans.size(); i++)
            printf("Point %d is contained in figure %d\n", point_no, ans[i]);
        point_no++;
    }
    return 0;
}



