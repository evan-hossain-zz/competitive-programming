#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output2.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 55
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int arr[MAX], n, dp[900][900][MAX], visited[900][900][MAX], kase = 1;

int call(int a, int b, int c, int indx)
{
    if(indx == n)
        return (a == b) && (b == c);
    if(a >= 835 || b >= 835 || c >= 835)
        return 0;
    int tem[3] = {a, b, c};
    sort(tem, tem+3);
    a = tem[0], b = tem[1], c = tem[2];
//    if(a > b)
//        swap(a, b);
    int &ret = dp[a][b][indx];
    int &visit = visited[a][b][indx];
    if(visit == kase)
        return ret;
    visit = kase;
    ret = call(a+arr[indx], b, c, indx+1);
    ret = max(ret, call(a, b+arr[indx], c, indx+1));
    ret = max(ret, call(a, b, c+arr[indx], indx+1));
    return ret;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, i;
    scanf("%d", &test);
    while(test--)
    {
//        cerr << test << endl;
        scanf("%d", &n);
//        assert(n <= 50);
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printf("Case %d: ", kase++);
        if(n > 2 && accumulate(arr, arr+n, 0) % 3 == 0 && call(0, 0, 0, 0))
            puts("Eid Makes Happy Everyone");
        else
            puts(":(");
    }
    return 0;
}
