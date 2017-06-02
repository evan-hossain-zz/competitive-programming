#include <iostream>

using namespace std;

int main()
{
int a, b, cnt = 0;
cin >> a >> b;
if(a % 2 == 0)
    cnt++;
if(b%2 == 0)
    cnt++;
cout << cnt;
return 0;
}
