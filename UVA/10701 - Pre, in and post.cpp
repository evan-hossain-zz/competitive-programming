#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

int position(char x);
void post(int start, int end);

string inorder, pre;
int indx, n;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        indx = 0;
        scanf("%d", &n);
        cin >> pre >> inorder;
        post(0, n - 1);
        printf("\n");
    }
    return 0;
}

int position(char x)
{
    for(int i = 0; i < n; i++)
        if(inorder[i] == x)
            return i;
}

void post(int start, int end)
{
    if(start > end)
        return;
    char c = pre[indx++];
    post(start, position(c) - 1);
    post(position(c) + 1, end);
    printf("%c", c);
}
