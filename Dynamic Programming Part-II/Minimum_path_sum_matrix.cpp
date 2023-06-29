int f(int ind1, int ind2, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    if (ind1 > n - 1 || ind2 > m - 1)
        return 1e9;

    if (ind1 == n - 1 && ind2 == m - 1)
        return grid[ind1][ind2];

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int down = grid[ind1][ind2] + f(ind1 + 1, ind2, n, m, grid, dp);

    int right = grid[ind1][ind2] + f(ind1, ind2 + 1, n, m, grid, dp);

    return dp[ind1][ind2] = min(down, right);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.

    // int start=0,end=0;
    int n = grid.size();
    int m = grid[0].size();
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // return f(start,end,n,m,grid,dp);
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
                dp[i][j] = grid[i][j];

            else
            {
                int down = 1e9;
                int right = 1e9;

                if (i + 1 != n)
                    down = grid[i][j] + dp[i + 1][j];
                if (j + 1 != m)
                    right = grid[i][j] + dp[i][j + 1];

                dp[i][j] = min(down, right);
            }
        }
    }
    return dp[0][0];
}