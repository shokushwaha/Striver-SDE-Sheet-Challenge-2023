int f(int ind, bool buy, int trans, vector<int> prices, vector<vector<vector<int>>> &dp)
{
    if (ind >= prices.size() || trans == 0)
        return 0;

    if (dp[ind][buy][trans] != -1)
        return dp[ind][buy][trans];

    int profit = 0;

    // can buy
    if (buy)
    {
        // will buy
        int a = -prices[ind] + f(ind + 1, false, trans, prices, dp);
        // will not buy
        int b = f(ind + 1, true, trans, prices, dp);
        profit = max(a, b);
    }

    // can sell
    else
    {
        // will sell
        int a = prices[ind] + f(ind + 1, true, trans - 1, prices, dp);
        // will not sell
        int b = f(ind + 1, false, trans, prices, dp);
        profit = max(a, b);
    }

    return dp[ind][buy][trans] = profit;
}
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(k + 1, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int canBuy = 0; canBuy < 2; canBuy++)
        {
            for (int trans = 1; trans <= k; trans++)
            {
                int maxProfit = 0;

                // can buy the stock
                if (canBuy)
                {
                    // will buy
                    int a = -prices[i] + dp[i + 1][0][trans];
                    // will not buy
                    int b = dp[i + 1][1][trans];
                    maxProfit = max(a, b);
                }
                // can sell
                else
                {
                    // will sell
                    int a = prices[i] + dp[i + 1][1][trans - 1];
                    // will not sell
                    int b = dp[i + 1][0][trans];
                    maxProfit = max(a, b);
                }
                dp[i][j][trans] = maxProfit;
            }
        }
    }
    return dp[0][1][k];
}
