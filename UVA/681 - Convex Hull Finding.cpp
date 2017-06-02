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
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str;}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define SZ 520
/*************************************************HABIJABI ENDS HERE******************************************************/

point hull[SZ], O;

int check(const point &O, const point &A, const point &B)
{
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool comp_angle(const point &a, const point &b)
{
    if(check(O, a, b) > 0)
        return true;
    else if(check(O, a, b) == 0)
        return getdist(O, a) < getdist(O, b);
    return false;
}
int next_to_top(stack <int> &S)
{
    int p = S.top();
    S.pop();
    int ret = S.top();
    S.push(p);
    return ret;
}
int make_hull(point convex[], int n)
{
    stack <int> S;
    int i, p = 0;
    for(i = 1; i < n; i++)
    {
        if(convex[p].y > convex[i].y)
            p = i;
        else if(convex[p].y == convex[i].y && convex[p].x > convex[i].x)
            p = i;
    }
    swap(convex[0], convex[p]);
    O = convex[0];
    sort(convex + 1, convex + n, comp_angle);
    for(i = 1; i < n; i++)
    {
        if(convex[0].x == convex[i].x && convex[0].y == convex[i].y)
            continue;
        break;
    }
    S.push(0), S.push(i);
    for(i = i + 1 ; i < n; i++)
    {
        while(S.size() > 1 && check(convex[next_to_top(S)], convex[S.top()], convex[i]) <= 0)
            S.pop();
        S.push(i);
    }
    n = S.size();
    for(i = S.size() - 1; i >= 0; i--)
    {
        hull[i] = convex[S.top()];
        S.pop();
    }
    return n;
}
int main()
{
    _
    int n, k, i, dummy;
    point arr[SZ];
    cin >> k;
    cout << k << endl;
    while(k--)
    {
        cin >> n;
        F(i, n)
            cin >> arr[i].x >> arr[i].y;
        if(k)
            cin >> dummy;
        n = make_hull(arr, n);
        cout << n + 1 << endl;
        for(i = 0; i < n; i++)
            cout << hull[i].x << ' ' << hull[i].y << endl;
        cout << hull[0].x << ' ' << hull[0].y << endl;
        if(k)
            cout << -1 << endl;
    }
    return 0;
}


