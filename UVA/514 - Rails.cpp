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

int main()
{
    int n, i, arr[1010], a;
    while(scanf("%d", &n) == 1 && n)
        {
            while(scanf("%d", &arr[1]) == 1 && arr[1])
                {
                    for(i = 2; i <= n; i++)
                        scanf("%d", &arr[i]);
                    stack <int> st;
                    st.push(-1);
                    for(i = 1, a = 1; i <= n; i++)
                        {
                            if(i == arr[a])
                                {
                                    a++;
                                    while(st.top() == arr[a])
                                        {
                                            st.pop();
                                            a++;
                                        }
                                }
                            else if(i == st.top())
                                st.pop();
                            else
                                st.push(i);
                        }
                    if(st.top() == -1)
                        printf("Yes\n");
                    else
                        printf("No\n");
                }
        printf("\n");
        }
    return 0;
}

