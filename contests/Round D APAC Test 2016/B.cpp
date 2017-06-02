#include <bits/stdc++.h>

#define in freopen("B-large.in", "r", stdin);
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

#define MAX 10010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int P[MAX], H[MAX], V[MAX];

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, kase = 1, i, j, n, m, q;
    cin >> test;
    while(test--)
    {
        cin >> n >> m >> q;
        for(i = 0; i < m; i++)
            cin >> V[i];
        for(i = 0; i < n; i++)
            cin >> P[i] >> H[i];
        int low = 0, high = 1e5, mid, res = -1;
        while(low <= high)
        {
            mid = (low+high) / 2;
            int need = 0;
            for(i = 0; i < n; i++)
            {
                if(P[i] == 0) continue;
                int tem = infinity;
                for(j = 0; j < m; j++)
                {
                    if(P[i] < 0 && V[j] < 0) continue;
                    if(P[i] > 0 && V[j] > 0) continue;
                    if(V[j] == 0) continue;
                    int timeNeed = (abs(P[i]) / abs(V[j])) + (abs(P[i]) % abs(V[j]) != 0);
                    if(timeNeed <= mid)
                        tem = min(tem, abs(H[i]-j));
                }
                if(tem >= infinity)
                {
                    need = infinity;
                    break;
                }
                need += tem;
            }
            if(i == n && need <= q)
                res = mid, high = mid-1;
            else
                low = mid+1;
        }
        if(res == -1)
            cout << "Case #" << kase++ << ": IMPOSSIBLE\n";
        else
            cout << "Case #" << kase++ << ": " << res << "\n";
    }
    return 0;
}
