#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 21474836452
#define LL long long
#define Pi acos(-1)
#define SZ 1000000010
#define error 1e-8

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

double m1, m2, radius, m3, x, y;
double X1, X2, X3, Y1, Y2, Y3;

struct point
{
    double x, y;
};
point arr[55];

double find_x(void)
{
    double up = m1 * m2 * (Y3 - Y1) +m1 * (X2 + X3) - m2 * (X1 + X2);
    double down = 2.0 * (m1 - m2);
    return up/down;
}
double find_y(double x)
{
    double f = 0;
    if(m1 > error)
    {
        f = (double) -1 / m1;
        f = f * (x - ((double) (X1 + X2) / 2.0));
        f += ((Y1 + Y2) / 2.0);
    }
    else if (m2 > error)
    {
        f = (double) -1 / m2;
        f = f * (x - ((double) (X3 + X2) / 2.0));
        f += ((Y3 + Y2) / 2.0);
    }
    else
     {
        f = (double) -1 / m3;
        f = f * (x - ((double) (X1 + X3) / 2.0));
        f += ((Y1 + Y3) / 2.0);
    }
    return f;
}
bool slopes(void)
{
    m1 = m2 = m3 = - infinity;
    if(X1 != X2)
        m1 = (Y2 - Y1) / (X2 - X1);
    if(X2 != X3)
        m2 = (Y3 - Y2) / (X3 - X2);
    if(X3 != X1)
        m3 = (Y3 - Y1) / (X3 - X1);
}
double get_dist(double x, double y, point p)
{
    return sqrt(((x - p.x) * (x - p.x)) + ((y - p.y) * (y - p.y)));
}
//bool right_angle(void)
//{
//    if(fabs(m1 - 0) < error && fabs(m2 - 0) < error)
//    {
//        x = (X1 + X3) / 2.0;
//        y = (Y1 + Y3) / 2.0;
//    }
//    else if(fabs(m1 - 0) < error && fabs(m3 - 0) < error)
//    {
//        x = (X2 + X3) / 2.0;
//        y = (Y2 + Y3) / 2.0;
//    }
//    else if(fabs(m3 - 0) < error && fabs(m2 - 0) < error)
//    {
//        x = (X1 + X2) / 2.0;
//        y = (Y1 + Y2) / 2.0;
//    }
//    else
//        return false;
//    return true;
//}

int main()
{
    int t, n, i, j, k, circle, killed, l;
    scanf("%d", &t);
    while(t--)
    {
        circle= killed = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%lf %lf", &arr[i].x, &arr[i].y);
        for(i = 0; i < n; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                for(k = j + 1; k < n; k++)
                {
                    X1 = arr[i].x, Y1 = arr[i].y;
                    X2 = arr[j].x, Y2 = arr[j].y;
                    X3 = arr[k].x, Y3 = arr[k].y;
                    circle++;
//                    cout << i << ' ' << j << ' ' << k << endl;
//                    cout << m1 << ' ' << m2 << ' ' << m3 << endl;
                    slopes();
//                    radius = get_dist(x, y, arr[i]);
                    for(l = 0; l < n; l++)
                    {
                        if(l == i || l == j || l == k)
                            continue;
//                        cout << i << ' ' << j << ' ' << k << ' ' << x << ' ' << y << ' ' << radius << ' ' << /*get_dist(x, y, arr[l]) / 2.0 <<*/ endl;
                        get_dist(x, y, arr[l]);
//                        if(radius - (get_dist(x, y, arr[l]) / 2.0) >= error)
                        {
//                            cout << i << ' ' << j << ' ' << k << endl;
//                            cout <<radius << ' ';
//                            cout << x << ' ' << y << ' ' << l << endl;
//                            cout << i << ' ' << j << ' ' << k << ' ' << radius << ' ' << get_dist(x, y, arr[l]) << endl;
//                            cout << m1 << ' ' << m2 << endl;
//                            cout << x << ' ' << y << ' ' << arr[l].x << ' ' << arr[l].y << ' ' << get_dist(x, y, arr[l]) << ' ' << radius<< endl;
                            killed++;
                        }
                    }
                }
            }
        }
        circle *= (n - 3);
        cout << circle << ' ' << killed << endl;
        printf("%lf\n", (double) killed / circle);
    }
    return 0;
}

