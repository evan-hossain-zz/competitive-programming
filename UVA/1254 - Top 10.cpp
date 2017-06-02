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

#define MAX 400010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

string text;
bool bh[MAX],b2h[MAX];
int revSA[MAX],SA[MAX], cnt[MAX] , nxt[MAX], lcp[MAX], n, q, who[MAX], qStart[MAX], stable[MAX][20];
vector <vector<int>> segtree(MAX*4, vector <int>(0)), res(MAX, vector<int>(0));

bool cmp(int i,int j)
{
    return text[i]<text[j];
}

void sortFirstChar(int n)
{
    /// sort for the first char  ...
    for(int i =0 ; i<n ; i++)
        SA[i] = i;
    sort(SA,SA+n ,cmp);

    ///indentify the bucket ........
    for(int i=0 ; i<n ; i++)
    {
        bh[i] = (i==0  || text[SA[i]]!=text[SA[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket(int n)
{
    int bucket = 0;
    for(int i =0 ,j; i<n ; i=j)
    {
        j = i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}

void SetRank(int n)
{
    for(int i = 0 ; i<n ; i=nxt[i])
    {
        cnt[i] = 0;
        for(int j =i ; j<nxt[i] ; j++)
        {
            revSA[SA[j]] = i;
        }
    }
    return;
}

void findNewRank(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0)
        {
            int head = revSA[pre];
            revSA[pre] = head+cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
    return;
}

void findNewBucket(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0 && b2h[revSA[pre]])
        {
            for(int k = revSA[pre]+1 ; b2h[k] && !bh[k] ; k++) b2h[k] = false;
        }
    }
    return;
}

void buildSA(int n)
{
    ///start sorting in logn step ...
    sortFirstChar(n);
    for(int h =1 ; h<n ; h<<=1)
    {
        if(CountBucket(n)==n) break;
        SetRank(n);
        /// cause n-h suffix must be sorted
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;

        for(int i = 0 ; i<n ; i=nxt[i])
        {
            findNewRank(i,nxt[i] , h);
            findNewBucket(i , nxt[i] , h);
        }
        ///set the new sorted suffix array ...
        for(int i =0 ; i<n ; i++)
        {
            SA[revSA[i]] = i;
            bh[i] |= b2h[i]; ///new bucket ....
        }
    }
    return;
}

void buildLCP(int n)
{
    int len = 0;
    for(int i = 0 ;i<n ; i++)
        revSA[SA[i]] = i;
    for(int i =0 ; i< n ; i++)
    {
        int k = revSA[i];
        if(k==0)
        {
            lcp[k] = 0;
            continue;
        }
        int j = SA[k-1];
        while(i+len < n && j+len < n && text[i+len]==text[j+len]) len++;
        lcp[k] = len;
        if(len) len--;
    }
    return;
}

void printSA()
{
    for(int i=0;i<SZ(text);i++) printf("%d %d %d %s %d\n", i, SA[i], revSA[SA[i]], text.substr(SA[i]).c_str(), lcp[i]);
    puts("");
//    for(int i=1;i<SZ(text);i++) printf("%d ",lcp[i]);
    puts("");
    return ;
}

pair <string,int> arr[MAX];

bool comp(const pair<string,int> &a, const pair <string, int> &b)
{
    if(SZ(a.first) == SZ(b.first))
    {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    return SZ(a.first) < SZ(b.first);
}


set <int> ss;
void build(int l, int r, int cur)
{
    if(l == r)
    {
        if(who[SA[l]] < n)
            segtree[cur].pb(who[SA[l]]);
        return;
    }
    int lchild = cur << 1, rchild = lchild|1, m = (l+r) >> 1;
    build(l, m, lchild);
    build(m+1, r, rchild);
    ss.clear();
    if(!segtree[lchild].empty())
        ss.insert(all(segtree[lchild]));
    if(!segtree[rchild].empty())
        ss.insert(all(segtree[rchild]));
    m = 0;
    for(auto x: ss)
    {
        if(m == 10) break;
        m++;
        segtree[cur].pb(x);
    }
}

void query(int l, int r, int cur, int L, int R)
{
    if(l > R || r < L)
        return ;
    if(l >= L && r <= R)
    {
        ss.insert(all(segtree[cur]));
        while(SZ(ss)>10)
            ss.erase(--ss.end());
        return;
    }
    int lchild = cur << 1, rchild = lchild|1, m = (l+r) >> 1;
    query(l, m, lchild, L, R);
    query(m+1, r, rchild, L, R);
}

void preprocess(int n)
{
    int i, j;
    for(i = 0; i < n; i++) stable[i][0] = lcp[i];
    for(j = 1; (1<<j) <= n; j++)
    {
        for(i = 0; i + (1<<j) - 1 < n; i++)
            stable[i][j] = min(stable[i][j-1], stable[i+(1<<(j-1))][j-1]);
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j, low, high, mid, up, down, orgPos;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr+n, comp);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < SZ(arr[i].first); j++)
        {
            who[SZ(text)] = i;
            text += arr[i].first[j];
        }
        who[SZ(text)] = infinity;
        text += "#";
    }
    cin >> q;
    for(i = n; i < q+n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
        qStart[SZ(text)] = SZ(arr[i].first);
        for(j = 0; j < SZ(arr[i].first); j++)
        {
            who[SZ(text)] = i;
            text += arr[i].first[j];
        }
        who[SZ(text)] = infinity;
        text += "#";
    }
    buildSA(SZ(text));
    buildLCP(SZ(text));
//    printSA();
    preprocess(SZ(text));
    build(0, SZ(text)-1, 1);
    for(i = 0; i < SZ(text); i++)
    {
        orgPos = SA[i];
        if(qStart[orgPos] == 0) continue;
        low = 0, high = i, up = i+1;
        while(low <= high)
        {
            mid = (low+high) >> 1;
            j = log2(i-mid+1);
            if(min(stable[mid][j], stable[i-(1<<j)+1][j]) >= qStart[orgPos])
                high = mid - 1, up = mid;
            else
                low = mid + 1;
        }
        up--;
        low = i+1, high = SZ(text)-1, down = i;
        while(low <= high)
        {
            mid = (low+high) >> 1;
            j = log2(mid-i);
            if(min(stable[i+1][j], stable[mid-(1<<j)+1][j]) >= qStart[orgPos])
                low = mid + 1, down = mid;
            else
                high = mid - 1;
        }
        ss.clear();
        query(0, SZ(text)-1, 1, up, down);
        for(auto x: ss)
            res[arr[who[orgPos]].second].pb(arr[x].second+1);
    }
    for(i = n; i < n+q; i++)
    {
        if(res[i].empty())
            cout << "-1\n";
        else
        {
            for(j = 0; j < SZ(res[i])-1; j++)
                cout << res[i][j] << ' ';
            cout << res[i][j] << '\n';
        }
    }
    return 0;
}
/*
17
acm
icpc
regional
asia
jakarta
two
thousand
and
nine
arranged
by
universitas
bina
nusantara
especially
for
you
5
a
an
win
b
z
*/
