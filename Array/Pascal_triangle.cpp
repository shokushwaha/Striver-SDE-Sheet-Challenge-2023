vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans(n, vector<long long int>(0));

    for (int i = 0; i < n; i++)
    {

        ans[i].push_back(1);
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j < i; j++)
        {

            ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }

        ans[i].push_back(1);
    }

    return ans;
}