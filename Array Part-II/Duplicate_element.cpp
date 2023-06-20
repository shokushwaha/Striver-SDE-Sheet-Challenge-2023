int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_map<int, int> mp;
    for (auto it : arr)
        mp[it]++;

    for (auto it : mp)
    {
        if (it.second >= 2)
            return it.first;
    }

    return -1;
}