bool isPalindrome(int i, int j, string a)
{
    while (i < j)
    {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int f(int i, int n, string &a, vector<int> &dp)
{
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];
    int mincost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, a))
        {
            int cost = 1 + f(j + 1, n, a, dp);
            mincost = min(cost, mincost);
        }
    }
    return dp[i] = mincost;
}
int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.length();
    vector<int> dp(n, -1);
    return f(0, n, str, dp) - 1;
}