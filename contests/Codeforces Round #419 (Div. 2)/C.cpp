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

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 555
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int arr[MAX][MAX], tem[MAX][MAX], n, m;

void add_to_row(int r, int val)
{
	for(int j = 0; j < m; j++)
		tem[r][j] += val;
}

void add_to_col(int c, int val)
{
	for(int i = 0; i < n; i++)
		tem[i][c] += val;
}

int main()
{
	// in;
	// out;
	int i, j, res = infinity;
	cin >> n >> m;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			cin >> arr[i][j];
	int maxr = MAX;
	vector <int> rows, cols;
	for(j = 0; j < m; j++)
		maxr = min(maxr, arr[0][j]);
	for(int curr = 0; curr <= maxr; curr++)
	{
		vector <int> tem_rows, tem_cols;
		for(i = 1; i <= curr; i++)
			tem_rows.pb(0);
		bool ok = true;
		int cur_res = curr;
		memset(tem, 0, sizeof tem);
		for(j = 0; j < m; j++)
		{
			tem[0][j] = curr;
			if(tem[0][j] < arr[0][j])
			{
				int val = arr[0][j]-tem[0][j];
				cur_res += val;
				add_to_col(j, val);
				while(val--)
					tem_cols.pb(j);
			}
		}
		for(i = 1; i < n; i++)
		{
			int cnt = 0, val = -1;
			for(j = 0; j < m; j++)
			{
				if(tem[i][j] > arr[i][j])
				{
					ok = false;
					break;
				}
				if(val == -1)
				{
					val = arr[i][j] - tem[i][j];
					cnt = 1;
				}
				else if(val == arr[i][j] - tem[i][j])
					cnt++;
				else
				{
					ok = false;
					break;
				}
			}
			if(val > 0 && cnt != m)
				ok = false;
			if(ok && val > 0)
			{
				cur_res += val;
				while(val--)
					tem_rows.pb(i);
			}
		}
		if(ok && cur_res < res)
		{
			res = min(res, cur_res);
			rows = tem_rows;
			cols = tem_cols;
		}
	}
	if(res == infinity)
	{
		cout << -1;
		return 0;
	}
	cout << res << "\n";
	while(!rows.empty())
	{
		cout << "row " << rows.back()+1 << "\n";
		rows.pop_back();
	}
	while(!cols.empty())
	{
		cout << "col " << cols.back()+1 << "\n";
		cols.pop_back();
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 















