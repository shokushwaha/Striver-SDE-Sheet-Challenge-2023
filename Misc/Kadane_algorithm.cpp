long long maxSubarraySum(int a[], int n)
{

    // Your code here
    long long sum = 0;

    long long maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }

    return maxi;
}