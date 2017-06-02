#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
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

#define MAX 1001
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

vector <bitset<MAX>> state[MAX];
vector <int> adj[MAX], sum[MAX*100];
int last[MAX], res, R[MAX*100];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, q, t, i, j, k;
    scanf("%d %d %d", &n, &m, &q);
    bitset <MAX> zero;
    for(i = 1; i < MAX; i++)
        state[i].pb(zero), adj[i].pb(0);
    for(i = 1; i < MAX*100; i++)
        sum[i].pb(0);
    for(int K = 1; K <= q; K++)
    {
        scanf("%d", &t);
        if(t < 3)
        {
            scanf("%d %d", &i, &j);
            int indx = lower_bound(all(adj[i]), last[i])-adj[i].begin();
            zero = state[i][indx];
            last[i] = K;
            if(t == 1 && zero[j]==false)
            {
                sum[i].pb(sum[i][indx]+1);
                res++;
                zero.set(j, true);
            }
            else if(t == 2 && zero[j])
            {
                sum[i].pb(sum[i][indx]-1);
                res--;
                zero.set(j, false);
            }
            state[i].pb(zero);
        }
        else if(t == 3)
        {
            scanf("%d", &i);
            int indx = lower_bound(all(adj[i]), last[i])-adj[i].begin();
            zero = state[i][indx];
            last[i] = K;
            sum[i].pb(m-sum[i][indx]);
            res -= sum[i][indx];
            res += sum[i].back();
            zero = zero.flip();
            state[i].pb(zero);
        }
        else
        {
            scanf("%d", &k);
            res = R[k];
            for(i = 1; i <= n; i++)
                last[i] = k;
        }
        R[K] = res;
        printf("%d\n", res);
    }
    return 0;
}
