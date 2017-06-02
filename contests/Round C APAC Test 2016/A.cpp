#include <bits/stdc++.h>

#define in freopen("A-large.in", "r", stdin);
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

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

vector <int> adj[MAX];

int arr[MAX];

bool comp(const pair<LL, string> &a, const pair<LL,string> &b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
        in;
        out;
    map <string, int> mpp;
    map <int, string> ulta;
    int kase = 1, p, i, n, test, j, m;
    cin >> test;
    while(test--)
    {
        mpp.clear();
        ulta.clear();
        cin >> p;
        for(i = 1; i <= p; i++)
            cin >> arr[i];
        int mc = 0;
        cin >> n;
        for(i = 0; i < n; i++)
        {
            LL x;
            cin >> x;
            for(j = 1; j <= p; j++)
            {
                string s;
                cin >> s;
                if(mpp.find(s) == mpp.end())
                    mpp[s] = ++mc, ulta[mc] = s;
                adj[mpp[s]].pb(x*arr[j]);
            }
        }
        cin >> m;
        vector <pair<LL,string>> res;
        for(i = 1; i <= mc; i++)
        {
            LL sum = 0;
            sort(adj[i].rbegin(), adj[i].rend());
            for(j = 0; j < min(SZ(adj[i]), m); j++)
                sum += adj[i][j];
            res.pb(mp(sum, ulta[i]));
            adj[i].clear();
        }
        sort(all(res), comp);
        int r = 1;
        cout << "Case #" << kase++ << ":\n";
        for(i = 0; i < SZ(res); i++)
        {
            if(i)
            {
                if(res[i] < res[i-1])
                    r = i+1;
            }
            cout << r << ": " << res[i].second << "\n";
        }
    }
    return 0;
}
