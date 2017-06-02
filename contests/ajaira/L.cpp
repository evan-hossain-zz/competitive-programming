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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int n, m, dp[8][8][6600][4];
int more_bit[10];
int get_bit(int mask , int pos)
{
    return (mask / more_bit[pos]) % 3;
}
int set_bit(int mask, int pos , int bit)
{
    int tmp = (mask / more_bit[pos]) % 3;
    mask -= tmp * more_bit[pos];
    mask += bit * more_bit[pos];
    return mask;
}
void init(void)
{
    more_bit[0] = 1;
    for(int i = 1; i < 10; i++) more_bit[i] = 3 * more_bit[i - 1];
}
int arr[8][8];

bool ok(int mask, int r, int c, int val)
{
    bool ret = false;
    if(c == 0)
        ret |= (get_bit(mask, c) != 3-val);
    else
        ret |= (get_bit(mask, c) != 3-val) || (get_bit(mask, c-1) == val);
    if(c < m-1 && arr[r][c+1] != 3-val)
        return true;
    if(r < n-1 && arr[r+1][c] != 3-val)
        return true;
    return ret;
}

int call(int r, int c, int mask, int last)
{
    if(r == n)
        return 1;
    if(c == m)
        return call(r+1, 0, mask, 0);
    int &ret = dp[r][c][mask][last], i, j;
    if(ret != -1) return ret;
    ret = 0;
    if(c == 0)
    {
        if(arr[r][c] != 2 && ok(mask, r, c, 1))
            ret += call(r, c+1, set_bit(mask, c, 1), get_bit(mask, c));
        if(arr[r][c] != 1 && ok(mask, r, c, 2))
            ret += call(r, c+1, set_bit(mask, c, 2), get_bit(mask, c));
        return ret;
    }
    for(i = 1; i < 3; i++)
    {
        if(get_bit(mask, c-1) == last && i == last && get_bit(mask, c) == i)
                continue;
        if((arr[r][c] != 3-i) && ok(mask, r, c, i))
            ret += call(r, c+1, set_bit(mask, c, i), get_bit(mask, c));
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    init();
    int test, i, j;
    cin >> test;
    string s;
    while(test--)
    {
        clr(arr, 0);
        cin >> n >> m;
        for(i = 0; i < n; i++)
        {
            cin >> s;
            for(j = 0; j < m; j++)
            {
                if(s[j] == 'o')
                    arr[i][j] = 1;
                else if(s[j] == '#')
                    arr[i][j] = 2;
            }
        }
        clr(dp, -1);
        cout << call(0, 0, 0, 0) << "\n";
    }
    return 0;
}
