void solve(int row, int col, vector<vector<int>> &ans, vector<int> &temp, vector<vector<int>> &pathvis,
           vector<vector<int>> &maze, int n)
{
    if (col == n - 1 && row == n - 1)
    {
        ans.push_back(temp);
        return;
    }
    int del_row[] = {0, 0, 1, -1};
    int del_col[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + del_row[i];
        int ncol = col + del_col[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && pathvis[nrow][ncol] == 0 && maze[nrow][ncol] == 1)
        {
            pathvis[nrow][ncol] = 1;
            temp[n * nrow + ncol] = 1;

            solve(nrow, ncol, ans, temp, pathvis, maze, n);

            pathvis[nrow][ncol] = 0;
            temp[n * nrow + ncol] = 0;
        }
    }
    return;
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    // Write your code here.
    vector<int> temp(n * n, 0);
    vector<vector<int>> ans;
    vector<vector<int>> pathvis(n, vector<int>(n, 0));
    pathvis[0][0] = 1;
    temp[0] = 1;
    solve(0, 0, ans, temp, pathvis, maze, n);

    return ans;
}