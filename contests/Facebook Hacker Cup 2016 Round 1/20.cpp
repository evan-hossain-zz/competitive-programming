#include <bits/stdc++.h>

#define in freopen("laundro_matt.in", "r", stdin);
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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL W[MAX];

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    priority_queue <pair<LL,int>, vector <pair<LL,int>>, greater <pair<LL,int>>> Q;
    int test, kase = 1;
    LL l, n, m, d, w, kapor, i;
    cin >> test;
    while(test--)
    {
        while(!Q.empty())
            Q.pop();
        cin >> l >> n >> m >> d;
        l *= 2;
        multiset <LL> ms;
        for(i = 0; i < n; i++)
            cin >> W[i], Q.push(mp(W[i], i)), ms.insert(W[i]);
        LL res = 0, washed = 0, machine = 0, idle = 0;
        kapor = 0;
        while(washed*2 < l)
        {
            auto cur = Q.top();
            Q.pop();
            if(cur.second < n)
            {
                if(kapor > l) continue;
                if(machine < min(l, m))
                    Q.push(mp(cur.first+d, n+1)), machine++;
                else
                    kapor++;
                auto it1 = ms.begin();
                auto it2 = ms.begin();
                it2++;
                ms.erase(it1, it2);
                cur.first += W[cur.second];
                Q.push(cur);
                ms.insert(cur.first);
            }
            else
            {
                if(cur.second == n+1)
                {
                    washed++;
                    res = cur.first;
                }
                if(kapor)
                {
                    kapor--;
                    cur.first += d;
                    cur.second = n+1;
                    Q.push(cur);
                }
                else if(idle < l)
                    Q.push(mp(*ms.begin(), n)), idle++;
            }
        }
        cout << "Case #" << kase++ << ": " << res << "\n";
        cerr << "Case #" << kase-1 << ": " << res << "\n";
    }
    return 0;
}
/*
1
1000000
1
1000000000
1000000000
1
*/
