#include <bits/stdc++.h>
int f(int ind, int prev_index, int arr[], int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    int take = INT_MIN;
    // take
    if (prev_index == -1 || arr[ind] > arr[prev_index])
        take = 1 + f(ind + 1, ind, arr, n, dp);

    // notTake
    int notTake = f(ind + 1, prev_index, arr, n, dp);

    return dp[ind][prev_index + 1] = max(take, notTake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // int prev_index=-1;
    // return f(0,prev_index,arr,n,dp);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int len = 0 + dp[ind + 1][prev + 1];
            if (prev == -1 || arr[ind] > arr[prev])
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            dp[ind][prev + 1] = len;
        }
    }
    return dp[0][0];

    // optimised ->
    // int dp[n];
    // int ans = 1;
    // for (int i = 0; i < n; i++)
    //     dp[i] = 1;
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (arr[j] < arr[i])
    //         {
    //             dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //     }
    //     ans = max(ans, dp[i]);
    // }

    // return ans;
}
