#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

#define F(i, n) for(i = 0; i < n; i++)

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

int g[110][110], len, ways, r, c, ans,flag;
int g1[110][110];
vector<pair<int,int> >ps;
vector<int>edge[11000],v,ansv;
void dfs(int n,int cnt)
{
    if(flag)return ;
    v.pb(c*(ps[n].first-1)+ps[n].second);
    if(g1[ps[n].first][ps[n].second]>cnt)
    {
        v.pop_back();
        return;
    }
    //cout<<cnt<<endl;
    if(cnt==len){
        flag=1;
        ansv=v;
        v.pop_back();
        ans++;
        return ;
    }
    for(int i=0;i<edge[n].size();i++){
        if(flag)
            return ;
        dfs(edge[n][i],cnt+1);

    }
    v.pop_back();
}

int main()
{
    int i, j, x, y,t=1;
    while(scanf("%d %d", &r, &c) == 2)
    {
        ans = 0;
        if(r == -1 && c == -1)
            break;
        clr(g, 0);
        while(scanf("%d %d", &x, &y) == 2 && x && y){
            ps.pb(make_pair(x,y));
            g[x][y] = 1;
        }
        sort(all(ps));
        for(i=0;i<ps.size();i++)
            for(j=0;j<ps.size();j++)
                if(i!=j&&ps[j].first>=ps[i].first&&ps[j].second>=ps[i].second)
                {
                    edge[i].pb(j);
                }
        for(i=0;i<ps.size();i++)
            for(j=0;j<ps.size();j++)
                if(i!=j&&ps[j].first<=ps[i].first&&ps[j].second<=ps[i].second)
                {
                    edge1[i].pb(j);
                }
        for(i = 1; i <= r; i++)
        {
            for(j = 1; j <= c; j++)
            {
                g1[i][j] = g[i][j] + max(g1[i - 1][j], g1[i][j - 1]);
            }
        }
        len = g1[r][c];
        flag=0;
        //cout<<len<<endl;
        for(int i=0;i<ps.size();i++)
            dfs(i,1);

        for(int i)
        for(int i=0;i<=ps.size();i++){
            edge1[i].clear();
            edge[i].clear();
        }
        ps.clear();
        cout<<"CASE#"<<t++<<": "<<len<<' '<<ans;
        for(int i=0;i<ansv.size();i++)
            cout<<' '<<ansv[i];
        cout<<endl;

    }
    return 0;
}

