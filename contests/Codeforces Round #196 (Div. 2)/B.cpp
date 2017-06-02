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

struct point{int x, y;};    // for coordinates

template <class T> T sqr(T a){return a * a;};    // square
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

int main()
{
    _
    int a, b, c, d, scrn, mv, A, B, C, D;
    cin >> A >> B >> C >> D;
    a = A / gcd(A, B);
    b = B / gcd(A, B);
    c = C / gcd(C, D);
    d = D / gcd(C, D);
    if(a == b && c == d)
    {
        cout << "0/1" << endl;
        return 0;
    }
    if(a == b || a== c || b == d)
    {
        cout << max(c, d) - min(c, d) << '/' << max(c, d) << endl;
        return 0;
    }
    if(c == d)
    {
        cout << max(a, b) - min(a, b) << '/' << max(a, b) << endl;
        return 0;
    }
    mv = a * b;
    int mx = 0;
    int p, q, P, Q;
    p = min(c, d);
    q = max(c, d);
    p = mv * p;
    p = q * mv - p;
    P = p / gcd(q, p);
    Q = q / gcd(q, p);
    cout << min(P, Q) << "/" << max(P, Q) << endl;
    return 0;
}


