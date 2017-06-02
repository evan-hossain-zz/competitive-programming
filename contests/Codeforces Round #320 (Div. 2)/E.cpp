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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int arr[MAX], n;
double data[MAX];

double max_sum()
{
    int start = 0, en = 0, i;
    double sum = 0, ret = 0;
    for(i = 0; i < n; i++)
    {
        sum += data[i];
        if(sum < 0)
            sum = 0;
        else if(sum > ret)
            ret = sum;
    }
    return ret;
}

double check(double x)
{
    for(int i = 0; i < n; i++)
        data[i] = arr[i]-x;
    double ret1 = max_sum();
    for(int i = 0; i < n; i++)
        data[i] = x - arr[i];
    double ret2 = max_sum();
    return max(ret1, ret2);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    double m1, m2, low, high;
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    low = -2e9, high = 2e9;
    for(i = 0; i < 500; i++)
    {
        m1 = (low*2+high) / 3;
        m2 = (low+high*2) / 3;
        double a = check(m1);
        double b = check(m2);
        if(a > b)
            low = m1;
        else
            high = m2;
    }
    cout << setprecision(8) << fixed << check(low);
    return 0;
}
