void sort012(int *arr, int n)
{
    int zeroCnt = 0, oneCnt = 0, twoCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zeroCnt++;
        else if (arr[i] == 1)
            oneCnt++;
        else
            twoCnt++;
    }
    int i = 0;
    while (zeroCnt)
    {
        arr[i++] = 0;
        zeroCnt--;
    }

    while (oneCnt)
    {
        arr[i++] = 1;
        oneCnt--;
    }

    while (twoCnt)
    {
        arr[i++] = 2;
        twoCnt--;
    }
}