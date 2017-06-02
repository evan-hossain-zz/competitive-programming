#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1LL << 50)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{LL x, y, i; point () {} point(LL a, LL b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> LL getdist(T a, T b){return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

struct PT {
  LL x, y, i;
  PT() {}
  PT(LL x, LL y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (LL c)     const { return PT(x*c,   y*c  ); }
  PT operator / (LL c)     const { return PT(x/c,   y/c  ); }
};
PT arr[MAX];
LL cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return abs(cross(b-a, c-d)) ==0;
}

bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d)
      && abs(cross(a-b, a-c))==0
      && abs(cross(c-d, c-a))==0;
}



int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y, arr[i].i = i+1;
    PT a = PT(1e18, 1e18), b(1e18, 1e18), c;
    for(i = 0; i < n; i++)
    {
        if(a.y > arr[i].y)
            a = arr[i];
        else if(a.y == arr[i].y && a.x > arr[i].x)
            a = arr[i];
    }
    for(i = 0; i < n; i++)
    {
        if(arr[i].x == a.x && arr[i].y == a.y) continue;
        if(b.y > arr[i].y)
            b = arr[i];
        else if(b.y == arr[i].y && b.x > arr[i].x)
            b = arr[i];
    }
    for(i = 0; i < n; i++)
    {
        if((arr[i].y == a.y && arr[i].x == a.x) || (arr[i].x == b.x && arr[i].y == b.y))
            continue;
        if(LinesCollinear(a, arr[i], b, arr[i]))
            continue;
        if(c.y > arr[i].y)
            c = arr[i];
        else if(c.y == arr[i].y && c.x > arr[i].x)
            c = arr[i];
    }
    cout << a.i << ' ' << b.i << ' ' << c.i << endl;
    return 0;
}
