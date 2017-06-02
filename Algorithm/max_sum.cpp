struct info
{
    int start, en, sum;
};

info max_sum(int *data, int n);

int main()
{
    int arr[50], i = 0;
    info res;
    while(scanf("%d", &arr[i]) == 1 && arr[i])
        i++;
    res = max_sum(arr, i);
    cout << res.start << ' ' << res.en << ' ' << res.sum << endl;
    return 0;
}

info max_sum(int *data, int n)
{
    int start = 0, en = 0, tem = 0, i, sum = 0;
    info ret;
    ret.start = ret.en = ret.sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += data[i];
        if(sum < 0)
        {
            tem = i + 1;
            sum = 0;
        }
        else if(sum > ret.sum)
        {
            ret.sum = sum;
            ret.start = tem;
            ret.en = i;
        }
    }
    return ret;
}
