#include <bits/stdc++.h>

#define in freopen("C-small-attempt2.in", "r", stdin);
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

#define MAX 20
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int adj[MAX][MAX], n, dp[200000000];

int more_bit[17];
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
    for(int i = 1; i < 17; i++) more_bit[i] = 3 * more_bit[i - 1];
}

int get(int mask)
{
    int one = 0, i;
    for(i = 0; i < n; i++)
        one += get_bit(mask, i) == 1;
    int tem = n, ret = 1;
    while(n-one <= tem/2)
    {
        tem /= 2;
        ret++;
    }
    return ret;
}

int call(int mask)
{
    int arr[3] = {0}, i;
    for(i = 0; i < n; i++)
    {
        arr[get_bit(mask, i)]++;
//        cout << get_bit(mask, i) << ' ';
    }
//    cout << endl;
    if(arr[2] == 1 && arr[1] == n-1)
        return 1;
    int &ret = dp[mask];
    if(ret != -1) return ret;
    int nmask = mask;
    if(arr[0] == 0)
    {
//        cout << "new round" << endl;
        for(i = 0; i < n; i++)
        {
            if(get_bit(mask, i) == 2)
                nmask = set_bit(nmask, i, 0);
//            cout << get_bit(nmask, i) << ' ';
        }
//        cout << endl;
    }
    ret = 0;
    int rounds = get(nmask);
    for(i = 0; i < n; i++)
    {
        if(get_bit(nmask, i) != 0) continue;
        for(int j = i+1; j < n; j++)
        {
            if(get_bit(nmask, j) != 0) continue;
            if(adj[i][j] <= rounds || adj[j][i] <= rounds) continue;
            int tem = nmask;
            tem = set_bit(tem, i, 2);
            tem = set_bit(tem, j, 1);
            ret = max(ret, call(tem));
            tem = nmask;
            tem = set_bit(tem, i, 1);
            tem = set_bit(tem, j, 2);
            ret = max(ret, call(tem));
            if(rounds > 1)
                break;
        }
    }
    return ret;
}

int main()
{
    in;
    out;
    init();
    int test, kase = 1, m, x, e, k, b;
    cin >> test;
    while(test--)
    {
        clr(adj, 63);
        cin >> n >> m;
        n = 1 << n;
        while(m--)
        {
            cin >> e >> k >> b;
            e--;
            while(b--)
            {
                cin >> x;
                x--;
                adj[e][x] = k;
            }
        }
        clr(dp, -1);
        if(call(0))
            cout << "Case #" << kase++ << ": " << "YES" << "\n";
        else
            cout << "Case #" << kase++ << ": " << "NO" << "\n";
    }
    return 0;
}

