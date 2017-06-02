#include <bits/stdc++.h>


#define MAX 100010
#define LOGMAX 20
using namespace std;
int stable[MAX][LOGMAX], arr[MAX];

void preprocess(int n)
{
    int i, j;
    for(i = 0; i < n; i++) stable[i][0] = arr[i];
    for(j = 1; (1<<j) <= n; j++)
    {
        for(i = 0; i + (1<<j) - 1 < n; i++)
            stable[i][j] = min(stable[i][j-1], stable[i+(1<<(j-1))][j-1]);
    }
}

int main()
{
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    int q;
    cin >> q;
    preprocess(n);
    while(q--)
    {
        cin >> i >> n;
        int lg = log2(n-i+1);
        cout << min(stable[i][lg], stable[n-(1<<lg)+1][lg]) << endl;
    }
    return 0;
}

