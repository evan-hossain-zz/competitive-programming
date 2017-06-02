#include <bits/stdc++.h>

using namespace std;

struct point
{
    int x, y;
};

bool on_segment(point p, point q, point r) // q point lies between p and r
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

int check(const point &O, const point &A, const point &B) //checks rotation
{
        int rotation = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
        if(rotation == 0) return 0;
        return rotation > 0? 1 : -1;
}

bool intersects(point p1, point p2, point q1, point q2)
{
    int d1 = check(p1, p2, q1);
    int d2 = check(p1, p2, q2);
    int d3 = check(q1, q2, p1);
    int d4 = check(q1, q2, p2);
    if(d1 != d2 && d3 != d4)
        return true;
    if(!d1 && on_segment(p1, q1, p2)) return true;
    if(!d2 && on_segment(p1, q2, p2)) return true;
    if(!d3 && on_segment(q1, p1, q2)) return true;
    if(!d4 && on_segment(q1, p2, q2)) return true;
    return false;
}

int main()
{
    point p1, p2, q1, q2;
    while(cin >> p1.x >> p1.y >> p2.x >> p2.y >> q1.x >> q1.y >> q2.x >> q2.y)
    {
        if(intersects(p1, p2, q1, q2))
            cout << "intersect\n";
        else
            cout << "do not intersect\n";
    }
    return 0;
}
