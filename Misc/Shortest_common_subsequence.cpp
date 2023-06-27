class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size(), m = str2.size(), l1 = n, l2 = m;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string ans = "";
        while (l1 > 0 && l2 > 0)
        {
            if (str1[l1 - 1] == str2[l2 - 1])
            {
                ans += str1[l1 - 1];
                l1--;
                l2--;
            }
            else if (dp[l1 - 1][l2] > dp[l1][l2 - 1])
            {
                ans += (str1[l1 - 1]);
                l1--;
            }
            else
            {
                ans += (str2[l2 - 1]);
                l2--;
            }
        }
        while (l1 > 0)
        {
            ans += str1[l1 - 1];
            l1--;
        }
        while (l2 > 0)
        {
            ans += str2[l2 - 1];
            l2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};