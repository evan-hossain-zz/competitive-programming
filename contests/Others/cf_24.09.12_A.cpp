#include <iostream>
#include <cmath>

using namespace std;


long long ax, ay, bx, by, cx, cy, val;

int main()
{
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    val = ((bx - ax) * (cy - ay)) - ((by - ay) * (cx - ax));
    if(!val)
        cout << "TOWARDS";
    else if(val < 0)
        cout << "RIGHT";
    else
        cout << "LEFT";
    return 0;
}


