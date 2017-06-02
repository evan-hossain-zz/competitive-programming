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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int N = 100000;
int lp[MAX], k;
vector<int> pr;
set <int> primes;
LL res;

void rec(int indx, LL gun, bool taken)
{
    if(indx == SZ(pr))
    {
        if(gun <= k && gun > 1 && taken)
            res = max(res, gun);
        return;
    }
    rec(indx+1, gun, taken);
    for(int i = 0; gun*pr[indx] <= k; i++)
    {
        gun *= pr[indx];
        rec(indx+1, gun, taken || (!primes.empty() && primes.find(pr[indx]) != primes.end()));
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL n, a, g = 0, i;
    cin >> n >> k;
    while(n--)
    {
        cin >> a;
        g = gcd(g, a);
    }
    N = sqrt(k);
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for(i = 0; pr[i]*pr[i] <= g; i++)
    {
        if(g % pr[i] == 0)
        {
            primes.insert(pr[i]);
            while(g % pr[i] == 0)
                g /= pr[i];
        }
    }
    if(g > 1)
        primes.insert(g);
    rec(0, 1, 0);
//    if(SZ(primes) == 1)
//    {
//        if(res % primes[0])
//            res = 0;
//    }
    cout << res;
    return 0;
}
