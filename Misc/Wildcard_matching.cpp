bool f(string pattern, string str, int ind1, int ind2, vector<vector<int>> &dp)
{

    if (ind1 < 0 && ind2 < 0)
        return true;

    if (ind1 < 0 && ind2 >= 0)
        return false;

    if (ind2 < 0 && ind1 >= 0)
    {
        for (int i = 0; i <= ind1; i++)
        {
            if (pattern[i] != '*')
                return false;
        }
        return true;
    }

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (pattern[ind1] == str[ind2] || pattern[ind1] == '?')
        return dp[ind1][ind2] = f(pattern, str, ind1 - 1, ind2 - 1, dp);

    if (pattern[ind1] == '*')
        return dp[ind1][ind2] = f(pattern, str, ind1 - 1, ind2, dp) | f(pattern, str, ind1, ind2 - 1, dp);

    // return dp[ind1][ind2]= false;
}
int wildCard(string pattern, string str)
{
    int n = pattern.size();
    int m = str.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(pattern, str, n - 1, m - 1, dp);
}