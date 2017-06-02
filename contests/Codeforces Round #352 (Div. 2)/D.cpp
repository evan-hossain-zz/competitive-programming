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

#define MAX 500010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int arr[MAX];
int tem[MAX], n, k;
priority_queue <int> Q;

int get(int mid)
{
    int i, pos = 0;
    for(i = 0; i < n; i++)
        tem[i] = arr[i];
    while(pos < n && tem[pos] <= mid)
        pos++;
    if(pos == n)
        return 2e9;
    while(!Q.empty())
        Q.pop();
    for(i = pos; i < n; i++)
        Q.push(tem[i]);
    int taken = 0;
    for(i = 0; i < pos; i++)
    {
        int t = Q.top();
        Q.pop();
        int mn = max(0, min(k-taken, min(mid-tem[i], t-mid)));
        tem[i] += mn;
        taken += mn;
        t -= mn;
        Q.push(t);
    }
    return Q.top()- *min_element(tem, tem+pos);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    arr[n] = 2e9;
    int low = arr[0], high = arr[n-1], mid, res = arr[n-1] - arr[0];
    while(low < high)
    {
        mid = (low+high) / 2;
        int l = get(mid), r = get(mid+1);
        if(l < r)
            low = mid+1, res = min(res, r);
        else
            high = mid-1, res = min(res, l);
    }
    for(i = max(arr[0], low-100); i < min(arr[n-1], high+100); i++)
        res = min(res, get(i));
    cout << res;
    return 0;
}
