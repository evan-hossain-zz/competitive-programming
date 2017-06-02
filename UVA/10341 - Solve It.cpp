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
#define e 2.71828182845904523536

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

double p, q, r, s, t, u;

double value(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x+ u;
}

int main()
{
    double lb, ub, mid, x, temp;
    while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6)
    {
        x= -1.0;
        ub = 1.0, lb = 0.0;
        while(lb < ub)
        {
            mid = (lb + ub) / 2.0;
            temp = value(mid);
            if(abs(temp - 0) <= 1e-7)
            {
                x = mid;
                break;
            }
            if(temp > 0)
                lb = mid;
            else
                ub = mid;
        }
        temp = value(ub);
        if(abs(temp - 0) <= 1e-7)
            x = ub;
        if(x == -1.0)
            printf("No solution\n");
        else
            printf("%.4lf\n", x);
    }
    return 0;
}
