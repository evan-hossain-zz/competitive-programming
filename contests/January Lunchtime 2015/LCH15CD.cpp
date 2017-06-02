#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1LL << 58)
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

#define MAX 50000010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL more_bit[13], more;

LL dp[MAX], visited[MAX], cur, n;

LL get_bit(LL mask , LL pos)
{
    return (mask / more_bit[pos]) % more;
}

LL set_bit(LL mask, LL pos , LL bit)
{
    LL tmp = (mask / more_bit[pos]) % more;
    mask -= tmp * more_bit[pos];
    mask += bit * more_bit[pos];
    return mask;
}

void init(LL n)
{
    more_bit[0] = more;
    for(LL i = 1; i <= n; i++) more_bit[i] = more * more_bit[i - 1];
}

LL get_cost(LL mask)
{
    LL i, ret = 0, xorval = 0, sum = 0, bit;
    for(i = 0; i < n; i++)
    {
        bit = get_bit(mask, i);
        xorval ^= bit;
        sum += bit;
    }
    return xorval * sum;
}

LL call(LL mask)
{
    if(mask == more_bit[n] - more)
        return 0;
    LL i, &ret = dp[mask], bit, tem_mask, cost;
    if(visited[mask] == cur) return ret;
    visited[mask] = cur;
    ret = infinity;
    for(i = 0; i < n; i++)
    {
        tem_mask = mask;
        bit = get_bit(tem_mask, i);
        if(bit + 1 < more)
        {
            tem_mask = set_bit(tem_mask, i, bit+1);
            ret = min(ret, call(tem_mask) + get_cost(tem_mask));
        }
    }
    return ret;
}

LL call1(LL indx)
{
    if(indx == more)
        return 0;
    return call1(indx+1) + (indx * indx);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int test;
    cin >> test;
    while(test--)
    {
        ++cur;
        cin >> n >> more;
        if(n == 1)
        {
            cout << call1(0) << "\n";
            continue;
        }
        init(n);
        cout << call(0) << "\n";
    }
    return 0;
}

