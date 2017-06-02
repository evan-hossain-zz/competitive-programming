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
#include <assert.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

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

#define MAX 200010
/*************************************************HABIJABI ENDS HERE******************************************************/

struct info
{
    int city, leave, arrive, cost;
    info(){};
    info(int _city, int _leave, int _arrive, int _cost)
    {
        city = _city;
        leave = _leave;
        arrive = _arrive;
        cost = _cost;
    }
};

vector <info> adj[MAX];
map <string, int> mpp;
int n;

void init(int arr[][1081], int source)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 1081; j++)
            arr[i][j] = infinity;
    for(int i = 0; i < 1081; i++)
        arr[source][i] = 0;
}

int get_distance(int source, int dest)
{
    queue <int> q;
    q.push(source);
    q.push(480);
    int dist[n][1081];
    init(dist, source);
    int ucity, utime, vcity, varr_time, vlv_time, udist, i;
    while(!q.empty())
    {
        ucity = q.front();
        q.pop();
        utime = q.front();
        q.pop();
        udist = dist[ucity][utime];
        for(i = 0; i < SZ(adj[ucity]); i++)
        {
            vcity = adj[ucity][i].city;
            vlv_time = adj[ucity][i].leave;
            if(vlv_time < utime) continue;
            varr_time = adj[ucity][i].arrive;
            dist[vcity][varr_time] = min(dist[vcity][varr_time], udist + adj[ucity][i].cost);
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int m, i, lh, lm, ah, am, cost;
    char strl[20], stra[20];
    while(scanf("%d", &m) == 1 && m)
    {
        mpp.clear();
        n = 1;
        while(m--)
        {
            scanf(" %s %d:%d %s %d:%d %d", strl, &lh, &lm, stra, &ah, &am, &cost);
            cout << strl << ' ' << stra << ' ' << lh << ":" << lm << ' ' << ah << ":" << am << endl;
            lh *= 60;
            lh += lm;
            ah *= 60;
            am += am;
            if(lh < 480 || ah > 1080) continue;
            if(mpp.find(strl) == mpp.end())
                mpp[strl] = n++;
            if(mpp.find(stra) == mpp.end())
                mpp[stra] = n++;
            adj[mpp[strl]].pb(info(mpp[stra], lh, ah, cost));
        }
        for(i = 1; i < n; i++)
        {
            // let i be meeting point
            int distenc_for_ken = get_distance(mpp["Hakodate"], i);
            int distenc_for_keiko = get_distance(mpp["Tokyo"], i);
        }
    }
    return 0;
}



