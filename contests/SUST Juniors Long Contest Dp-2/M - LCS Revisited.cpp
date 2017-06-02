#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

const int mod = 1000007;

int LCS[1010][1010], val, len1, len2;
int dp[1010][1010];
char arr1[1010], arr2[1010];

int check_lcs(int apos, int bpos);

int main()
{
    int test, kase, i, j;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf(" %s %s", &arr1, &arr2);
        len1 = strlen(arr1);
        len2 = strlen(arr2);
        for(i = 1; i <= len1; i++)
            for(j = 1; j <= len2; j++)
            {
                if(arr1[i - 1] == arr2[j - 1])
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
//        cout << LCS[i - 1][j - 1] << endl;
        len1 = max(len1, len2);
        for(i = 0; i <= len1; i++)
            LCS[0][i] = LCS[i][0] = 0;
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", kase, check_lcs(0, 0));
    }
    return 0;
}

int check_lcs(int apos, int bpos)
{
    if(apos == len1 || bpos == len2)
        return 1;
    int &ret = dp[apos][bpos];
    if(ret != -1)
        return ret;
    ret = 0;
    if(LCS[apos][bpos] == LCS[apos + 1][bpos + 1])
        ret += check_lcs(apos + 1, bpos + 1) % mod;
    if(LCS[apos][bpos] == LCS[apos + 1][bpos])
        ret += check_lcs(apos + 1, bpos) % mod;
    if(LCS[apos][bpos] == LCS[apos][bpos + 1])
        ret += check_lcs(apos, bpos + 1) % mod;
    return ret;
}
