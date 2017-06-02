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

#define MAX 1000010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int ms[MAX];

struct node{
    int type, moment, val, qno;
}Q[MAX];

LL tree[MAX];

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

void update(int idx, LL val, int n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}


int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, i;
    map <int,int> mpp;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> Q[i].type >> Q[i].moment >> Q[i].val, Q[i].qno = i, mpp[Q[i].val];
    i = 1;
    for(auto &x: mpp)
        x.second = i++;
    for(i = 0; i < n; i++)
        Q[i].val = mpp[Q[i].val];
    for(i = 0; i < n; i++)
    {
        if(Q[i].type == 1)
            update(Q[i].val, 1, SZ(mpp));
        else if(Q[i].type == 2)
            update(Q[i].val, -1, SZ(mpp));
        else
            cout << readSingle(Q[i].val) << "\n";
    }
    return 0;
}
