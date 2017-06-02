#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str;}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define SZ 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

struct node
{
    int l, r, qno;
    bool flag;
};
int segtree[SZ * 3], input[SZ], ans[SZ / 2];
node arr[SZ + (SZ / 2)];

bool comp(const node &a, const node &b)
{
    if(a.r != b.r)
        return a.r < b.r;
    return a.flag < b.flag;
}

void update(int L, int R, int indx, int val, int cur)
{
    if(L == R)
    {
        segtree[cur] += val;
        return;
    }
    int mid = (L + R) / 2;
    if(indx <= mid)
        update(L, mid, indx, val, cur * 2);
    else
        update(mid + 1, R, indx, val, cur * 2 + 1);
    segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1];
}
int query(int L, int R, int left_bound, int right_bound, int cur)
{
    if(L > right_bound || R < left_bound)
        return 0;
    if(L >= left_bound && R <= right_bound)
        return segtree[cur];
    return query(L, (L + R) / 2, left_bound, right_bound, cur * 2) +
                                        query(((L + R) / 2) + 1, R, left_bound, right_bound, cur * 2 + 1);
}

int main()
{
//    _
    int n, i, q, test;
//    cin >> test;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        clr(segtree, 0);
        clr(input, -1);
//        cin >> n >> q;
        scanf("%d %d", &n, &q);
        for(i = 1; i <= n; i++)
//            cin >> arr[i].l, arr[i].r = i, arr[i].flag = 0;
        scanf("%d", &arr[i].l), arr[i].r = i, arr[i].flag = 0;
        for(i = 1; i <= q; i++)
//            cin >> arr[n + i].l >> arr[n + i].r, arr[n + i].flag = 1, arr[n + i].qno = i;
        scanf("%d %d", &arr[n + i].l, &arr[n + i].r), arr[n + i].flag = 1, arr[n + i].qno = i;
        sort(arr + 1, arr + n + q + 1, comp);
//        for(i = 1; i <= n + q; i++)
//            cout << arr[i].l << ' ' << arr[i].r << ' ' << arr[i].op << endl;
        for(i = 1; i <= n + q; i++)
        {
            if(arr[i].flag == 0)
            {
                if(input[arr[i].l] != -1)
                    update(1, n, input[arr[i].l], -1, 1);
                update(1, n, arr[i].r, 1, 1);
                input[arr[i].l] = arr[i].r;
            }
            else
                ans[arr[i].qno] = query(1, n, arr[i].l, arr[i].r, 1);
        }
//        cout << "Case " << kase << ":" << endl;
        printf("Case %d:\n", kase);
        for(i = 1; i <= q; i++)
//            cout << ans[i] << endl;
            printf("%d\n", ans[i]);
    }
    return 0;
}
