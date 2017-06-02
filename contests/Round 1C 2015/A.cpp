#include <bits/stdc++.h>

#define in freopen("A-small-attempt3.in", "r", stdin);
#define out freopen("output2.txt", "w", stdout);
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

#define MAX 30
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int cur[MAX], C, W, tot;

int get(int low, int high)
{
    if(low > high || (high-low+1) < W) return 0;
    int mid, ret = 1;
    mid = (low+high) / 2;
    if(cur[mid] == 1)
    {
        tot++;
        int tem;
        tem = mid+1;
        while(tem <= high && tot < W)
        {
            ret++;
            if(cur[tem]) tot++;
            else break;
            tem++;
        }
        tem = mid-1;
        while(tem >= low && tot < W)
        {
            ret++;
            if(cur[tem]) tot++;
            else break;
            tem--;
        }
        assert(tot == W);
        return ret;
    }
    ret += get(mid+1, high);
    ret += get(low, mid-1);
    return ret;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int R, test, kase = 1;
    cin >> test;
    while(test--)
    {
        cin >> R >> C >> W;
        int res = 0;
        for(int i = 1; i <= R - 1; i++)
        {
            clr(cur, 0);
            res += get(1, C);
        }
        int tem = 0;
        for(int i = 1; i + W - 1 <= C; i++)
        {
            clr(cur, 0);
            int cnt = 0;
            while(cnt < W)
                cur[i+cnt] = 1, cnt++;
            tot = 0;
            tem = max(tem, get(1, C));
        }
        cout << "Case #" << kase++ << ": " << res + tem << "\n";
    }
    return 0;
}

