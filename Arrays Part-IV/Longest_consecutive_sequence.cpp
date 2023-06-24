int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    int cnt = 1;
    int prevSmaller = INT_MIN;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == prevSmaller + 1)
        {
            cnt++;
            prevSmaller = arr[i];
        }
        else if (arr[i] != prevSmaller)
        {
            cnt = 1;
            prevSmaller = arr[i];
        }
        ans = max(ans, cnt);
    }
    return ans;
}