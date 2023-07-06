int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return n * price[0];

    if (dp[ind][n] != -1)
        return dp[ind][n];

    int notTake = f(ind - 1, n, price, dp);

    int take = -1e9;
    int rodLen = ind + 1;

    if (rodLen <= n)
        take = price[ind] + f(ind, n - rodLen, price, dp);

    return dp[ind][n] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return f(n-1,n,price,dp);
    for (int i = 0; i <= n; i++)
        dp[0][i] = price[0] * i;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notTake = dp[i - 1][j];
            int take = -1e9, rodlen = i + 1;
            if (rodlen <= j)
                take = price[i] + dp[i][j - rodlen];

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}
