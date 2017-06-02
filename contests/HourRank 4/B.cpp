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

#define MAX 210
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int arr[MAX], n, tot, cnt[3], dp[MAX][MAX][MAX][3][3];

int call(int pos, int one, int two, int a, int b)
{
    int player = pos%2;
    if(pos==n)
    {
        if(player==1)
            return abs(a-b)%3==0;
        return abs(a-b)%3!=0;
    }
    int &ret = dp[pos][one][two][a][b];
    if(ret != -1) return ret;
    ret = 0;
    int zero = cnt[0]-(pos+1-one-two);
    if(zero)
        ret |= !call(pos+1, one, two, a, b);
    if(one)
    {
        if(player==0)
            ret |= !call(pos+1, one+1, two, (a+1)%3, b);
        else
            ret |= !call(pos+1, one+1, two, a, (b+1)%3);
    }
    if(two)
    {
        if(player==0)
            ret |= !call(pos+1, one, two+1, (a+2)%3, b);
        else
            ret |= !call(pos+1, one, two+1, a, (b+2)%3);
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, i;
    cin >> test;
    while(test--)
    {
        clr(dp, -1);
        clr(cnt, 0);
        tot = 0;
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] %= 3;
            cnt[arr[i]]++;
            tot += arr[i];
        }
        if(call(cnt[0], cnt[1], cnt[2], 0, 0))
            cout << "Balsa\n";
        else
            cout << "Koca\n";
    }
    return 0;
}
