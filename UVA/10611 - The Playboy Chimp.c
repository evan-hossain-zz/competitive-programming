#include <stdio.h>

int hights[50001];
int main()
{
    int n, i = 0, j, k, q, mid, beg, end, min, max, temp;
    scanf("%d", &n);
    while(i < n)
        scanf("%d", &hights[i++]);
    scanf("%d", &q);
    while(q--)
    {
        int flag = 1;
        mid = 0;
        min = max = 0;
        scanf("%d", &n);
        beg = 0;
        end = i - 1;
        if(n >= hights[end])
        {
            while(hights[end] >= n)
                end--;
            min = hights[end];
            flag = 0;
        }
        else if(n <= hights[beg])
        {
            while(hights[beg] <= n)
                beg++;
            max = hights[beg];
            flag = 0;
        }
        while(flag && beg < end)
        {
            mid = (beg + end) >> 1;
            if(hights[mid] == n)
            {
                if(mid - 1 >= 0)
                {
                    temp = mid - 1;
                    while(hights[temp] >= n)
                        temp--;
                    if(temp >= 0)
                        min = hights[temp];
                }
                if(mid + 1 < i)
                {
                    temp = mid + 1;
                    while(hights[temp] <= n)
                        temp++;
                    if(temp < i)
                        max = hights[temp];
                }
                break;
            }
            if(n < hights[mid])
                end = mid - 1;
            else if(n > hights[mid])
                beg = mid + 1;
            if(beg == end)
            {
                if(hights[beg] > n)
                {
                    max = hights[beg];
                    if(beg - 1 >= 0)
                    {
                        temp = beg - 1;
                        while(hights[temp] >= n)
                            temp--;
                        if(temp >= 0)
                            min = hights[temp];
                    }
                }
                else if(hights[beg] < n)
                {
                    min = hights[beg];
                    if(beg + 1 < i)
                    {
                        temp = beg + 1;
                        while(hights[temp] <= n)
                            temp++;
                        if(temp < i)
                            max = hights[temp];
                    }
                }
                else
                {
                    if(beg - 1 >= 0)
                    {
                        temp = beg - 1;
                        while(hights[temp] >= n)
                            temp--;
                        if(temp >= 0)
                            min = hights[temp];
                    }
                    if(beg + 1 < i)
                    {
                        temp = beg + 1;
                        while(hights[temp] <= n)
                            temp++;
                        if(temp < i)
                            max = hights[temp];
                    }
                }
            }
        }
        if(hights[mid] > n && (max == 0 && min == 0))
        {
            temp = mid;
            do
                temp--;
            while(hights[temp] > n);
            max = hights[++temp];
            do
                temp--;
            while(hights[temp] >= n);
            if(temp >= 0)
                min = hights[temp];
        }
        else if(hights[mid] < n && (max == 0 && min == 0))
        {
            temp = mid;
            do
                temp++;
            while(hights[temp] < n);
            min = hights[--temp];
            do
                temp++;
            while(hights[temp] == n);
            if(temp < i)
                max = hights[temp];
        }
        if(min == 0)
            printf("X ");
        else
            printf("%d ", min);
        if(max == 0)
            printf("X\n");
        else
            printf("%d\n", max);
    }
    return 0;
}
