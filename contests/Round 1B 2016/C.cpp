#include <bits/stdc++.h>

#define in freopen("C-small-attempt0.in", "r", stdin);
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

#define MAX 110
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

pair <string, string> inp[MAX];
pair <int, int> arr[MAX];

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, n, kase = 1, i, j;
    cin >> test;
    while(test--)
    {
        map <string,int> mpp;
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> inp[i].first >> inp[i].second, mpp[inp[i].first], mpp[inp[i].second];
        i = 0;
        for(auto &x: mpp)
            x.second = i++;
        for(i = 0; i < n; i++)
            arr[i] = mp(mpp[inp[i].first], mpp[inp[i].second]);
        int res = 0;
        for(i = 1; i < (1<<n); i++)
        {
            set <int> f, s;
            for(j = 0; j < n; j++)
            {
                if(i & (1<<j))
                    f.insert(arr[j].first), s.insert(arr[j].second);
            }
            int cnt = 0;
            for(j = 0; j < n; j++)
            {
                if(i & (1<<j))
                    continue;
                if(f.find(arr[j].first) != f.end() && s.find(arr[j].second) != s.end())
                    cnt++;
            }
            res = max(res, cnt);
        }
        cout << "Case #" << kase++ << ": " << res << "\n";
        cerr << "Case #" << kase-1 << ": " << res << "\n";
    }
    return 0;
}
