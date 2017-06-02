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

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

char grid[1110][1110];
int res[1110][1110];
int seen[1110][1110], n, m;

int get(int i, int j)
{
    queue <int> Q;
    Q.push(i);
    Q.push(j);
    int ni, nj, p, ret = 0;
    while(!Q.empty())
    {
        i = Q.front();
        Q.pop();
        j = Q.front();
        Q.pop();
        for(p = 0; p < 4; p++)
        {
            ni = i + row[p];
            nj = j + col[p];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m)
            {
                if(grid[ni][nj] == '*')
                    ret++;
                else if(!seen[ni][nj])
                {
                    Q.push(ni);
                    Q.push(nj);
                    seen[ni][nj] = 1;
                }
            }
        }
    }
    return ret;
}
void fill(int i, int j, int r)
{
    queue <int> Q;
    Q.push(i);
    Q.push(j);
    res[i][j] = r;
    int ni, nj, p;
    while(!Q.empty())
    {
        i = Q.front();
        Q.pop();
        j = Q.front();
        Q.pop();
        for(p = 0; p < 4; p++)
        {
            ni = i + row[p];
            nj = j + col[p];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && seen[ni][nj] == 1)
            {
                Q.push(ni);
                Q.push(nj);
                seen[ni][nj] = 2;
                res[ni][nj] = r;
            }
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int k, i, j, p, ni, nj;
    cin >> n >> m >> k;
    for(i = 0; i < n; i++)
        cin >> grid[i];
    queue <int> Q;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == '*' || seen[i][j]) continue;
            seen[i][j] = 1;
            fill(i, j, get(i, j));
        }
    while(k--)
    {
        cin >> i >> j;
        cout << res[i-1][j-1] << "\n";
    }
    return 0;
}
