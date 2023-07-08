void solve(int ind, vector<int> &temp, vector<int> &arr, set<vector<int>> &st)
{
    if (ind == arr.size())
    {
        st.insert(temp);
        return;
    }

    // skip
    solve(ind + 1, temp, arr, st);

    // take
    temp.push_back(arr[ind]);
    solve(ind + 1, temp, arr, st);
    temp.pop_back();
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here
    sort(arr.begin(), arr.end());
    set<vector<int>> ans;
    vector<int> temp;
    solve(0, temp, arr, ans);

    vector<vector<int>> comb;
    for (auto it : ans)
        comb.push_back(it);

    return comb;
}