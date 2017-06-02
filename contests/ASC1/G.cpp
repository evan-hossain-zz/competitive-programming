#include <bits/stdc++.h>

#define in freopen("people.in", "r", stdin);
#define out freopen("people.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 30)
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

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

struct node{
    int s, b, no;
}sequence[MAX], I[MAX];

int L[MAX], lislength;

int lis(int n)
{
    int i, low, high, mid;
    I[0].b = I[0].s = -infinity;
    for(i = 1; i <= n; i++)
        I[i].b = I[i].s = infinity;
    lislength = 0;
    for(i = 0; i < n; i++)
    {
        low = 0, high = lislength;
        while(low <= high)
        {
            mid = low + high >> 1;
            if(I[mid].b < sequence[i].b)
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = sequence[i];
        L[i] = low;
        if(lislength < low)
            lislength = low;
    }
    return lislength;
}

void printseq(int n)
{
    int pos, i, j, arr[lislength], val = lislength;
    for(i = n; i >= 0; i--)
        if(L[i] == lislength)
        {
            pos = i;
            break;
        }
    arr[--val] = sequence[i].no;
    for(i = pos-1; i >= 0; i--)
    {
        if(L[i] == val && sequence[pos].b > sequence[i].b && sequence[pos].s > sequence[i].s)
        {
            arr[--val] = sequence[i].no;
            pos = i;
        }
    }
    for(i = 0; i < lislength; i++)
        cout << arr[i] + 1<< ' ';
}


bool comp(const node &a, const node &b)
{
    if(a.s == b.s)
        return a.b > b.b;
    return a.s < b.s;
}

int main()
{
//    #ifdef Evan
        in;
        out;
//    #endif
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> sequence[i].s >> sequence[i].b, sequence[i].no = i;
    sort(sequence, sequence+n, comp);
    cout << lis(n) << "\n";
    printseq(n);
    return 0;
}
