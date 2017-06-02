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

#define MAX 60010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int segtree[MAX*4];
vector <int> open[MAX], close[MAX];

struct rect{
    int x1, x2, y1, y2;
}arr[MAX];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1, n, i, mc;
    scanf("%d", &test);
    while(test--)
    {
        LL res = 0;
        map <int,int> mpp, ulta;
        mc = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d %d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
            mpp[arr[i].x1], mpp[arr[i].y1];
            mpp[arr[i].x2], mpp[arr[i].y2];
        }
        for(map<int,int> :: iterator it = mpp.begin(); it != mpp.end(); it++)
        {
            it->second = ++mc;
            ulta[mc] = it->first;
        }
        open.clear();
        close.clear();
        set <int> ss;
        for(i = 0; i < n; i++)
        {
            arr[i].x1 = mpp[arr[i].x1];
            arr[i].x2 = mpp[arr[i].x2];
            arr[i].y1 = mpp[arr[i].y1];
            arr[i].y2 = mpp[arr[i].y2];
            open[x1].pb(i);
            close[x2].pb(i);
            ss.insert(x1), ss.insert(x2);
        }
        vector <int> X(all(ss));
        for(i = 0; i < SZ(X); i++)
        {
            if(i)
                res += segtree[1] * (X[i]-X[i-1]);
            for(j = 0; j < SZ(open[X[i]]); j++)
                update(arr[open[i][j]].y1, arr[open[i][j]].y2, 1, 1, mc, 1);
            for(j = 0; j < SZ(close[X[i]]); j++)
                update(arr[close[i][j]].y1, arr[close[i][j]].y2, 1, 1, mc, -1);
        }
    }
    return 0;
}
