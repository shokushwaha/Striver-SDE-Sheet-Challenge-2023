int memo(vector<int> &values, vector<int> &weights, int ind, int weight, vector<vector<int>> &dp)
{

    if (weight <= 0)
        return 0;

    if (ind == 0)
    {
        if (weight >= weights[0])
            return values[0];
        else
            return 0;
    }
    if (dp[ind][weight] != -1)
        return dp[ind][weight];

    int take = 0, notTake = 0;

    if (weights[ind] <= weight)
        take += values[ind] + memo(values, weights, ind - 1, weight - weights[ind], dp);

    notTake = memo(values, weights, ind - 1, weight, dp);

    return dp[ind][weight] = max(take, notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here

    // vector<vector<int>>dp(n,vector<int>(w+1,-1));
    // return memo(values,weights,n-1,w,dp);

    vector<vector<int>> dp(n + 1, vector<int>(w + 1));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < w + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}