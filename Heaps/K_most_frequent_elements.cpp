vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    unordered_map<int, int> mp;
    for (auto it : arr)
        mp[it]++;

    priority_queue<pair<int, int>> pq;

    for (auto it : mp)
        pq.push({it.second, it.first});

    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}