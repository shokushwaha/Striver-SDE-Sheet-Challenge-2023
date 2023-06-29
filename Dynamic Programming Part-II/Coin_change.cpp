long solve(int ind, int value, int *arr, int n, vector<vector<long>> &dp)
{

    if (value == 0)
        return 1;

    if (ind == 0)
    {
        if (value % arr[ind] == 0)
            return 1;
        else
            return 0;
    }

    if (dp[ind][value] != -1)
        return dp[ind][value];

    long notTake = solve(ind - 1, value, arr, n, dp);

    long take = 0;
    if (arr[ind] <= value)
        take = solve(ind, value - arr[ind], arr, n, dp);

    return dp[ind][value] = take + notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here

    vector<vector<long>> dp(n, vector<long>(value + 1, -1));

    return solve(n - 1, value, denominations, n, dp);
}