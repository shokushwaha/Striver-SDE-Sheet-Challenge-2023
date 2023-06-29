vector<int> LargestSubset(int n, vector<int> &arr)
{
    // Code here
    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);
    vector<int> back(n);
    vector<int> ans;
    int maxi = 1;
    int last = 0;

    for (int i = 0; i < n; i++)
    {
        back[i] = i;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] % arr[j] == 0 && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                back[i] = j;
            }
        }

        if (dp[i] > maxi)
        {
            maxi = dp[i];
            last = i;
        }
    }

    while (back[last] != last)
    {
        ans.push_back(arr[last]);
        last = back[last];
    }
    ans.push_back(arr[last]);

    return ans;
}