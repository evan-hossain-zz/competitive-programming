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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL n, k, s, arr[MAX], F[20];

map <LL,LL> mpp1[26], mpp2[26];

LL half, other;

LL more_bit[14];
LL get_bit(LL mask , LL pos)
{
    return (mask / more_bit[pos]) % 3;
}

LL set_bit(LL mask, LL pos , LL bit)
{
    LL tmp = (mask / more_bit[pos]) % 3;
    mask -= tmp * more_bit[pos];
    mask += bit * more_bit[pos];
    return mask;
}
void init(void)
{
    more_bit[0] = 1;
    for(LL i = 1; i < 14; i++) more_bit[i] = 3 * more_bit[i - 1];
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    init();
    F[1] = 1;
    for(n = 2; n < 19; n++)
        F[n] = F[n-1] * n;
    cin >> n >> k >> s;
    LL i, j;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    half = n/2;
    other = n - half;
    LL P[14];
    P[0] = 1;
    for(i = 1; i <= 13; i++)
        P[i] = P[i-1]*3;
    for(i = 0; i < P[half]; i++)
    {
        LL tem = 0, taken = 0;
        bool over = 0;
        for(j = 0; j < half; j++)
        {
            if(tem > s)
            {
                over = 1;
                break;
            }
            if(get_bit(i, j) == 0)
                continue;
            if(get_bit(i, j) == 1)
                tem += arr[j];
            else
            {
                taken++;
                if(arr[j] > 18)
                    over = 1;
                else
                    tem += F[arr[j]];
            }
        }
        if(tem > s)
            over = 1;
        if(!over && taken <= k)
            mpp1[taken][tem]++;
    }
    for(i = 0; i < P[other]; i++)
    {
        LL tem = 0, taken = 0;
        bool over = 0;
        for(j = 0; j < other; j++)
        {
            if(tem > s)
                break;
            if(get_bit(i, j) == 0)
                continue;

            if(get_bit(i, j) == 1)
                tem += arr[half+j];
            else
            {
                taken++;
                if(arr[half+j] > 18)
                    over = 1;
                else
                    tem += F[arr[half+j]];
            }
        }
        if(tem > s) over = 1;
        if(!over && taken <= k)
            mpp2[taken][tem]++;
    }
//    for(i = 0; i <= k; i++)
//        mpp1[i][0] = mpp2[i][0] = 1;
    LL res = 0;
    for(i = 0; i <= k; i++)
    {
        for(j = 0; j <= k ;j++)
        {
            if(i+j> k) continue;
            for(auto x: mpp1[i])
            {
                if((s-x.first < 0) || (mpp2[j].find(s-x.first) == mpp2[j].end()))
                    continue;
                res += x.second * mpp2[j][s-x.first];
            }
        }
    }
    cout << res ;
    return 0;
}


