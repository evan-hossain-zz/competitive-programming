#include <bits/stdc++.h>

#define in freopen("C-small-attempt0.in", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
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

struct outfit{
    int j, p, s;
};
vector<outfit> arr;
int res;
int jp[20][20], ps[20][20], js[20][20], K;

void call(int indx, int mask)
{
    cerr << indx << ' ' << mask << endl;
    if(indx == SZ(arr))
    {
        if(no_of_ones(mask) > no_of_ones(res))
            res = mask;
        return;
    }
    call(indx+1, mask);
    if(jp[arr[indx].j][arr[indx].p] < K && js[arr[indx].j][arr[indx].s] < K && ps[arr[indx].p][arr[indx].s] < K)
    {
        jp[arr[indx].j][arr[indx].p]++;
        js[arr[indx].j][arr[indx].s]++;
        ps[arr[indx].p][arr[indx].s]++;
        call(indx+1, mask|(1<<indx));
        jp[arr[indx].j][arr[indx].p]--;
        js[arr[indx].j][arr[indx].s]--;
        ps[arr[indx].p][arr[indx].s]--;
    }
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, kase = 1, J, P, S, i, j, k;
    cin >> test;
    while(test--)
    {
        cerr << test << endl;
        res = 0;
        arr.clear();
        cin >> J >> P >> S >> K;
        cerr << J << ' ' << P << ' ' << S << ' ' << K << endl;
        for(i = 1; i <= J; i++)
            for(j = 1; j <= P; j++)
                for(k = 1; k <= S; k++)
                    arr.pb({i, j, k});
        clr(jp, 0);
        clr(js, 0);
        clr(ps, 0);
        call(0, 0);
        cout << "Case #" << kase++ << ": " << no_of_ones(res) << "\n";
        for(int i = 0; i < SZ(arr); i++)
        {
            if(res & (1 << i))
                cout << arr[i].j << " " << arr[i].p << " " << arr[i].s << "\n";
        }
    }
    return 0;
}
