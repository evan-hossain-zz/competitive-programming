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

template <class T> T sqr(T a){return a * a;}   // square
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

bool check(point a, point b, point c)
{
    point p, q;
    p.x = b.x - a.x, p.y = b.y - a.y;
    q.x = c.x - a.x, q.y = c.y - a.y;
    int ret = (p.x * q.y) - (p.y * q.x);
    if(ret > 0)
        return true;
    return false;
}

int main()
{
    _
    int n, i;
    while(cin >> n && n)
    {
        stack <point> S;
        point arr[55], tem;
        int lef = 0, rig = 0;
        for(i = 0; i < n; i++)
            cin >> arr[i].x >> arr[i].y;
        S.push(arr[1]);
        S.push(arr[2]);
        for(int I = 3; I <= n + 1; I++)
        {
            i = I % n;
            tem = S.top();
            S.pop();
            if(check(S.top(), tem, arr[i]))
                lef++;
            else
                rig++;
            S.pop();
            S.push(tem);
            S.push(arr[i]);
        }
        if(lef == 0 || rig == 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}


