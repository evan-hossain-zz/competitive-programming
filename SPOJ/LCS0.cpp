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

#define MAX 400000002
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

short tree[MAX];

short read(short idx)
{
    short sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(short idx, short val, short n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

vector <short> pos[200];

short I[MAX];

short lis(vector <short> &sequence)
{
    short i, low, high, mid, n = SZ(sequence);
    I[0] = -infinity;
    for(i = 1; i <= n; i++)
        I[i] = infinity;
    short lislength = 0;
    for(i = 0; i < n; i++)
    {
        low = 0, high = lislength;
        while(low <= high)
        {
            mid = (low + high) >> 1;
            if(I[mid] < sequence[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = sequence[i];
        if(lislength < low)
            lislength = low;
    }
    return lislength;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    string a, b;
    cin >> a >> b;
    short i, j;
    for(i = 0; i < SZ(a); i++)
        pos[a[i]].pb(i);
    for(i = 'a'; i <= 'z'; i++)
        sort(pos[i].rbegin(), pos[i].rend());
    vector <short> arr;
    for(i = 0; i < SZ(b); i++)
    {
        for(j = 0; j < SZ(pos[b[i]]); j++)
            arr.pb(pos[b[i]][j]);
    }
    cout << lis(arr) << "\n";
    return 0;
}

