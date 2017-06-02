#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    int p;
    int q;
};

int main()
{
    int x, y, a, b, cnt = 0;
    point t;
    vector <point> v;
    cin >> x >> y >> a >> b;
    for(int i = a; i <= x; i++)
    {
        for(int j = b; j <= y && j < i; j++)
        {
            t.p = i;
            t.q = j;
            v.push_back(t);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for(int i = 0; i < v.size(); i++)
    {
        t = v[i];
        cout << t.p << " " << t.q << endl;
    }
    return 0;
}
