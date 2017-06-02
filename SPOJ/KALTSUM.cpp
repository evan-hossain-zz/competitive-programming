#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 110000
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL arr[MAX], cum[MAX], block;
vector <LL> precal[320][320];

LL brute(int i, int j, int k)
{
    LL ret = 0;
    bool add = 1;
    while(i+k-1 <= j)
    {
        if(add)
            ret += cum[i+k-1] - cum[i-1];
        else
            ret -= cum[i+k-1] - cum[i-1];
        i+=k;
        add = !add;
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, q, i, j, k;
    cin >> n >> q;
    for(i = 1; i <= n; i++)
        cin >> arr[i], cum[i] = cum[i-1] + arr[i];
    block = sqrt(n);
    for(i = 1; i < block; i++)
    {
        for(j = 1; j <= i; j++)
        {
            LL cur = 0;
            bool add = 1;
            precal[i][j].resize(n/i+2);
            int ti = 1;
            for(k = j; k+i-1 <= n; k+=i, ti++)
            {
                assert(ti < SZ(precal[i][j]));
                if(add)
                    cur += cum[k+i-1] - cum[k-1];
                else
                    cur -= cum[k+i-1] - cum[k-1];
                precal[i][j][ti] = cur;
                add = !add;
            }
        }
    }
    while(q--)
    {
        cin >> i >> j >> k;
        if(k >= block)
        {
            cout << brute(i, j, k) << "\n";
            continue;
        }
        int start = i%k;
        if(start == 0)
            start = k;
        bool parity = ((i - start)/k)%2;
        if(parity==0)
            cout << precal[k][start][j/k] - precal[k][start][(i-1)/k] << "\n";
        else
            cout << -(precal[k][start][j/k] - precal[k][start][(i-1)/k]) << "\n";
    }
    return 0;
}
