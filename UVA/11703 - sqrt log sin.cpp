#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int arr[1000010];

void func(void);

int main()
{
    func();
    int n;
    while(cin >> n && n != -1)
        cout << arr[n] << endl;
    return 0;
}

void func(void)
{
    arr[0] = 1;
    for(int i = 1; i < 1000001; i++)
    arr[i] = (arr[(int)(i - sqrt(i))] + arr[(int)log(i)] +\
    arr[(int)(i * sin(i) * sin(i))]) % 1000000;
    return;
}
