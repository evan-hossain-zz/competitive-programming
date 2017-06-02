#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>

#define in freopen("control.in", "r", stdin);
#define out freopen("control.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
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

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 200010
#define BLOCK 320
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int n, q;
LL res[BLOCK], baad[BLOCK], arr[MAX], mod = 1e9+7;
int whole_update[BLOCK];

void update(int l, int r, int x)
{
    int left_block = l/BLOCK;
    if(whole_update[left_block] != -1)
    {
        for(int i = left_block*BLOCK; i < (left_block+1)*BLOCK; i++)
            arr[i] = whole_update[left_block];
        whole_update[left_block] = -1;
    }
    while(l <= r && (l/BLOCK) == left_block)
        arr[l++] = x;
    int cur_indx = left_block*BLOCK;
    res[left_block] = 1;
    baad[left_block] = 1;
    while(cur_indx/BLOCK == left_block)
    {
        res[left_block] *= arr[cur_indx];
        res[left_block] %= mod;


        baad[left_block] *= (arr[cur_indx++]-1);
        baad[left_block] %= mod;
    }
    left_block++;
    int right_block = r/BLOCK;
    if(whole_update[right_block] != -1)
    {
        for(int i = right_block*BLOCK; i < (right_block+1)*BLOCK; i++)
            arr[i] = whole_update[right_block];
        whole_update[right_block] = -1;
    }
    while(l <= r && (r/BLOCK) == right_block)
        arr[r--] = x;
    cur_indx = right_block*BLOCK;
    res[right_block] = 1;
    baad[right_block] = 1;
    while(cur_indx/BLOCK == right_block)
    {
        res[right_block] *= arr[cur_indx];
        res[right_block] %= mod;
        baad[right_block] *= (arr[cur_indx++]-1);
        baad[right_block] %= mod;
    }
    right_block--;
    while(left_block <= right_block)
    {
        res[left_block] *= bigmod(x, BLOCK, mod);
        res[left_block] %= mod;
        baad[left_block] *= bigmod(x-1, BLOCK, mod);
        baad[left_block] %= mod;
        whole_update[left_block++] = x;
    }
}

LL get(int l, int r)
{
    LL ret = 1, minus = 1;
    int left_block = l/BLOCK;
    if(whole_update[left_block] != -1)
    {
        for(int i = left_block*BLOCK; i < (left_block+1)*BLOCK; i++)
            arr[i] = whole_update[left_block];
        whole_update[left_block] = -1;
    }
    while(l <= r && (l/BLOCK) == left_block)
    {
        ret *= arr[l];
        ret %= mod;
        minus *= (arr[l++]-1);
        minus %= mod;
    }
    left_block++;
    int right_block = r/BLOCK;
    if(whole_update[right_block] != -1)
    {
        for(int i = right_block*BLOCK; i < (right_block+1)*BLOCK; i++)
            arr[i] = whole_update[right_block];
        whole_update[right_block] = -1;
    }
    while(l <= r && (r/BLOCK) == right_block)
    {
        ret *= arr[r];
        ret %= mod;
        minus *= (arr[r--]-1);
        minus %= mod;
    }
    right_block--;
    while(left_block <= right_block)
    {
        ret *=res[left_block];
        ret %= mod;

        minus *= baad[left_block++];
        minus %= mod;
    }
    return ((ret-minus)%mod+mod)%mod;
}

int main()
{
    clr(whole_update, -1);
    int i;
    cin >> n >> q;
    for(i = 0; i < BLOCK; i++)
        res[i] = baad[i] = 1;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        res[i/BLOCK] *= arr[i];
        res[i/BLOCK] %= mod;

        baad[i/BLOCK] *= (arr[i]-1);
        baad[i/BLOCK] %= mod;
    }
    int t, l, r, x;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> l >> r >> x;
            l--, r--;
            update(l, r, x);
        }
        else
        {
            cin >> l >> r;
            l--, r--;
            cout << get(l, r) << "\n";
        }
    }
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 















