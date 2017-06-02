#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 30)
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

#define MAX 310
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

pair<int,int> arr[MAX];

bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second < b.second;
}
int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, n, i, j, k;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second;
        if(n < 3)
        {
            cout << "0\n";
            continue;
        }
        sort(arr, arr+n);
        LL res = 1LL<<60;
        vector <int> tem;
        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                tem.clear();
                for(k = 0; k < n; k++)
                {
                    if(arr[k].first >= arr[i].first && arr[k].first <= arr[j].first)
                        tem.pb(arr[k].second);
                }
                sort(all(tem));
                for(int l = 0, r = -1, got = 0; l < SZ(tem);)
                {
                    while(got*2 < n && r+1 < SZ(tem))
                    {
                        ++r;
                        got++;
                    }
                    bool ins = 1;
                    while((got-1)*2>n)
                    {
                        l++;
                        ins = 0;
                    }
                    if(got*2 > n)
                    {
                        res = min(res, 1LL*(tem[r]-tem[l])*(arr[j].first-arr[i].first));
                    }
                    if(ins)
                        got--, l++;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
