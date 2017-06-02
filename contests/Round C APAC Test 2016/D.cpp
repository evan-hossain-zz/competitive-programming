#include <bits/stdc++.h>

#define in freopen("D-large.in", "r", stdin);
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

#define MAX 3010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL arr[MAX][MAX], A[MAX], B[MAX], N, C, X, K;
LL ONE[MAX][MAX], TWO[MAX][MAX];

int main()
{
        in;
        out;
    int test, kase = 1, i, j;
    cin >> test;
    while(test--)
    {
        cin >> N >> K >> C >> X;
        for(i = 1; i <= N; i++)
            cin >> A[i];
        for(i = 1; i <= N; i++)
            cin >> B[i];
        for(i = 1; i <= N; i++)
        {
            for(j = 1; j <= N; j++)
                arr[i][j] = (A[i]*i + B[j]*j + C) % X;
            multiset <int> ss;
            for(j = 1; j <= K; j++)
                ss.insert(arr[i][j]);
            ONE[i][j-K] = *ss.rbegin();
            for(; j <= N; j++)
            {
                ss.erase(ss.lower_bound(arr[i][j-K]));
                ss.insert(arr[i][j]);
                ONE[i][j-K+1] = *ss.rbegin();
            }
        }
        for(j = 1; j + K - 1 <= N; j++)
        {
            multiset <int> ss;
            for(i = 1; i <= K; i++)
                ss.insert(ONE[i][j]);
            TWO[i-K][j] = *ss.rbegin();
            for(; i<= N; i++)
            {
                ss.erase(ss.lower_bound(ONE[i-K][j]));
                ss.insert(ONE[i][j]);
                TWO[i-K+1][j] = *ss.rbegin();
            }
        }
        LL res = 0;
        for(i = 1; i + K - 1 <= N; i++)
            for(j = 1; j + K -1 <= N; j++)
                res += TWO[i][j];
        cout << "Case #" << kase++ << ": " << res << "\n";
    }
    return 0;
}
