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

#define MAX 1000010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL res[MAX];
LL n;

void done(LL pos)
{
    cout << "NO";
    exit(0);
}

void print(auto x)
{
    for(auto y: x)
        cout << y.first << "-" << y.second << ", ";
    cout << endl;
}

void rec(LL pos, map<LL,LL> mpp)
{
    if(pos > 2*n-1)
    {
        if(!mpp.empty())
            done(pos);
        return;
    }
    if(mpp.empty())
        done(pos);
    auto candidate = *mpp.begin();
    res[pos] = candidate.first;
    mpp.erase(candidate.first);
    candidate.second--;
    if(candidate.second)
        mpp[candidate.first] = candidate.second;
    if(SZ(mpp) % 2)
        done(pos);
    map <LL,LL> lef, rig;
    bool l = 1;
    vector <pair<LL,LL>> tem;
    for(auto x: mpp)
    {
        tem.pb(mp(-x.second, x.first));
        if(candidate.second < x.second)
            done(pos);
    }
    sort(all(tem));
    for(int i = 0; i < SZ(tem); i++)
    {
        int cnt = 1, j = i+1;
        while(j < SZ(tem) && tem[i].first == tem[j].first)
            j++, cnt++;
        if(cnt % 2)
            done(pos);
        for(j = 0; j < cnt/2; j++)
            lef[tem[i+j].second] = -tem[i+j].first;
        for(; j < cnt; j++)
            rig[tem[i+j].second] = -tem[i+j].first;
        i = i+cnt-1;
    }
    rec(pos*2, lef);
    rec(pos*2+1, rig);
}

int main()
{
    #ifdef Evan
        in;
//        out;
    #endif
    LL i, x;
    while(cin >> n)
    {
        map <LL,LL> mpp, inp;
        for(i = 1; i < 2*n; i++)
        {
            cin >> x, inp[x];
            res[i] = x;
        }
        int mc = 0;
        for(auto &x: inp)
            x.second = ++mc;
        for(i = 1; i < 2*n; i++)
        {
            mpp[inp[res[i]]]++;
            res[i] = 1e18;
        }
        rec(1, mpp);
        if(*max_element(res+1, res+2*n) > 1e17)
            done(0);
        cout << "YES\n";
        for(i = 1; i < 2*n; i++)
        {
            if(2*i < 2*n)
                assert(res[i] == res[2*i]);
            if(2*i+1 < 2*n)
                assert(res[i] < res[2*i+1]);
            cout << res[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
/*
8
1 1 1 1 2 4 4 6 3 3 3 7 5 5 8
8
1 1 1 1 2 4 4 6 3 3 3 7 5 5 8
*/
