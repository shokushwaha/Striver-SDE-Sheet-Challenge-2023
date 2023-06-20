int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int curMin = prices[0];
    int maxProfit = INT_MIN;
    for (int i = 1; i < prices.size(); i++)
    {
        maxProfit = max(maxProfit, prices[i] - curMin);
        curMin = min(curMin, prices[i]);
    }

    return maxProfit < 0 ? 0 : maxProfit;
}