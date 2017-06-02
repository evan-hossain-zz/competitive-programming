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

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

set <string> ss;

void rec(string arr[2])
{
    string tem = arr[0] + arr[1];
    if(ss.find(tem) != ss.end())
        return;
    ss.insert(tem);
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(arr[i][j] != 'X')
                continue;
            for(int k = 0; k < 4; k++)
            {
                int nr = row[k] + i;
                int nc = col[k] + j;
                if(nr < 0 || nr == 2 || nc < 0 || nc == 2) continue;
                swap(arr[i][j], arr[nr][nc]);
                rec(arr);
                swap(arr[i][j], arr[nr][nc]);
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
    string a[2], b[2];
    for(int i = 0; i < 2; i++)
        cin >> a[i];
    for(int i = 0; i < 2; i++)
        cin >> b[i];
    rec(b);
    if(ss.find(a[0] + a[1]) == ss.end())
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
