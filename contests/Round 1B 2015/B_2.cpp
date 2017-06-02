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
int col[4] = {1, -1, -1, 1};
int row[4] = {1, 1, -1, -1};
int col2[4] = {1, 0, -1, 0};
int row2[4] = {0, 1, 0, -1};
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

#define MAX 17
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int color[MAX][MAX], R, C, baki;

void bfs()
{
    if(baki = 0)
        return;
    queue <int> Q;
    Q.push(1);
    Q.push(1);
    color[1][1] = 1;
    baki--;
    int r, c, nr, nc, i;
    while(!Q.empty() && baki)
    {
        r = Q.front();
        Q.pop();
        c = Q.front();
        Q.pop();
        for(i = 0; i < 4; i++)
        {
            nr = r+row[i];
            nc = c+col[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || color[nr][nc] == 1) continue;
            color[nr][nc] = 1;
            Q.push(nr);
            Q.push(nc);
            baki--;
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, i, j, k, kase = 1;
    cin >> test;
    while(test--)
    {
        clr(color, 0);
        int res = 0;
        cin >> R >> C >> baki;
        bfs();
        if(baki)
        {
            for(i = 0;baki && i < C; i++)
            {
                if(color[0][i] == 0)
                    color[0][i] = 1, baki--;
            }
            for(i = 0;baki && i < C; i++)
            {
                if(color[R-1][i] == 0)
                    color[R-1][i] = 1, baki--;
            }
            for(i = 0;baki && i < R; i++)
            {
                if(color[i][0] == 0)
                    color[i][0] = 1, baki--;
            }
            for(i = 0;baki && i < R; i++)
            {
                if(color[C-1][0] == 0)
                    color[C-1][0] = 1, baki--;
            }
            for(i = 0; baki && i < R; i++)
                for(j = 0; baki && j < C; j++)
                    if(color[i][j] == 0)
                        color[i][j] = 1, baki--;
        }
        for(i = 1; i < C; i++)
            if(color[0][i] & color[0][i-1])
                res++;
        for(i = 1; i < C; i++)
            if(color[R-1][i] & color[R-1][i-1])
                res++;
        for(i = 1; i < R; i++)
            if(color[i][0] & color[i-1][0])
                res++;
        for(i = 1; i < R; i++)
            if(color[i][C-1] & color[i-1][C-1])
                res++;
        for(i = 1; i < R-1; i++)
        {
            for(j = 1; j < C-1; j++)
            {
                for(k = 0; k < 4; k++)
                {
                    int nr = i+row2[k];
                    int nc = j+col2[k];
                    if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                    res += color[nr][nc];
                }
            }
        }
        cout << "Case #" << kase++ << ": " << res << "\n";
    }
    return 0;
}



