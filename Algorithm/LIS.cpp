int sequence[100], I[101], L[100], lislength;

int input(void)
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &sequence[i]);
    return n;
}

int lis(int n)
{
    int i, low, high, mid;
    I[0] = -infinity;
    for(i = 1; i <= n; i++)
        I[i] = infinity;
    lislength = 0;
    for(i = 0; i < n; i++)
    {
        low = 0, high = lislength;
        while(low <= high)
        {
            mid = low + high >> 1;
            if(I[mid] < sequence[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = sequence[i];
        L[i] = low;
        if(lislength < low)
            lislength = low;
    }
    return lislength;
}

void printseq(void)
{
    int pos, i, n, j, arr[lislength], val = lislength;
    for(i = 0; i < 10; i++)
        if(L[i] == lislength)
        {
            pos = i;
            arr[val - 1] = sequence[pos];
            val--;
            break;
        }
    for(i = pos; i >= 0; i--)
    {
        if(L[i] == val && sequence[pos] > sequence[i])
        {
            arr[val - 1] = sequence[i];
            val--;
            pos = i;
        }
    }
    for(i = 0; i < lislength; i++)
        cout << arr[i] << ' ';
}
