#include <bits/stdc++.h>

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
#define sz(name) (int)(name.size())

#define F(i, n) for(i = 0; i < n; i++)

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{double x, y; point () {} point(double a, double b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str;}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define SZ 1000010
/*************************************************HABIJABI ENDS HERE******************************************************/

point arr[10];

double check(const point &O, const point &A, const point &B)
{
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double area(point a, point b, point c)
{
//    return fabs((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y)));
    double C = getdist(a, b), A = getdist(b, c), B = getdist(a, c);
    double S = (A + B + C) / 2.0;
    return sqrt(S * (S - A) * (S - B) * (S - C));
}

int main()
{
    _
    point res;
    int i, j, k, l, cake = 1;
    double mn, lef, rig, total_area;
    while(cin >> arr[0].x >> arr[0].y)
    {
        for(i = 1; i < 4; i++)
            cin >> arr[i].x >> arr[i].y;
        for(i = 0; i < 4; i++)
        {
            if(arr[i].x == 0 && arr[i].y == 0)
                continue;
            else
                break;
        }
        if(i == 4)
            break;
        i = 4;
        arr[i].x = (arr[0].x + arr[1].x) / 2.0;
        arr[i++].y = (arr[0].y + arr[1].y) / 2.0;
        arr[i].x = (arr[1].x + arr[2].x) / 2.0;
        arr[i++].y = (arr[1].y + arr[2].y) / 2.0;
        arr[i].x = (arr[2].x + arr[3].x) / 2.0;
        arr[i++].y = (arr[2].y + arr[3].y) / 2.0;
        arr[i].x = (arr[3].x + arr[0].x) / 2.0;
        arr[i++].y = (arr[3].y + arr[0].y) / 2.0;
        total_area = area(arr[0], arr[1], arr[2]) + area(arr[0], arr[2], arr[3]);
        mn = total_area;
        lef = total_area - area(arr[0], arr[1], arr[5]);
        rig = area(arr[0], arr[1], arr[5]);
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[0], arr[1], arr[2]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[0], arr[6], arr[3]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[4], arr[1], arr[5]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[4], arr[1], arr[2]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[4], arr[1], arr[2]) + area(arr[4], arr[2], arr[6]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[4], arr[3], arr[0]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[4], arr[7], arr[0]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[1], arr[2], arr[6]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[1], arr[2], arr[3]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[1], arr[7], arr[0]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[5], arr[2], arr[6]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[5], arr[2], arr[3]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[5], arr[2], arr[3]) + area(arr[5], arr[3], arr[7]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[2], arr[3], arr[7]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        rig = area(arr[6], arr[3], arr[7]);
        lef = total_area - rig;
        if(fabs((lef - rig)) < mn && mn > 0)
        {
            mn = fabs((lef - rig));
            res.x = lef, res.y = rig;
        }
        printf("Cake %d: %.3lf %.3lf\n", cake++, min(res.x, res.y), max(res.x, res.y));
    }
    return 0;
}
/*
0 1 6 0 5 2 2 3
0 0 100 0 100 100 0 100
0 0 0 0 0 0 0 0
*/
