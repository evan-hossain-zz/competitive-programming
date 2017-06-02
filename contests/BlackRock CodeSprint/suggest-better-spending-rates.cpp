#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int arrT[22], T[22];
LL p, t, thresh, orgsum;
double r;
vector <pair <double, vector<int>>> res;

double calc(int t, int *arr)
{
    double ret = p*arr[t]*pow(1+r, t)/pow(100, t);
    for(int i = 1; i < t; i++)
        ret *= 100-arr[i];
    return ret;
}

vector <int> tem;
void get()
{
    double ret = 0;
    tem.clear();
    for(int i = 1; i <= t; i++)
    {
        ret += calc(i, T);
        tem.pb(T[i]);
    }
    res.pb(mp(ret, tem));
    sort(res.rbegin(), res.rend());
    if(SZ(res) > 3)
        res.resize(3);
}

void rec(int indx, int sum, int extra)
{
    if(abs(extra) > (t-indx+1)*thresh)
        return;
    if(indx > t)
    {
        if(sum == orgsum)
            get();
        return;
    }
    for(int i = max(0ll, arrT[indx]-thresh); i <= min(99ll, arrT[indx]+thresh); i++)
    {
        T[indx] = i;
        rec(indx+1, sum+i, extra+arrT[indx]-i);
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    cin >> p >> r >> t >> thresh;
    r /= 100;
    double org = 0;
    for(int i = 1; i <= t; i++)
    {
        cin >> arrT[i];
        orgsum += arrT[i];
        org += calc(i, arrT);
    }
    cout << setprecision(3) << fixed;
    cout << org << "\n";
    rec(1, 0, 0);
    for(auto x: res)
    {
        cout << x.first << " - ";
        for(auto y: x.second)
            cout << y << ' ';
        cout << "\n";
    }
    return 0;
}
