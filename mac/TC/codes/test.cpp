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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/


vector <LL> ors, sums, x;
LL got_sum;

bool isSet(int indx, LL val) {
	return ((1LL<<indx) & val) > 0;
}

bool check() {
	for(int i = 2; i < SZ(x); i++)
		x[i] = sums[i-1] - x[i-1];
	for(int i = 1; i < SZ(x); i++){
		if(((x[i]|x[i-1]) != ors[i-1]) || (x[i]+x[i-1] != sums[i-1]))
			return false;
	}
	return true;
}

bool rec(int indx, bool carry) {
    cout << indx << ' ' << got_sum << endl;
	if(got_sum >= sums[0] || indx > 62)
	{
        if(carry == 0)
            return check();
        return false;
    }

	bool res = 0;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			int sum_val = (i + j + carry) % 2;
			int next_carry = (i + j + carry) / 2;
			int or_val = (i | j);

			if(sum_val == isSet(indx, sums[0]) && or_val == isSet(indx, ors[0]))
			{
				x[0] |= (1LL<<indx)*i;
				x[1] |= (1LL<<indx)*j;
                got_sum |= (1LL<<indx) * sum_val;
				res |= rec(indx+1, next_carry);

				if(res)
					return res;
				x[0] &= ~(1LL<<indx);
				x[1] &= ~(1LL<<indx);

                got_sum &= ~(1LL<<indx);
			}
		}
	}
	return res;
}

string isPossible(vector<long long> pairOr, vector<long long> pairSum) {
	ors = pairOr;
	sums = pairSum;
	x.resize(SZ(pairOr)+1, 0);
    got_sum = 0;
	if(rec(0, 0))
		return "Possible";
	return "Impossible";
}

int main()
{
    vector <LL> pairSum, pairOr, x;
    int kase, n;
    cin >> kase >> n;
    while(kase--)
    {
        pairSum.resize(n, 0);
        pairOr.resize(n, 0);
        x.resize(n+1, 0);

        x[0] = (rand()*rand())%500000000000000;
        x[1] = (rand()*rand())%500000000000000;

        pairSum[0] = x[0] + x[1];
        pairOr[0] = x[0] | x[1];
        for(int i = 2; i < n+1; i++){
            x[i] = (rand()*rand())%500000000000000;
            pairSum[i-1] = x[i-1] + x[i];
            pairOr[i-1] = x[i-1] + x[i];
        }
        cout << isPossible(pairOr, pairSum) << endl;
    }
    return 0;
}
