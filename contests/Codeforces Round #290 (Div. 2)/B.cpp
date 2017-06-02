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
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};
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

#define MAX 51
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

char grid[MAX][MAX];
int dist[MAX][MAX], n, m;

bool bfs(int r, int c)
{
    clr(dist, 63);
    dist[r][c] = 0;
    queue <int> Q;
    Q.push(r);
    Q.push(c);
    Q.push(-1);
    Q.push(-1);
    int nr, nc, i;
    while(!Q.empty())
    {
        r = Q.front();
        Q.pop();
        c = Q.front();
        Q.pop();
        int pr = Q.front();
        Q.pop();
        int pc = Q.front();
        Q.pop();
        for(i = 0; i < 4; i++)
        {
            nr = r + row[i];
            nc = c + col[i];
            if(nr > n || nr < 1 || nc > m || nc < 1 || grid[nr][nc] != grid[r][c])
                continue;
            if(nr == pr && nc == pc)
                continue;
            if(dist[nr][nc] != dist[0][0])
                return true;
            dist[nr][nc] = 0;
            Q.push(nr);
            Q.push(nc);
            Q.push(r);
            Q.push(c);
        }
    }
    return false;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            cin >> grid[i][j];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            if(bfs(i, j))
            {
                cout << "Yes";
                return 0;
            }
        }
    cout << "No";

    return 0;
}

