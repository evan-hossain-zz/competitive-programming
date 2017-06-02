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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int arr[MAX], next_pos[MAX], cnt[MAX], n, last[MAX], block_size;

int get_block(int cur)
{
    return (cur / block_size) + (cur % block_size != 0);
}

void update(int cur)
{
    int tem = arr[cur] + cur;
    last[cur] = last[tem];
    if(get_block(tem) == get_block(cur))
    {
        next_pos[cur] = next_pos[tem];
        cnt[cur] = cnt[tem] + 1;
    }
    else
    {
        next_pos[cur] = tem;
        cnt[cur] = 1;
    }
    if(tem > n)
        last[cur] = cur, next_pos[cur] = n + 1;
}

pair<int, int> query(int cur)
{
    auto ret = mp(cur, 0);
    while(cur <= n)
    {
        ret.second += cnt[cur];
        ret.first = last[cur];
        cur = next_pos[cur];
    }
    ret.second += cnt[cur];
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int m, i, q, a, b;
    cin >> n >> m;
    block_size = sqrt(n);
    if(sqr(block_size) != n)
        block_size++;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    for(i = n; i ; i--)
        update(i);
    while(m--)
    {
        cin >> q;
        if(q)
        {
            cin >> a;
            auto res = query(a);
            cout << res.first << ' ' << res.second << "\n";
        }
        else
        {
            cin >> a >> b;
            arr[a] = b;
            int run = a % block_size;
            if(run == 0) run = block_size;
            while(run--)
                update(a), a--;
        }
    }
    return 0;
}
