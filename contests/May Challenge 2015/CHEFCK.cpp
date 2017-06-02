#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1LL << 60)
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

#define MAX 10000010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL arr[MAX], n, k, precal[MAX];

void sliding_window_minimum() {
  std::deque< std::pair<int, int> > window;
  for (int i = 1; i <= n; i++) {
     while (!window.empty() && window.back().first >= arr[i])
       window.pop_back();
     window.push_back(std::make_pair(arr[i], i));

     while(window.front().second <= i - k)
       window.pop_front();

     if(i < k) continue;
     precal[i-k+1] = window.front().first;
  }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL i, q, a, b, c, d, e, f, s, t, m, lm, dm, la, da, l1, d1, l, r, lc, dc;
    cin >> n >> k >> q;
    cin >> a >> b >> c >> d >> e >> f >> r >> s >> t >> m >> arr[1];
    cin >> l1 >> la >> lc >> lm >> d1 >> da >> dc >> dm;
    LL gun = t, cur;
    for(i = 2; i <= n; i++)
    {
        gun *= t;
        if(gun >= s) gun %= s;
        if(gun <= r)
        {
            cur = a*arr[i-1];
            if(cur >= m) cur %= m;
            cur += b;
            if(cur >= m) cur %= m;
            cur *= arr[i-1];
            if(cur >= m) cur %= m;
            cur += c;
            if(cur >= m) cur %= m;
            arr[i] = cur;
        }
        else
        {
            cur = d*arr[i-1];
            if(cur >= m) cur %= m;
            cur += e;
            if(cur >= m) cur %= m;
            cur *= arr[i-1];
            if(cur >= m) cur %= m;
            cur += f;
            if(cur >= m) cur %= m;
            arr[i] = cur;
        }
    }
    sliding_window_minimum();
    LL sum = 0;
    gun = 1;
    LL mod = 1e9+7, qr;
    for(i = 1; i <= q; i++)
    {
        cur = la*l1;
        if(cur >= lm) cur %= lm;
        cur += lc;
        if(cur >= lm) cur %= lm;
        l1 = cur;

        cur = da*d1;
        if(cur >= dm) cur %= dm;
        cur += dc;
        if(cur >= dm) cur %= dm;
        d1 = cur;
        l = l1 + 1;
        r = min(l+k-1+d1, n);
        qr = min(precal[l], precal[r-k+1]);
        sum += qr;
        gun *= qr;
        if(gun >= mod) gun %= mod;
    }
    cout << sum << ' ' << gun << "\n";
    return 0;
}
