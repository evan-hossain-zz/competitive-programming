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

#define MAX 200010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int pointer; //Keeps track of the best line from previous query
deque<long long> M; //Holds the slopes of the lines in the envelope, aka M[i]
deque<long long> B; //Holds the y-intercepts of the lines in the envelope, aka C[i]
deque<LL> pos;
//Returns true if either line l1 or line l3 is always better than line l2

LL dp[MAX], n;
pair <LL,LL> arr[MAX];
bool bad(int l1,int l2,int l3)
{
	/*
	intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
	intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
	set the former greater than the latter, and cross-multiply to
	eliminate division
	*/
	return 1.0 * (B[l3]-B[l1])*(M[l1]-M[l2])< 1.0 * (B[l2]-B[l1])*(M[l1]-M[l3]); // must check overflow
}
//Adds a new line (with lowest slope) to the structure
void add(long long m,long long b, LL p)
{
	//First, let's add it to the end
	M.push_back(m);
	B.push_back(b);
	pos.push_back(p);
	//If the penultimate is now made irrelevant between the antepenultimate
	//and the ultimate, remove it. Repeat as many times as necessary
	while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
	{
		M.erase(M.end()-2);
		B.erase(B.end()-2);
		pos.erase(pos.end()-2);
	}
}
//Returns the minimum y-coordinate of any intersection between a given vertical
//line and the lower envelope
long long query(long long x)
{
	//If we removed what was the best line for the previous query, then the
	//newly inserted line is now the best for that query
	if (pointer>=M.size())
		pointer=M.size()-1;
	//Any better line must be to the right, since query values are
	//non-decreasing
	while (pointer<M.size()-1&&
	  ((x-pos[pointer] > n) ||
        (M[pointer+1]*(x-pos[pointer+1])+B[pointer+1]<M[pointer]*(x-pos[pointer])+B[pointer])))
		pointer++;
    if(x-pos[pointer] > n)
        return -1;
	return M[pointer]*(x-pos[pointer])+B[pointer];
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int d, m, i;
    clr(dp, -1);
    dp[0] = 0;
    cin >> d >> n >> m;
    for(i = 1; i <= m; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr+1, arr+1+m);
    arr[m+1] = mp(d, 0);
    m++;
    i = 1;
    while(i <= m && arr[i].first <= n)
        add(arr[i].second, 0, arr[i].first), i++;
    for(; i <= m; i++)
    {
        dp[i] = query(arr[i].first);
        cout << dp[i] << endl;
        add(arr[i].second, dp[i], arr[i].first);
    }
    cout << dp[m] << endl;
    return 0;
}
