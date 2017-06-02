#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <set>

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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 610
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int arr[MAX][MAX], row[MAX][MAX], col[MAX][MAX], tem[MAX];

void manacher(int *P, int *t, int n)
{
    int c = 0, r = 0, i, i_mirror;
    for(i = 1; i <= n; i++)
    {
        i_mirror = (2 * c) - i;
        P[i] = r > i? min(r - i, P[i_mirror]) : 0;
        while(i+1+P[i] <= n && t[i + 1 + P[i]] == t[i - 1 - P[i]]) P[i]++;
        if(i + P[i] > r)
        {
            c = i;
            r = i + P[i];
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, test, i, j, k, res;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);
        for(i = 2; i <= 2*n; i += 2)
            for(j = 2; j <= 2*m; j += 2)
                scanf("%d", &arr[i][j]);
        for(i = 1; i <= 2*n+1; i++)
        {
            for(j = 1; j <= 2*m+1; j++)
                tem[j] = arr[i][j];
            manacher(row[i], tem, 2*m+1);
        }
        for(j = 1; j <= 2*m+1; j++)
        {
            for(i = 1; i <= 2*n+1; i++)
                tem[i] = arr[i][j];
            manacher(col[j], tem, 2*n+1);
        }
//        for(i = 1; i <= 2*n+1; i++)
//        {
//            for(j = 1; j <= 2*m+1; j++)
//                cout << row[i][j] << ' ';
//            cout << endl;
//        }
//        cout << endl << endl;
//        for(j = 1; j <= 2*m+1; j++)
//        {
//            for(i = 1; i <= 2*n+1; i++)
//                cout << col[j][i] << ' ';
//            cout << endl;
//        }
        res = 0;
        for(i = 1; i <= 2*n+1; i++)
        {
            for(j = 1; j <= 2*m+1; j++)
            {
                int mn = min(row[i][j], col[j][i]), k=1;
                while(1)
                {
                    if(i+k>2*n+1)
                        break;
                    if(j+k>2*m+1)
                        break;
                    if(i-k<1)
                        break;
                    if(j-k<1)
                        break;
                    mn = min(mn, row[i-k][j]);
                    mn = min(mn, row[i+k][j]);
                    mn = min(mn, col[j+k][i]);
                    mn = min(mn, col[j-k][i]);
                    if(mn < k)
                        break;
                    k++;
                }
                res = max(res, k-1);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
