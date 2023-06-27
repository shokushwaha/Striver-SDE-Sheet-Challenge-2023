void solve(int ind, int sum, int k, vector<int> arr, vector<vector<int>> &ans, vector<int> &temp)
{
    if (ind == arr.size())
    {
        if (sum == k)
            ans.push_back(temp);
        return;
    }

    solve(ind + 1, sum, k, arr, ans, temp);
    temp.push_back(arr[ind]);
    solve(ind + 1, sum + arr[ind], k, arr, ans, temp);
    temp.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> temp;

    solve(0, 0, k, arr, ans, temp);

    return ans;
}