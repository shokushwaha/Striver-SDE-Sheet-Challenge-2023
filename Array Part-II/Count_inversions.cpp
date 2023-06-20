#include <bits/stdc++.h>
long long merge(long long *arr, long long *temp, int left, int mid, int right)
{
    long long cnt = 0;
    int i = left, j = mid, k = left;
    while (i <= mid - 1 && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cnt += mid - i;
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return cnt;
}
long long ms(long long *arr, long long *temp, int left, int right)
{
    int cnt = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        cnt += ms(arr, temp, left, mid);
        cnt += ms(arr, temp, mid + 1, right);
        cnt += merge(arr, temp, left, mid + 1, right);
    }
    return cnt;
}

long long getInversions(long long *arr, int n)
{ // Write your code here.
    long long temp[n];
    long long cnt = ms(arr, temp, 0, n - 1);
    return cnt;
}
