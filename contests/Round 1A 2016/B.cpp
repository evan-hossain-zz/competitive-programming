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

#define MAX 200
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int arr[MAX][MAX], res[MAX][MAX];

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen)
{
    for (int j = 0; j < w[i].size(); j++)
    {
        if (w[i][j] && !seen[j])
        {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen))
            {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc)
{
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);

    int ct = 0;
    for (int i = 0; i < w.size(); i++)
    {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, kase = 1, n, i, j, k;
    cin >> test;
    while(test--)
    {
        clr(arr, 0);
        clr(res, 0);
        cin >> n;
        VVI w(2*n);
        VI mr, mc;
        int cnt[3000] = {0};
        for(i = 0; i < 2*n-1; i++)
        {
            w[i].resize(2*n);
            vector <int> tem;
            for(j = 0; j < n; j++)
                cin >> arr[i][j], cnt[arr[i][j]]++;
        }
        w[i].resize(n);
        for(i = 0; i < 2*n-1; i++)
        {
            for(j = 0; j < 2*n-1; j++)
            {
                if(i == j) continue;
                for(k = 0; k < n; k++)
                    if(arr[i][k] == arr[j][k])
                        w[i][j] = 1;
            }
        }
        BipartiteMatching(w, mr, mc);
        for(i = 0; i < SZ(mr); i++)
        {
            if(mr[i] == -1) continue;
            for(j = 0; j < n; j++)
                res[mr[i]][j] = arr[i][j];
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                cnt[res[i][j]] -= 2;
        }
        cout << "Case #" << kase++ << ":";
        int c = 0;
        for(i = 0; i < 3000; i++)
            if(abs(cnt[i])%2)
                cout << ' ' << i, c++;
        assert(c == n);
        cout << "\n";
    }
    return 0;
}
/*
2
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3
3
1 2 3
2 3 5
3 4 6
2 3 4
1 2 3
*/
