#include <stdio.h>
#include <string.h>

int arr[1010][1010];

int main()
{
    char str1[1010], str2[1010];
    int i, j, l1, l2;
    while(gets(str1) && gets(str2))
        {
            l1 = strlen(str1);
            l2 = strlen(str2);
            for(i = 1; i <= l1; i++)
                {
                    for(j = 1; j <= l2; j++)
                        {
                            if(str1[i-1] == str2[j-1])
                                arr[i][j] = arr[i-1][j - 1] + 1;
                            else
                                {
                                    if(arr[i - 1][j] > arr[i][j - 1])
                                        arr[i][j] = arr[i - 1][j];
                                    else
                                        arr[i][j] = arr[i][j - 1];
                                }
                        }
                }
            printf("%d\n", arr[i - 1][j - 1]);
            if(l1 < l2)
                l1 = l2;
            for(i = 0; i <= l1; i++)
                arr[i][0] = arr[0][i] = 0;
        }
        return 0;
}
