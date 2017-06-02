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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

pair<LL,int> arr[MAX];
LL cum[MAX];

int main()
{
	LL n, A, cf, cm, m, i, low, high, mid, res = 0, indx, cur, val;
	cin >> n >> A >> cf >> cm >> m;
	for(i = 0; i < n; i++)
		cin >> arr[i].first, arr[i].second = i;
	sort(arr, arr+n);
	cum[0] = arr[0].first;
	arr[n].first = A;
	for(i = 1; i < n; i++)
		cum[i] = cum[i-1] + arr[i].first;
	for(i = n; i >= 0; i--)
	{
		m -= max(0LL, A - arr[i].first);
		if(m < 0)
			break;
		low = 1, high = i, indx = -1;
		cur = (n-i)*cf;
		while(low <= high)
		{
			mid = (low+high)/2;
			LL need = (mid*arr[mid-1].first)-cum[mid-1];
			if(need > m)
				high = mid-1;
			else
			{
				low = mid+1;
				indx = mid;
			}
		}
		if(indx > 0)
			cur += arr[indx].first*cm;
		if(res < cur)
		{
			res = cur;
		}
	}
	cout << res << "\n";
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 















