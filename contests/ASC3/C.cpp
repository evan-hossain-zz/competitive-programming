#include <bits/stdc++.h>

#define in freopen("dissim.in", "r", stdin);
#define out freopen("dissim.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1LL << 50)
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

#define MAX 2010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

string alphabet, a, b, pup, pdown;
LL dp[MAX][MAX];
int arr[210][210], upVal[210], downVal[210], asUp[210], asDown[210];
map <int,int> mpp, ulta;

LL call(int i, int j)
{
    if(i == SZ(a) && j == SZ(b))
        return 0;
    LL &ret = dp[i][j];
    if(ret != -1) return ret;
    ret = infinity;
    if(i < SZ(a))
        ret = min(ret, call(i+1, j) + upVal[mpp[a[i]]]);
    if(j < SZ(b))
        ret = min(ret, call(i, j+1) + downVal[mpp[b[j]]]);
    if(i < SZ(a) && j < SZ(b))
        ret = min(ret, call(i+1, j+1) + arr[mpp[a[i]]][mpp[b[j]]]);
    return ret;
}

void print(int i, int j)
{
    if(i == SZ(a) && j == SZ(b))
        return;
    if(i < SZ(a) && call(i+1, j) + upVal[mpp[a[i]]] == dp[i][j])
    {
        pup += a[i];
        pdown += (char) asUp[mpp[a[i]]];
        print(i+1, j);
        return;
    }
    if(j < SZ(b) && call(i, j+1) + downVal[mpp[b[j]]] == dp[i][j])
    {
        pup += (char) asDown[mpp[b[j]]];
        pdown += b[j];
        print(i, j+1);
        return;
    }
    pup += a[i];
    pdown += b[j];
    print(i+1, j+1);
}

int main()
{
        in;
        out;
    cin >> alphabet >> a >> b;
    int i, j, x;
    for(i = 0; i < SZ(alphabet); i++)
        mpp[alphabet[i]] = i;
    clr(upVal, 63);
    clr(downVal, 63);
    for(i = 0; i < SZ(alphabet); i++)
        for(j = 0; j < SZ(alphabet); j++)
        {
            cin >> x;
            arr[i][j] = x;
            if(x < upVal[i])
            {
                upVal[i] = x;
                asUp[i] = alphabet[j];
            }
            if(x < downVal[j])
            {
                downVal[j] = x;
                asDown[j] = alphabet[i];
            }
        }
    clr(dp, -1);
    cout << call(0, 0) << "\n";
    print(0, 0);
    cout << pup << "\n" << pdown << "\n";
    return 0;
}
