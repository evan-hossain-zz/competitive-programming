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
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast_input_output ios_base::sync_with_stdio(0);cin.tie(0);
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

struct point{double x, y;};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 110
/*************************************************HABIJABI ENDS HERE******************************************************/

int d[MAX][MAX], inq[MAX][MAX];
struct edge
{
    int city, start, arr;
    edge(){};
    edge(int a, int b, int c)
    {
        city = a;
        start = b;
        arr = c;
    }
};

vector <edge> e[MAX];

int bfs(int start, int des)
{
    clr(inq, 0);
    queue <edge> q;
    q.push(edge(start, 18, 18));
    d[start][18] = 0;
    inq[start][18] = 1;
    edge u, v;
    int i, ucost, vcost, ret = infinity;
    while(!q.empty())
    {
        u = q.front();
        if(u.city == des)
            ret = min(ret, d[u.city][u.arr]);
        q.pop();
        inq[u.city][u.arr] = 0;
        ucost = d[u.city][u.arr];
        for(i = 0; i < SZ(e[u.city]); i++)
        {
            v.city = e[u.city][i].city, v.start = e[u.city][i].start, v.arr = e[u.city][i].arr;
            vcost = ucost;
            if(v.start < u.arr)
                vcost++;
            if(d[v.city][v.arr] > vcost)
            {
                d[v.city][v.arr] = vcost;
                if(inq[v.city][v.arr] == 0)
                {
                    inq[v.city][v.arr] = 1;
                    q.push(v);
                }
            }
        }
    }
    return ret;
}

int main()
{
    string a, b;
    int j, start, arrive, i, test, m, mc, kase = 1;
    char stra[MAX], strb[MAX];
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &m);
        map <string, int> mp;
        mc = 0;
        for(i = 0; i < MAX; i++)
        {
            e[i].clear();
            for(j = 0; j < MAX; j++)
                d[i][j] = infinity;
        }
        while(m--)
        {
            scanf("%s %s %d %d", stra, strb, &start, &arrive);
            a = stra;
            b = strb;
            if(mp.find(a) == mp.end())
                mp[a] = mc++;
            if(mp.find(b) == mp.end())
                mp[b] = mc++;
            if(start <= 6) start += 24;
            if(arrive > 12) continue;
            arrive += start;
            if(start < 18 || arrive > 30) continue;
            e[mp[a]].pb(edge(mp[b], start, arrive));
        }
        scanf("%s %s", stra, strb);
        a = stra, b = strb;
        printf("Test Case %d.\n", kase++);
        if(mp.find(a) == mp.end() || mp.find(b) == mp.end())
        {
            printf("There is no route Vladimir can take.\n");
            continue;
        }
        arrive = bfs(mp[a], mp[b]);
        if(arrive >= infinity)
            printf("There is no route Vladimir can take.\n");
        else
            printf("Vladimir needs %d litre(s) of blood.\n", arrive);
    }
    return 0;
}
