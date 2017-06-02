#include<stdio.h>

int array2[3] = {0, 1, 81};
int array4[5] = {0,1,2025,3025,9801};
int array6[5] = {0,1,88209,494209,998001};
int array8[9] = {0,1,4941729,7441984,24502500,25502500,52881984,60481729,99980001};

int main()
{
    int n, i;
    while(scanf("%d", &n) == 1)
    {
        i = 0;
        switch(n){
        case 2:
        {
            while(i < 3)
                printf("%02d\n", array2[i++]);
            break;
        }
        case 4:
        {
            while(i < 5)
                printf("%04d\n", array4[i++]);
            break;
        }
        case 6:
        {
            while(i < 5)
                printf("%06d\n", array6[i++]);
            break;
        }
        case 8:
        {
            while(i < 9)
                printf("%08d\n", array8[i++]);
            break;
        }
        }
    }
    return 0;
}

