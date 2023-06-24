#include <bits/stdc++.h>
static bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.second.second < b.second.second)
        return true;
    else if (a.second.second > b.second.second)
        return false;
    else if (a.first < b.first)
        return true;
    else
        return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.

    int n = start.size();
    vector<pair<int, pair<int, int>>> arr;
    for (int i = 0; i < n; i++)
        arr.push_back({i + 1, {start[i], end[i]}});

    sort(arr.begin(), arr.end(), comp);
    int maxEnd = arr[0].second.second;
    vector<int> ans;
    ans.push_back(arr[0].first);
    for (int i = 1; i < n; i++)
    {
        if (maxEnd < arr[i].second.first)
        {
            ans.push_back(arr[i].first);
            maxEnd = arr[i].second.second;
        }
    }
    return ans;
}