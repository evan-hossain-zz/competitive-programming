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
#include <numeric>

#define in freopen("control.in", "r", stdin);
#define out freopen("control.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
#define infinity (1LL << 50)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (LL)(v.size())
#define eps 1e-7

LL col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
LL row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
LL col4[4] = {1, 0, -1, 0};
LL row4[4] = {0, 1, 0, -1};
//LL months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct poLL{LL x, y; poLL () {} poLL(LL a, LL b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(LL i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

struct node{
	LL a, b, indx;
}arr[MAX];

bool comp_a(const node &a, const node &b)
{
	return a.a > b.a;
}

LL seg_tree[MAX*4];

int ans[MAX];

void update(LL l, LL r, LL cur, LL pos, LL val)
{
	if(l == r)
	{
		seg_tree[cur] = val;
		return;
	}
	LL lchild = cur << 1, rchild = lchild|1, m = (l+r)>>1;
	if(pos <= m)
		update(l, m, lchild, pos, val);
	else
		update(m+1, r, rchild, pos, val);
	seg_tree[cur] = min(seg_tree[lchild], seg_tree[rchild]);
}

LL query(LL L, LL R, LL l, LL r, LL cur)
{
	if(l > R || r < L)
		return infinity;
	if(l >= L && r <= R)
		return seg_tree[cur];
	LL lchild = cur << 1, rchild = lchild|1, m = (l+r)>>1;
	return min(query(L, R, l, m, lchild),
			query(L, R, m+1, r, rchild));
}

LL get_smaller_b(LL b, LL high, LL n)
{
	LL low = 0, mid, ret = -1;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(query(mid, high, 0, n-1, 1) < b)
		{
			ret = mid;
			low = mid+1;
		}
		else
			high = mid-1;
	}
	return ret;
}

int main()
{
	LL n, i;
	LL all_a = 0, all_b = 0;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> arr[i].a;
		all_a += arr[i].a;
	}
	for(i = 0; i < n; i++)
	{
		cin >> arr[i].b;
		arr[i].indx = i;
		all_b += arr[i].b;
	}
	sort(arr, arr+n, comp_a);
	LL sum_a = 0, sum_b = 0, can_take = n/2 + 1;
	for(i = 0; i < 4*MAX; i++)
		seg_tree[i] = infinity;
	// for(i = 0; i < n; i++)
	// {
	// 	cout << arr[i].a << ' ';
	// }
	// cout << endl;
	// for(i = 0; i < n; i++)
	// {
	// 	cout << arr[i].b << ' ';
	// }
	// cout << endl;
	for(i = 0; i < can_take; i++)
	{
		ans[arr[i].indx] = 1;
		sum_a += arr[i].a;
		sum_b += arr[i].b;
		update(0, n-1, 1, i, arr[i].b);
	}
	for(; i < n; i++)
	{
		if(sum_a*2 > all_a && 2*sum_b > all_b)
			break;
		LL pos = get_smaller_b(arr[i].b, i-1, n);
		if(pos == -1)
			continue;
		int indx = arr[pos].indx;
		ans[indx] = 0;
		ans[arr[i].indx] = 1;
		sum_a -= arr[indx].a;
		sum_b -= arr[indx].b;
		sum_a += arr[i].a;
		sum_b += arr[i].b;
		update(0, n-1, 1, pos, infinity);
		update(0, n-1, 1, i, arr[i].b);
	}
	int taken = accumulate(ans, ans+n, 0);
	if(sum_a*2 > all_a && 2*sum_b > all_b && taken <= can_take)
	{
		cout << taken << "\n";
		for(i = 0; i < n; i++)
			if(ans[i])
				cout << i+1 << ' ';
	}
	else
		assert(0);
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 















