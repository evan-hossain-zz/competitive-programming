#include <bits/stdc++.h>

#define in freopen("B-large.in", "r", stdin);
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 55
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int grid[MAX][MAX], color[MAX][MAX], n, m;

void go(int r, int c)
{
    clr(color, 0);
    queue <int> Q;
    Q.push(r);
    Q.push(c);
    color[r][c] = 1;
    int nr, nc, i;
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
            if(nr < 1 || nr > n || nc < 1 || nc > m || color[nr][nc] || grid[nr][nc] > grid[r][c])
                continue;
            color[nr][nc] = 1;
            Q.push(nr);
            Q.push(nc);
        }
    }
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int res, i, j, k, l, p, test, kase = 1;
    cin >> test;
    while(test--)
    {
        res = 0;
        clr(grid, 0);
        cin >> n >> m;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                cin >> grid[i][j];
        int pre = 0;
        int cnt = 0;
        while(1)
        {
            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= m; j++)
                {
                    go(i, j);
                    int cur = infinity;
                    for(k = 1; k <= n; k++)
                    {
                        for(l = 1; l <= m; l++)
                        {
                            if(!color[k][l]) continue;
                            for(p = 0; p < 4; p++)
                            {
                                int nr = row[p] + k;
                                int nc = col[p] + l;
                                if(!color[nr][nc])
                                    cur = min(cur, grid[nr][nc]);
                            }
                        }
                    }
                    if(cur <= grid[i][j] || cur == infinity) continue;
                    for(k = 1; k <= n; k++)
                        for(l = 1; l <= m; l++)
                            if(color[k][l])
                            {
                                res += cur - grid[k][l];
                                grid[k][l] = cur;
                            }
                }
            }
//            cout << endl << endl;
//            for(i = 1; i <= n; i++)
//            {
//                for(j = 1; j <= m; j++)
//                    cerr << grid[i][j] << ' ';
//                cerr << endl;
//            }
            if(res == pre)
                break;
            pre = res;
            cnt++;
        }
        cout << "Case #" << kase++ << ": " << res << "\n";
        cerr << "Case #" << kase-1 << ": " << res << ' ' << cnt << "\n";
    }
    return 0;
}
/*
10 10
689 724 245 182 98 177 514 185 997 377
538 210 901 27 250 840 269 538 373 49
920 102 543 136 337 38 13 373 367 221
714 513 511 165 793 669 764 903 691 451
584 164 225 710 851 986 618 954 339 176
641 215 295 971 932 712 122 337 900 463
495 770 69 725 214 329 942 195 312 775
829 509 117 977 300 784 186 274 433 328
203 830 714 57 164 169 427 355 229 512
603 266 246 660 471 828 914 12 182 812
*/
