#include <bits/stdc++.h>
bool f(int index, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;

    if (index == 0)
        return arr[0] == sum;

    if (dp[index][sum] != -1)
        return dp[index][sum];

    bool take = false;

    if (arr[index] <= sum)
        take = f(index - 1, sum - arr[index], arr, dp);

    bool notTake = f(index - 1, sum, arr, dp);

    return dp[index][sum] = take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // return f(n-1,k,arr,dp);

    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int sum = 1; sum <= k; sum++)
        {
            bool take = false;
            if (arr[i] <= sum)
                take = dp[i - 1][sum - arr[i]];

            bool notTake = dp[i - 1][sum];

            dp[i][sum] = take | notTake;
        }
    }
    return dp[n - 1][k];
}