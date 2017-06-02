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

pair<LL,LL> arr[MAX];
map <string,LL> mpp;
string names[MAX];
LL got[MAX];

bool comp(const pair<LL, LL> &a, const pair<LL, LL> &b)
{
    if(a.second == b.second)
        return names[a.first] < names[b.first];
    return a.second < b.second;
}

/*
5
14 5 999
p05 119
p02 179
p04 334
p01 364
p03 354
*/
int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL i, tot = 0, n, pa, minimum_trade_size, increment, avail_units, id = 0;
    cin >> n;
    cin >> minimum_trade_size >> increment >> avail_units;
    for(i = 0; i < n; i++)
    {
        string s;
        cin >> s >> arr[i].second;
        if(mpp.find(s) == mpp.end())
            mpp[s] = id++, names[id-1] = s;
        arr[i].first = mpp[s];
    }
    LL pre = avail_units+1;
    while(avail_units < pre)
    {
        sort(arr, arr+n, comp);
        pre = avail_units;
        tot = 0;
        for(i = 0; i < n; i++)
            tot += arr[i].second;
        if(tot < minimum_trade_size || avail_units < minimum_trade_size)
            break;
        LL baki;
        for(i = 0; i < n; i++)
        {
            long double dpa = (1.0*arr[i].second * avail_units) / tot;
            pa = dpa;
            LL tem = arr[i].second;
            if(dpa < minimum_trade_size)
            {
                if(dpa > minimum_trade_size/2.0 && arr[i].second >= minimum_trade_size)
                {
                    pa = minimum_trade_size;
                    baki = arr[i].second - pa;
                    if(baki == 0 || (baki-minimum_trade_size > 0 && (baki-minimum_trade_size)%increment == 0))
                    {
                        got[arr[i].first] += pa;
                        arr[i].second -= pa;
                        avail_units -= pa;
                    }
                }
            }
            else
            {
                pa = min(avail_units, min(arr[i].second, pa));
                pa = pa - ((pa - minimum_trade_size) % increment);
                baki = arr[i].second - pa;
                if(baki == 0 || (baki-minimum_trade_size > 0 && (baki-minimum_trade_size)%increment == 0))
                {
                    got[arr[i].first] += pa;
                    arr[i].second -= pa;
                    avail_units -= pa;
                }
            }
            tot -= tem;
        }
    }
    vector <pair<string, LL>> res;
    for(i = 0; i < n; i++)
        res.pb(mp(names[i], got[i]));
    sort(all(res));
    for(auto x: res)
        cout << x.first << ' ' << x.second << "\n";
    return 0;
}
