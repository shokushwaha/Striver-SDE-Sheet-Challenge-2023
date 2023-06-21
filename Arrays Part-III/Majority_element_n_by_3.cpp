vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    unordered_map<int, int> mp;
    for (auto it : arr)
        mp[it]++;

    for (auto it : mp)
    {
        if (it.second > arr.size() / 3)
            ans.push_back(it.first);
    }

    return ans;
}