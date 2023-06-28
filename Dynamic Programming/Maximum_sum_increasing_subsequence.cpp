int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // Write your code here
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (rack[prev] < rack[ind] && 1 + dp[prev] > dp[ind])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }

        if (dp[ind] > maxi)
        {
            maxi = dp[ind];
            lastIndex = ind;
        }
    }

    int sum = 0;
    sum += rack[lastIndex];
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        sum += rack[lastIndex];
    }
    return sum;
}