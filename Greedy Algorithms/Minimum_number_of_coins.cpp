int findMinimumCoins(int amount)
{
    // Write your code here
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    int i = 0;
    int cnt = 0;
    while (amount && i < coins.size())
    {
        if (coins[i] <= amount)
        {
            amount -= coins[i];
            cnt++;
        }
        else
            i++;
    }
    return cnt;
}