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

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL res[MAX], ans;
int n, k, arr[MAX];
pair <int,int> limits[MAX];
map <int,int> mpp;
set <int> ss;

int tree[MAX];

int read(int idx)
{
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}


int block;

struct query{
    int no, l, r;
}Q[MAX];

bool comp(const query &a, const query &b)
{
    if(a.l/block == b.l/block)
        return a.r < b.r;
    return a.l/block < b.l/block;
}

void add(int val)
{
    int l = limits[val].first, r = limits[val].second;
    val = arr[val];
    int cur = read(val);
    ans += cur - read(l-1);
    ans += read(r) - cur;
    update(val, 1, SZ(mpp));
}

void remove(int val)
{
    int l = limits[val].first, r = limits[val].second;
    val = arr[val];
    update(val, -1, SZ(mpp));
    int cur = read(val);
    ans -= cur - read(l-1);
    ans -= read(r) - cur;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int q, i;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> arr[i], ss.insert(arr[i]);
    i = 1;
    mpp[0] = 0;
    for(auto x: ss)
        mpp[x] = i++;
    for(i = 0; i < n; i++)
    {
        auto pt = ss.lower_bound(arr[i]-k);
        if(pt != ss.end())
            limits[i].first = mpp[*pt];
        else
            limits[i].first = 1;
        pt = ss.lower_bound(arr[i]+k);
        if(pt != ss.end())
        {
            if(ss.find(arr[i]+k) == ss.end())
                limits[i].second = mpp[*pt]-1;
            else
                limits[i].second += mpp[*pt];
        }
        else
            limits[i].second += SZ(mpp);
    }
    for(i = 0; i < n; i++)
        arr[i] = mpp[arr[i]];
    cin >> q;
    for(i = 0; i < q; i++)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].no = i;
    }
    block = sqrt(n);
    sort(Q, Q+q, comp);
    int Lp = 0, Rp = -1;
    for(i = 0; i < q; i++)
    {
        while(Lp < Q[i].l)
            remove(Lp++);
        while(Lp > Q[i].l)
            add(--Lp);
        while(Rp < Q[i].r)
            add(++Rp);
        while(Rp > Q[i].r)
            remove(Rp--);
        res[Q[i].no] = ans;
    }
    for(i = 0; i < q; i++)
        cout << res[i] << "\n";
    return 0;
}


