#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define VI vector <int>
#define all(v) v.begin(), v.end()
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(i, n) for(i = 0; i < n; i++)

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

#define SZ 100010
using namespace std;

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
template <class T> T GCD(T a, T b) {if(b == 0) return a; return GCD(b, a % b);}
template <class T> T LCM(T a, T b) {return (a * b) / GCD(a, b);}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;}
//LL Pow(LL B,LL P){  LL R = 1; while(P > 0)  {if(P % 2 == 1) R = (R*B);P /= 2;B = (B*B); } return R;}
//LL bigmod(LL n,LL p){ if(p == 0) return 1; LL a = bigmod(n, p / 2) % mod; if(p % 2 == 1) return (a*a*n) % mod; return (a*a) % mod;}

int main()
{
    _
    int test, i, j, taken[110], n, m, bottles, v;
    LL tot;
    vector <int> volumes[110];
    vector <int> visits;
    cin >> test;
    while(test--)
    {
        cin >> n >> m;
        clr(taken, 0);
        for(i = 0; i < 105; i++) volumes[i].clear();
        visits.clear();
        tot = 0;
        FOR(i, m)
        {
            cin >> j;
            visits.pb(j);
        }
        FOR(i, n)
        {
            cin >> bottles;
            FOR(j, bottles)
            {
                cin >> v;
                volumes[i].pb(v);
            }
            sort(volumes[i].rbegin(), volumes[i].rend());
        }
        FOR(i, m)
        {
            int cur = visits[i];
            if(taken[cur] < volumes[cur].size())
                tot += volumes[cur][taken[cur]], taken[cur]++;
        }
        cout << tot << endl;
    }
    return 0;
}


