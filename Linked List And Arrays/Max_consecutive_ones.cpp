int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int j = -1;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt++;

        while (cnt > k)
        {
            j++;

            if (arr[j] == 0)
                cnt--;
        }

        ans = max(ans, i - j);
    }
    return ans;
}
