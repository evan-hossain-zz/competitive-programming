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

#define MAX 200010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL tree[MAX];

LL read(int idx)
{
    LL sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, LL val, int n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

vector <pair<int,int>> rowSame[MAX], colSame[MAX];
vector <int> start[MAX], finish[MAX];
int arr[MAX][4];
LL res=0;
map <int,int> mpp, ulta;

vector <pair<int,int>> recalculate(vector <pair<int,int>> &same)
{
    vector <pair<int,int>> ret;
    sort(all(same));
    int l = same.front().first, r = same.front().second;
    for(auto v: same)
    {
        if(r < v.first)
        {
            ret.pb(mp(l, r));
            res += ulta[r]-ulta[l]+1;
            l = v.first, r = v.second;
        }
        else
        {
            r = max(r, v.second);
        }
    }
    ret.pb(mp(l, r));
    res += ulta[r]-ulta[l]+1;
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, i, j, mc = 0, l, r;
    cin >> n;
    int tem[4];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 4; j++)
            cin >> tem[j], mpp[tem[j]];
        if(tem[0] > tem[2])
            swap(tem[0], tem[2]);
        if(tem[1] > tem[3])
            swap(tem[1], tem[3]);
        for(j = 0; j < 4; j++)
            arr[i][j] = tem[j];
    }
    for(auto &v: mpp)
        v.second = ++mc, ulta[mc] = v.first;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 4; j++)
            arr[i][j] = mpp[arr[i][j]];
        if(arr[i][0] == arr[i][2])
            colSame[arr[i][0]].pb(mp(arr[i][1], arr[i][3]));
        else
            rowSame[arr[i][1]].pb(mp(arr[i][0], arr[i][2]));
    }
    for(i = 1; i <= mc; i++)
    {
        if(!colSame[i].empty())
            colSame[i] = recalculate(colSame[i]);
        if(!rowSame[i].empty())
            rowSame[i] = recalculate(rowSame[i]);
    }
    for(i = 1; i <= mc; i++)
    {
        for(auto v: colSame[i])
            start[v.first].pb(i), finish[v.second].pb(i);
    }
    for(i = 1; i <= mc; i++)
    {
        for(auto v: finish[i-1])
            update(v, -1, mc);
        for(auto v: start[i])
            update(v, 1, mc);
        for(auto v: rowSame[i])
            res -= read(v.second)-read(v.first-1);
    }
    cout << res << "\n";
    return 0;
}
