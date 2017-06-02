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

#define MAX 1000010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int match[MAX];
string pat;

void compute_match_array()
{
    int m = SZ(pat);
    int len = 0;
    int i;
    match[0] = 0, i = 1;
    // calculate match[i] for i = 1 to m - 1
    while(i < m)
    {
        if(pat[i] == pat[len])
        {
            len++;
            match[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
                len = match[len - 1];
            else
            {
                match[i] = 0;
                i++;
            }
        }
    }
    for(int i = 0; i < SZ(pat); i++)
        cout << match[i] << ' ';
    cout << endl;
}

string s;
int arr[MAX];

int ok(int pos)
{
    int i = 0;
    while(pos < SZ(s) && i < SZ(pat) && s[pos] == '?')
        s[pos++] = pat[i++];
    if(i == SZ(pat))
        return 1;
    if(SZ(pat)-i > match[i])
        return 0;
    return 1;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, i;
    cin >> n >> m >> pat;
    for(i = 0; i < n; i++)
        s += "?";
    for(i = 0; i < m; i++)
        cin >> arr[i], arr[i]--;
    compute_match_array();
    for(i = m-1; i >= 0; i--)
    {
        if(!ok(arr[i]))
        {
            cout << 0;
            return 0;
        }
    }
    LL res = 1, mod = 1e9+7;
    for(auto x: s)
    {
        if(x == '?')
            res *= 26, res %= mod;
    }
    cout << res;
    return 0;
}

