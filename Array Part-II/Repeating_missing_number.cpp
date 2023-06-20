pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    unordered_map<int, int> mp;
    for (auto it : arr)
        mp[it]++;

    int missing = 0, repeating = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 2)
            repeating = i;
        if (mp[i] == 0)
            missing = i;
    }

    return {missing, repeating};
}
