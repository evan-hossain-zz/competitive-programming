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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int tree[MAX], ulta[MAX], n;
map <int, int> mpp;
set <int> ss;
pair<char, int> arr[MAX];

int read(int idx)
{
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int readSingle(int idx)
{
    int sum = tree[idx]; // sum will be decreased
    if (idx > 0)  // special case
    {
        int z = idx - (idx & -idx); // make z first
        idx--; // idx is no important any more, so instead y, you can use idx
        while (idx != z)  // at some iteration idx (y) will become z
        {
            sum -= tree[idx]; // substruct tree frequency which is between y and "the same path"
            idx -= (idx & -idx);
        }
    }
    return sum;
}

void update(int idx, int val)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int kth_smallest(int k)
{
    int low = 1, high = n, mid, ret = n;
    while(low <= high)
    {
        mid = (low+high)>>1;
        if(read(mid) >= k)
            high = mid - 1, ret = min(ret, mid);
        else
            low = mid + 1;
    }
    return ulta[ret];
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int x, q, i, mc = 0, pos;
    char c;
//    scanf("%d", &q);
    cin >> q;
    for(i = 0; i < q; i++)
    {
//        scanf(" %c %d", &arr[i].first, &arr[i].second);
        cin >> arr[i].first >> arr[i].second;
        if(arr[i].first != 'K')
            ss.insert(arr[i].second);
    }
    for(auto x: ss)
    {
        mpp[x] = ++mc;
        ulta[mc] = x;
    }
    n=mc;
    for(i = 0; i < q; i++)
    {
        c = arr[i].first;
        x = arr[i].second;
        if(c == 'I')
        {
            pos = mpp[x];
            if(!readSingle(pos)) update(pos, 1);
        }
        else if(c == 'D')
        {
            pos = mpp[x];
            if(readSingle(pos)) update(pos, -1);
        }
        else if(c == 'K')
        {
            if(read(mc) < x)
                cout << "invalid" << "\n";
            else
                cout << kth_smallest(x) << "\n";
        }
        else
            cout << read(mpp[x]-1) << "\n";
    }
    return 0;
}

