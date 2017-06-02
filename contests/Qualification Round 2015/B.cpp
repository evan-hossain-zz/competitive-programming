#include <bits/stdc++.h>

#define in freopen("B-small-attempt3.in", "r", stdin);
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

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    vector <int> arr;
    int test, res, kase = 1, i, d;
    cin >> test;
    while(test--)
    {
        cin >> d;
        arr.resize(d);
        for(i = 0; i < d; i++)
            cin >> arr[i];
        arr.pb(0);
        res = 0;
        sort(arr.rbegin(), arr.rend());
        while(arr.front())
        {
            int give = 0;
            if(arr[0] - arr[1] > 1)
            {
                give = arr[0] - arr[1];
                if(give+arr.back() > arr[1])
                    give >>= 1;
            }
            arr[0] -= give;
            arr.back() += give;
            sort(arr.rbegin(), arr.rend());
            int cut = max(arr.back(), 1);
            if(give) res++;
            res += cut;
            for(i = 0; i < SZ(arr); i++)
                arr[i] -= cut;
            sort(arr.rbegin(), arr.rend());
            while(!arr.empty() && arr.back() <= 0)
                arr.pop_back();
            arr.pb(0);
        }
        cout << "Case #" << kase++ << ": " << res << "\n";
    }
    return 0;
}

