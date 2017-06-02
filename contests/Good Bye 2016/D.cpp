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
#define out freopen("input.in", "w", stdout);
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

int X[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int Y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
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

#define MAX 310
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int grid[MAX][MAX], color[30][MAX][MAX][8], T[MAX], n;

pair<int,int> getNewDir(int dir)
{
	pair<int,int> ret;
	ret.first = (dir+1)%8;
	ret.second = ((dir-1)%8+8)%8;
	return ret;
}

void simulate()
{
	queue <int> Q;
	Q.push(1);
	Q.push(150);
	Q.push(150+T[0]);
	Q.push(0);
	color[1][150][150+T[0]][0] = 1;
	int x, y, dir, i, nx, ny;
	for(i = 1; i <= T[0]; i++)
		grid[150][150+i] = 1;
	int res = 0;
	while(!Q.empty())
	{
		i = Q.front();
		Q.pop();
		x = Q.front();
		Q.pop();
		y = Q.front();
		Q.pop();
		dir = Q.front();
		Q.pop();
		pair<int,int> dirs = getNewDir(dir);
		for(int m = 1; m <= T[i]; m++)
		{
			nx = x + m*X[dirs.first];
			ny = y + m*Y[dirs.first];
			grid[nx][ny] = 1;
			nx = x + m*X[dirs.second];
			ny = y + m*Y[dirs.second];
			grid[nx][ny] = 1;
		}
		nx = x + T[i]*X[dirs.first];
		ny = y + T[i]*Y[dirs.first];
		if(i+1 < n && color[i+1][nx][ny][dirs.first] == 0)
		{
			Q.push(i+1);
			Q.push(nx);
			Q.push(ny);
			Q.push(dirs.first);
			color[i+1][nx][ny][dirs.first] = 1;
		}

		nx = x + T[i]*X[dirs.second];
		ny = y + T[i]*Y[dirs.second];
		if(i+1 < n && color[i+1][nx][ny][dirs.second] == 0)
		{
			Q.push(i+1);
			Q.push(nx);
			Q.push(ny);
			Q.push(dirs.second);
			color[i+1][nx][ny][dirs.second] = 1;
		}
	}
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			res += grid[i][j] > 0;
	cout << res;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> T[i];
	simulate();
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 
















