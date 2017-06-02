#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char arr[12];
    int test;
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", arr);
        sort(&arr[0], &arr[strlen(arr)]);
        do{
            printf("%s\n", arr);
        }while(next_permutation(&arr[0], &arr[strlen(arr)]));
        printf("\n");
    }
    return 0;
}
