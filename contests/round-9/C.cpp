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

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int par[MAX], arr[MAX], Q[MAX], done[MAX];
LL sum[MAX], res[MAX];

int root(int v)
{
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}
void merge(int x,int y) 	//	x and y are some tools (vertices)
{
    x = root(x), y = root(y);
    if(par[y] < par[x])	// balancing the height of the tree
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    for(i = 1; i <= n; i++)
        cin >> Q[i];
    multiset <LL> sums;
    clr(par, -1);
    for(int q = n; q ; q--)
    {
        i = Q[q];
        int age = i-1, pore = i+1;
        if(!(done[age] || done[pore]))
        {
            done[i] = 1;
            sum[root(i)] = arr[i];
            sums.insert(sum[root(i)]);
        }
        else if(done[age] && done[pore])
        {
            sums.erase(sums.lower_bound(sum[root(age)]));
            sums.erase(sums.lower_bound(sum[root(pore)]));
            LL tem = sum[root(age)] + arr[i] + sum[root(pore)];
            merge(age, i);
            merge(pore, i);
            sum[root(i)] = tem;
            done[i] = 1;
            sums.insert(sum[root(i)]);
        }
        else if(done[age])
        {
            sums.erase(sums.lower_bound(sum[root(age)]));
            LL tem = sum[root(age)] + arr[i];
            merge(age, i);
            done[i] = 1;
            sum[root(i)] = tem;
            sums.insert(sum[root(i)]);
        }
        else
        {

            sums.erase(sums.lower_bound(sum[root(pore)]));
            LL tem = sum[root(pore)] + arr[i];
            merge(pore, i);
            done[i] = 1;
            sum[root(i)] = tem;
            sums.insert(sum[root(i)]);
        }
        res[q] = *sums.rbegin();
    }
    for(i = 1; i <= n; i++)
        cout << res[i] << "\n";
    return 0;
}
