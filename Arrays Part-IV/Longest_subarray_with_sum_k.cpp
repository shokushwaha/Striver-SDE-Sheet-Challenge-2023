int LongestSubsetWithZeroSum(vector<int> arr, int k)
{

    // Write your code here
    int maxi = 0, sum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == k)
            maxi = i + 1;

        if (mp.find(sum - k) != mp.end())
            maxi = max(maxi, i - mp[sum]);

        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }

    return maxi;
}