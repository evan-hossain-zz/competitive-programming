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

#define MAX 200003
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int segtree[MAX*4][2];

void update(int l, int r, int cur, int indx, int val)
{
    if(l == r)
    {
        segtree[cur][0] += val;
        segtree[cur][1] += val;
        return;
    }
    int lchild = cur << 1, rchild = lchild | 1, m = (l+r)>>1;
    if(indx <= m)
        update(l, m, lchild, indx, val);
    else
        update(m+1, r, rchild, indx, val);
    segtree[cur][0] = max(segtree[lchild][0], segtree[rchild][0]);
    segtree[cur][1] = min(segtree[lchild][1], segtree[rchild][1]);
}

int T[MAX+5], n, m;
bool ok[MAX];

vector <int> text;
int revSA[MAX],SA[MAX];
int cnt[MAX] , nxt[MAX];
bool bh[MAX],b2h[MAX];
int lcp[MAX];


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


int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, i, kase = 1;
    scanf("%d", &test);
    while(test--)
    {
        clr(segtree, 0);
        clr(ok, 0);
        scanf("%d %d", &n, &m);
        text.resize(n);
        for(i = 0; i < n; i++)
            scanf("%d", &text[i]);
        for(i = 0; i < m; i++)
        {
            scanf("%d", &T[i]);
            if(n >= m)
                update(0, MAX, 1, T[i], 1);
        }
        printf("Case %d: ", kase++);
        if(m > n)
        {
            puts("0");
            continue;
        }
        text.pb(MAX-1);
        n++;
        bool has = false;
        for(i = 0; i < m; i++)
            update(0, MAX, 1, text[i], -1);
        if(segtree[1][0] == 0 && segtree[1][1] == 0)
            ok[0] = 1, has = true;
        while(i < n)
        {
            update(0, MAX, 1, text[i-m], 1);
            update(0, MAX, 1, text[i], -1);
            if(segtree[1][0] == 0 && segtree[1][1] == 0)
                ok[i-m+1] = 1, has = true;
            i++;
        }
        if(!has)
        {
            puts("0");
            continue;
        }
        buildSA(n);
        int res = infinity;
        for(i = 0; i < n; i++)
        {
            if(ok[SA[i]] == 0) continue;
            res = SA[i];
            break;
        }
        printf("%d\n", res+1);
    }
    return 0;
}
/*
5
4 3
1 3 2 4
1 2 3
5 3
3 2 1 4 10
1 2 4
4 3
1 3 2 4
1 2 3
5 3
3 2 1 4 10
1 2 4
5 3
3 4 2 1 4
1 2 4
*/
