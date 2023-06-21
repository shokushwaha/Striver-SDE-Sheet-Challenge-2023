bool issafe(int i, int j, int m, int n)
{
    if (i >= 0 && j >= 0 && i < m && j < n)
        return true;
    return false;
}
int solve(int m, int n, int i, int j, vector<vector<int>> &dp)
{

    if (i == m - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    if (issafe(i, j + 1, m, n))
        ans += solve(m, n, i, j + 1, dp);

    if (issafe(i + 1, j, m, n))
        ans += solve(m, n, i + 1, j, dp);

    return dp[i][j] = ans;
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m, n, 0, 0, dp);
}