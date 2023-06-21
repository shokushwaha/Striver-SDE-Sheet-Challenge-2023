
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size();

    while (i < j)
    {
        int sum = arr[i] + arr[j];

        if (sum == s)
        {
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            ans.push_back(temp);

            i++;
            j--;
        }
        else if (sum < s)
            i++;
        else
            j--;
    }
    return ans;
}