#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, i, x;
    cin >> n;
    map <int,int> mpp;
    for(i = 0; i < n; i++)
        cin >> x, mpp[x]++;
    int res = n;
    for(auto x: mpp)
        res = max(res, n-x.second);
    cout << res;
    return 0;
}
