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

#define MAX 1010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

char grid[MAX][MAX];
queue <int> Q;
int par[5], color[MAX][MAX], dist[MAX][MAX], n, m, cost[5][5];

int root(int v)
{
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}
void merge(int x,int y)     //  x and y are some tools (vertices)
{
    x = root(x), y = root(y);
    if(par[y] < par[x]) // balancing the height of the tree
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

void dfs(int r, int c, char ch)
{
    color[r][c] = 1;
    Q.push(r);
    Q.push(c);
    for(int i = 0; i < 4; i++)
    {
        int nr = row[i] + r;
        int nc = col[i] + c;
        if(nr < 0 || nr == n || nc < 0 || nc == m || grid[nr][nc] == '.' || grid[nr][nc] == '#' || color[nr][nc])
            continue;
        int a = grid[nr][nc]-'0';
        int b = ch-'0';
        if(root(a) != root(b))
            merge(a, b);
        dfs(nr, nc, ch);
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> grid[i][j];
    clr(par, -1);
    clr(cost, 63);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == '.' || grid[i][j] == '#' || color[i][j])
                continue;
            dfs(i, j, grid[i][j]);
        }
    }
    for(i = 1; i < 4; i++)
        for(j = 1; j < 4; j++)
            if(root(i) == root(j))
                cost[i][j] = 0;
    int r, c, nr, nc;
    for(i = 2; i < 4; i++)
    {
        if(root(1) != root(i))
            break;
    }
    if(i == 4)
    {
        cout << 0;
        return 0;
    }
    while(!Q.empty())
    {
        r = Q.front();
        Q.pop();
        c = Q.front();
        Q.pop();
        for(i = 0; i < 4; i++)
        {
            nr = row[i] + r;
            nc = col[i] + c;
            if(nr < 0 || nr == n || nc < 0|| nc == m || grid[nr][nc] == '#')
                continue;
            if(grid[nr][nc] == '.')
            {
                color[nr][nc] = 1;
                dist[nr][nc] = dist[r][c] + 1;
                grid[nr][nc] = grid[r][c];
                Q.push(nr);
                Q.push(nc);
                continue;
            }
            int a = grid[r][c]-'0';
            int b = grid[nr][nc]-'0';
            if(root(a) == root(b))
                continue;
            merge(a, b);
            cost[a][b] = dist[r][c] + dist[nr][nc];
            bool ok = true;
            for(int p = 2; p < 4; p++)
                if(root(1) != root(p))
                    ok = false;
            if(!ok) continue;
            int res = 0;
            for(i = 1; i < 4; i++)
                for(j = 1; j < 4; j++)
                    if(cost[i][j] < cost[0][0])
                        res += cost[i][j];
            cout << res;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
