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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

tuple <int,int,int> Q[MAX];
int arr[MAX], ans[MAX], L[MAX];

double get(double n, double alpha)
{
    double ret;
    ret = log(n) / log(alpha);
    return -ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    ///.4
    cout << get(100, .4) << ' ' << get(100, .6) << endl;
    int n, q, i, l, r, res;
    cin >> n >> q;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    for(i = 1; i <= q; i++)
    {
        cin >> l >> r;
        Q[i] = make_tuple(l, r, i);
    }
    sort(Q+1,Q+1+q);
    multiset <pair<int,int>> ms1;
    multiset <pair<int,int>> ms2;
    set <int> seen;
    int j = 1;
    int tem[3] = {0};
    for(i = 1; i <= n; i++)
    {
        while(j <= q && get<0> (Q[j]) <= i)
        {
            l = get<1> (Q[j]);
            r = get<2> (Q[j]);
            ms1.insert(mp(l, r));
            ms2.insert(mp(l, get<0> (Q[j])));
            L[get<0> (Q[j])]++;
            j++;
        }
        if(!ms1.empty() && seen.find(arr[i]) != seen.end())
        {
            if(tem[arr[i] % 3])
                tem[arr[i]%3]--;
            seen.erase(arr[i]);
        }
        else if(!ms1.empty())
        {
            seen.insert(arr[i]);
            tem[arr[i]%3]++;
        }
//        cout << i << ' ' << tem[0] << ' ' << tem[1] << ' ' << tem[2] << endl;
        while(!ms1.empty() && (*ms1.begin()).first <= i)
        {
            auto pt = ms1.begin();
            if(tem[0])
                res = 0;
            else if(tem[2])
                res = bigmod(2, tem[2], 3);
            else
                res = 1;
            ans[(*pt).second] = res;
            ms1.erase(pt);
            pt = ms2.begin();
            L[(*pt).second]--;
            if(L[(*pt).second] == 0)
            {
                if(tem[arr[(*pt).second] % 3])
                    tem[arr[(*pt).second] %3]--;
                if(seen.find(arr[(*pt).second]) != seen.end())
                    seen.erase(arr[(*pt).second]);
            }
            ms2.erase(pt);
        }
        if(ms1.empty())
            clr(tem, 0);
    }
    for(i = 1; i <= q; i++)
        cout << ans[i] << "\n";
    return 0;
}
