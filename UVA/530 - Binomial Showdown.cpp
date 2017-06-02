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
#define infinity 2147483647
#define LL long long

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int gcd(int a, int b);
void divbygcd(int &a, int &b);
int nck(int n, int k);

int main()
{
    int n, k, i;
    while(scanf("%d %d", &n, &k) && (n | k))
        printf("%d\n", nck(n, k));
    return 0;
}

int nck(int n, int k)
{
    int todiv, tomul, i, j, upore = 1, niche = 1;
    if(k > n >> 1)
        k = n - k;
    for(i = k; i ; i--)
    {
        tomul = n - k + i;
        todiv = i;
        divbygcd(tomul, todiv);
        divbygcd(upore, todiv);
        divbygcd(tomul, niche);
        upore *= tomul;
        niche *= todiv;
    }
    return upore/niche;
}

void divbygcd(int &a, int &b)
{
    int g = gcd(a, b);
    a /= g;
    b /= g;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
