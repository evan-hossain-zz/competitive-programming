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
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};
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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 22
/*************************************************HABIJABI ENDS HERE******************************************************/

int wall[MAX][MAX][MAX], n, m, t, dist[MAX][MAX][MAX], visited[MAX][MAX][MAX], mn;

void bfs(int r, int c)
{
    queue <int> q;
    q.push(r);
    q.push(c);
    q.push(0);
    dist[0][r][c] = 0;
    visited[0][r][c] = 1;
    int i, nr, nc, s;
    while(!q.empty())
    {
        r = q.front();
        q.pop();
        c = q.front();
        q.pop();
        s = q.front();
        q.pop();
        for(i = 1; i <= t; i++)
        {
            if(!visited[i][r][c] && !wall[i][r][c])
            {
                visited[i][r][c] = 1;
                    if(i > s)
                        dist[i][r][c] = dist[s][r][c] + s - i;
                    else
                        dist[i][r][c] = dist[s][r][c] + 10 - s + i;
                dist[i][r][c] = dist[s][r][c] + i;
                q.push(r);
                q.push(c);
                q.push(i);
            }
        }
        for(i = 0; i < 4; i++)
        {
            nr = r + row[i];
            nc = c + col[i];
            if(nr < 0 || nr == n || nc < 0 || nc == m)
                continue;
            int sec = (s % t) + 1;

            if(wall[sec][nr][nc] || visited[sec][nr][nc])
                continue;
            dist[sec][nr][nc] = dist[s][r][c] + 1;
            visited[sec][nr][nc] = 1;
            q.push(nr);
            q.push(nc);
            q.push(sec);
        }
    }
    mn = infinity;
    for(i = 1; i <= t; i++)
    {
        if(dist[i][n - 1][m - 1])
            mn = min(dist[i][n - 1][m - 1], mn);
    }
}

int main()
{
    int i, j, w, kase = 1;
    string s;
    while(scanf("%d %d %d", &n, &m, &t) == 3 && (n | m | t))
    {
        clr(dist, 0);
        clr(wall, 0);
        clr(visited, 0);
        for(w = 1; w <= t; w++)
        {
            for(i = 0; i < n; i++)
            {
                cin >> s;
                for(j = 0; j < m; j++)
                    wall[w][i][j] = s[j] - '0';
            }
        }
        if(n == 1 && m == 1)
        {
            printf("Case %d: Luke and Leia can escape in 0 steps.\n", kase++);
            continue;
        }
        bfs(0, 0);
        if(mn != infinity)
            printf("Case %d: Luke and Leia can escape in %d steps.\n", kase++, mn);
        else
            printf("Case %d: Luke and Leia cannot escape.\n", kase++);
    }
    return 0;
}

