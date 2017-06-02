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

#define MAX 8010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

/**
Define P(g,l) as the lowest position k that minimizes dp(g,l) ,
i.e. P(g,l) is the lowest k such that dp(g,l)=dp(g−1,k)+Cost(k+1,l)
P(g,0)≤P(g,1)≤P(g,2)≤…≤P(g,L−1)≤P(g,L)
**/

LL dp[801][MAX], C[MAX], L, cum[MAX], P[801][MAX];

LL getCost(int l, int r)
{
    if(l > r) return 0;
    return (cum[r] - cum[l-1])*(r-l+1);
}

void call(int g, int l1, int l2, int p1, int p2)
{
    if(l1 > l2) return;
    int m = l1+l2 >> 1, i;
    dp[g][m] = 1LL<<60;
    for(i = p1; i <= p2; i++)
    {
        LL cur = dp[g-1][i] + getCost(i+1, m);
        if(cur < dp[g][m])
        {
            dp[g][m] = cur;
            P[g][m] = i;
        }
    }
    call(g, l1, m-1, p1, P[g][m]);
    call(g, m+1, l2, P[g][m], p2);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int G, i;
    cin >> L >> G;
    for(i = 1; i <= L; i++)
        cin >> C[i], cum[i] = C[i]+cum[i-1];
    for(i = 1; i <= L; i++)
    {
        dp[1][i] = getCost(1, i);
        P[1][i] = 1;
    }
    for(i = 2; i <= G; i++)
        call(i, 1, L, 1, L);
    cout << dp[G][L] << "\n";
    return 0;
}
