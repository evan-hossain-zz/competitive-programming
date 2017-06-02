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

#define in freopen("input.in", "r", stdin);
#define out freopen("output.out", "w", stdout);
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

struct point{double x, y, z, r; point () {} point(double a, double b, double c) {x = a, y = b, z = c;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

point arr[MAX];

template <class T> double getdist(T a, T b){return sqrt(sqr(a.x - b.x)+ sqr(a.y - b.y) + sqr(a.z - b.z));}    // distance between a and b


int main()
{
	in;
	out;
	int test, kase = 1, n, i, j, k;
	cin >> test;
	while(test--)
	{
		cin >> n;
		for(i = 0; i < n; i++)
			cin >> arr[i].x >> arr[i].y >> arr[i].z >> arr[i].r;
		LL res  = 1LL << 60;
		for(i = 0; i < (1<<n); i++)
		{
			double cur[2] = {0};
			for(j = 0; j < n; j++)
			{
				for(k = 0; k < n; k++)
				{
					if(((i&j)==0) == ((i&k)==0))
					{
						double betweenCenters = getdist(arr[j], arr[k]);
						if(betweenCenters * 2 <= max(arr[j].r, arr[k].r))
							cur[(i&k)==0] = max(cur[(i&k)==0], 2*sqrt(2*sqr(max(arr[j].r, arr[k].r))));
						else
							cur[(i&k)==0] = max(cur[(i&k)==0], (betweenCenters + sqrt(2*sqr(arr[j].r)) + sqrt(2*sqr(arr[k].r))));
					}
				}
			}
			LL curLL[2];
			// cout << cur[0]/sqrt(3) << ", " << cur[1]/sqrt(3) << endl;
			for(j = 0; j < 2; j++)
			{
				curLL[j] = ceil(cur[j]/sqrt(3));
				// if(cur[j]-(LL)cur[j] > eps)
				// 	curLL[j] = (LL) cur[j] + 1;
				// else
				// 	curLL[j] = (LL) cur[j];
			}
			res = min(res, max(curLL[0], curLL[1]));
		}
		cout << "Case #" << kase++ << ": " << res << "\n";
		cerr << kase << ' ' << n << ' ' << res << endl;
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 