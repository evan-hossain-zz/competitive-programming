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

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

tuple <int, int, int> judges[MAX];
int arr[MAX], visited[201][501], kase;
LL dp[201][501];
vector <int> adj[201];

LL call(int indx, int baki)
{
    if(indx > 200 || baki == 0)
        return 0;
    int &visit = visited[indx][baki];
    LL &ret = dp[indx][baki];
    if(visit == kase) return ret;
    visit = kase;
    ret = call(indx+1, baki);
    LL taken = 0;
    for(int i = 0, j = 1; j*indx <= baki && i < SZ(adj[indx]); i++, j++)
        ret = max(ret, call(indx+1, baki - (j*indx)) + taken + adj[indx][i]), taken += adj[indx][i];
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, n, m, k, i, l, r, c, j;
    multiset <pair<int,int>> ms;
    multiset <int> values;
    cin >> test;
    while(test--)
    {
        kase++;
        ms.clear();
        values.clear();
        for(i = 1; i <= 200; i++)
            adj[i].clear();
        LL total = 0;
        cin >> n >> k >> m;
        for(i = 0; i < n; i++)
            cin >> arr[i], total += arr[i];
        for(i = 0; i < m; i++)
        {
            cin >> l >> r >> c;
            l--, r--;
            judges[i] = make_tuple(l, r, c);
        }
        sort(judges, judges+m);
        i = 0, j = 0;
        while(i < n)
        {
            while(j < m && get<0> (judges[j]) <= i)
                ms.insert(mp(get<1>(judges[j]), get<2> (judges[j]))),
                values.insert(get<2>(judges[j])), j++;
            if(arr[i] < 0 && !values.empty())
                adj[*values.begin()].pb(-arr[i]);
            while(!ms.empty())
            {
                auto pt = ms.begin();
                if((*pt).first > i)
                    break;
                auto pt2 = values.find((*pt).second);
                auto pt2end = pt2;
                pt2end++;
                values.erase(pt2, pt2end);
                auto ptend = pt;
                ptend++;
                ms.erase(pt, ptend);
            }
            i++;
        }
        for(i = 1; i <= 200; i++)
            sort(adj[i].rbegin(), adj[i].rend());
        cout << call(1, k) + total << "\n";
    }
    return 0;
}
