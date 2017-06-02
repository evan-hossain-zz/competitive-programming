#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
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

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 2010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int h, arr[MAX], visited[MAX][MAX];
double dp[MAX][MAX], p;

double call(int l, int r)
{
    if(l > r) return 0;
    if(l == r) return h;
    int &visit = visited[l][r];
    double &ret = dp[l][r], L, R;
    if(visit) return ret;
    visit = 1;
    L = (call(l+1, r) + h)*p;
    R = (call(l, r-1) + h)*(1-p);
    int tl = l+1;
    while(tl <= r)
    {
        if(arr[tl]-arr[tl-1] < h)
            tl++;
        else
            break;
    }
    L += (call(tl, r) + (arr[tl-1]+h-arr[l])) * (1-p);
    int tr = r-1;
    while(tr >= l)
    {
        if(arr[tr+1]-arr[tr] < h)
            tr--;
        else
            break;
    }
    R += (call(l, tr) + (arr[r] - arr[tr+1]+h)) * p;
    if(arr[l+1]-arr[l] >= h)
        cout<<"OK"<<endl,L += (call(l+2, r) + 2*h)*(1-p)*p;
    if(arr[r] - arr[r-1] >= h)
        cout<<"OK"<<endl,R += (call(l, r-2) + 2*h) * p*(1-p);
    cout << tl << ' ' << tr << endl;
    ret = .5*L + .5*R;
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, i;
    cin >> n >> h >> p;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    cout << setprecision(8) << fixed << call(0, n-1);
    return 0;
}
