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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 505
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int arr[MAX][MAX];
string s;

bool ok()
{
    int i, j;
    for(i = 1; i < SZ(s); i++)
    {
        for(j = i+1; j < SZ(s); j++)
        {
            if(s[i] == '#' || s[j] == '#')
                continue;
            if(abs(s[i]-s[j]) < 2)
            {
                if(arr[i][j] == 0)
                    return false;
            }
            else if(arr[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, i, u, v, j;
    cin >> n >> m;
    for(i = 0; i <= n; i++)
        s += "#";
    while(m--)
    {
        cin >> u >> v;
        arr[u][v] = arr[v][u] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        bool flag = 0;
        for(j = i+1; j <= n; j++)
        {
            if(arr[i][j]) continue;
            flag = 1;
            break;
        }
        if(flag == 0)
            continue;
        char cur, keep;
        if(s[i] == '#' || s[i] == 'a')
            cur = 'a', keep = 'c';
        else
            cur = 'c', keep = 'a';
        s[i] = cur;
        for(j = i+1; j <= n; j++)
        {
            if(arr[i][j]) continue;
            if(s[j] == cur)
            {
                cout << "No\n";
                return 0;
            }
            s[j] = keep;
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(s[i] != '#') continue;
        s[i] = 'a';
        if(ok())
            continue;
        s[i] = 'b';
        if(ok())
            continue;
        cout << "No";
        return 0;
    }
    if(!ok())
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    cout << s.substr(1);
    return 0;
}
