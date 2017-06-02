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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL dp[1<<10][1<<10], mod = 1e9+7, kase, n, save[1<<10][1<<10], cnt[1<<10];

LL call(int pmask, int mask)
{
    if(pmask == 1<<10)
        return mask == 0;
    LL &ret = dp[pmask][mask];
    if(ret != -1) return ret;
    if(cnt[pmask] == 0)
        return ret = call(pmask+1, mask);
    ret = call(pmask+1, mask) * bigmod(2, cnt[pmask]-1, mod);
    ret %= mod;
    ret += call(pmask+1, save[pmask][mask]) * bigmod(2, cnt[pmask]-1, mod);
    ret %= mod;
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, i, j, tem, k;
    char ch;
    for(i = 0; i < (1<<10); i++)
    {
        for(j = 0; j < (1<<10); j++)
        {
            for(k = 0; k < 10; k++)
            {
                if((j & (1<<k)) && (!(i & (1<<k))))
                    save[i][j] |= 1 << k;
                else if((!(j & (1<<k))) && (i & (1<<k)))
                    save[i][j] |= 1 << k;
            }
        }
    }
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        clr(dp, -1);
        clr(cnt, 0);
        int have = 0;
        for(j = 0; j < 10; j++)
        {
            scanf(" %c", &ch);
            if(ch == 'w')
                have |= 1<<j;
        }
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            tem = 0;
            for(j = 0; j < 10; j++)
            {
                scanf(" %c", &ch);
                if(ch == '+')
                    tem |= 1<<j;
            }
            cnt[tem]++;
        }
        printf("%lld\n", call(0, have));
    }
    return 0;
}
