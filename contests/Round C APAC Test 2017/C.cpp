#include <bits/stdc++.h>

#define in freopen("C-large.in", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 50010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

bool available[MAX];
vector <int> adj[MAX];

vector <string> split(string &s, char del)
{
    vector <string> ret;
    string tem;
    int i = 0;
    while(i < SZ(s))
    {
        if(s[i] == del)
        {
            if(!tem.empty())
                ret.pb(tem);
            tem.clear();
        }
        else
            tem += s[i];
        i++;
    }
    if(!tem.empty())
        ret.pb(tem);
    return ret;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, kase = 1, n, i;
    cin >> test;
    while(test--)
    {
        for(i = 0; i < MAX; i++)
            adj[i].clear();
        clr(available, 0);
        cin >> n;
        int mc = 0;
        map <string,int> mpp;
        vector <string> holder;
        string s;
        for(i = 0; i < n; i++)
        {
            cin >> s;
            holder = split(s, '=');
            if(mpp.find(holder[0]) == mpp.end())
                mpp[holder[0]] = ++mc;
            int u = mpp[holder[0]];
            s = holder[1];
            int j = 0;
            while(s[j] != '(')
                    j++;
            s = s.substr(j+1);
            s = s.substr(0, SZ(s)-1);
            holder = split(s, ',');
            for(auto s: holder)
            {
                if(mpp.find(s) == mpp.end())
                    mpp[s] = ++mc;
                int v = mpp[s];
                adj[u].pb(v);
            }
            if(adj[u].empty())
                available[u] = 1;
        }
        bool updated = true;
        while(updated)
        {
            updated = false;
            for(i = 1; i <= mc; i++)
            {
                if(!available[i] && !adj[i].empty())
                {
                    bool ok = true;
                    for(auto v: adj[i])
                    {
                        if(!available[v])
                        {
                            ok = false;
                            break;
                        }
                    }
                    if(ok)
                    {
                        updated = true;
                        available[i] = 1;
                    }
                }
            }
        }
        int ans = 1;
        for(i = 1; i <= mc; i++)
            ans = min(ans, (int) available[i]);
        if(ans)
            cout << "Case #" << kase++ << ": GOOD\n";
        else
            cout << "Case #" << kase++ << ": BAD\n";
    }
    return 0;
}
