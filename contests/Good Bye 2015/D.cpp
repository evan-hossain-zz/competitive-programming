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

#define MAX 5010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/


struct info
{
    int tup[2], indx; //tup[0] = prev rank, tup[1] = new rank
}arr[MAX];

int sorted[18][MAX], step;
string text;

bool comp(const info &a, const info &b)
{
    return a.tup[0] != b.tup[0]? a.tup[0] < b.tup[0] : a.tup[1] < b.tup[1];
}

void build_suffix_array(void)
{
    int i, n = SZ(text), jump;
    for(i = 0; i < n; i++)
    {
        sorted[0][i] = text[i] - '0'+1; //rank suffixes according to 1st char
//        clr(arr[i].tup, 0);
    }
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(i = 0; i <=n; i++)
        {
            arr[i].indx = i;
            arr[i].tup[0] = sorted[step - 1][i]; // what i was in prev step
            arr[i].tup[1] = i + jump < n? sorted[step - 1][i + jump] : -1;
        }
        sort(arr, arr + n, comp);
        sorted[step][arr[0].indx] = 0;
        for(i = 1; i < n; i++)
            sorted[step][arr[i].indx] = arr[i].tup[0] == arr[i - 1].tup[0] &&
            arr[i].tup[1] == arr[i - 1].tup[1] ? sorted[step][arr[i - 1].indx] : i;
    }
//    cout << "Suffix Array : \n\n";
//    for(i = 0; i < n; i++)
//        cout<<arr[i].indx<<' '<<text.substr(arr[i].indx)<<endl;
}

int LCP(int id1, int id2)
{
    int n = SZ(text), i, j, ret = 0;
//        cout << id1 << ' ' << id2 << endl;
    for(j = step - 1; j >= 0; j--)
        if(sorted[j][id1] == sorted[j][id2] && sorted[j][id1])
        {
            ret += (1 << j);
            id1 += (1 << j);
            id2 += (1 << j);
        }
    return ret;
}

LL dp[MAX][MAX], mod = 1e9+7, ok[MAX][MAX], cnt;

string s;

LL call(int l, int r)
{
    if(l == 0)
        return 1;
    LL &ret = dp[l][r];
    if(ret != -1) return ret;
    ret = 0;
    int to = l-1;
    for(int i = l-1; i >= 0; i--)
    {
        if(s[i] == '0') continue;
        int ls = to-i+1;
        int rs = r-l+1;
        if(ls > rs)
            break;
        if(ls==rs && !ok[i][l])
            continue;
        ret += call(i, to);
        ret %= mod;
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    cin >> s >> s;
//    for(int i = 0; i < MAX; i++)
//        s += "1";
    text = s;
    build_suffix_array();
    for(int len = 1; len <= SZ(s); len++)
        for(int i = 0; i + len + len <= SZ(s); i++)
        {
            if(s[i] == '0' || s[i+len] == '0') continue;
            int lcp = LCP(i, i+len);
            if(lcp >= len) continue;
            if(s[i+lcp] < s[i+len+lcp])
                ok[i][i+len] = 1;
        }
    clr(dp, -1);
    LL res = 0;
    for(int i = SZ(s)-1; i >= 0; i--)
    {
        if(s[i] != '0')
            res += call(i, SZ(s)-1);
        res %= mod;
    }
    cout << res << "\n";
    return 0;
}
