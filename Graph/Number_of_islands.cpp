bool isValid(int row, int col, int n, int m)
{
    if (row >= 0 && col >= 0 && row < n && col < m)
        return true;
    else
        return false;
}
void dfs(vector<vector<int>> &vis, int row, int col, int **arr, int n, int m)
{
    vis[row][col] = 1;

    int drow[] = {-1, 0, 1, 0, -1, 1, -1, 1};
    int dcol[] = {0, 1, 0, -1, 1, -1, -1, 1};

    for (int i = 0; i < 8; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (isValid(nrow, ncol, n, n) && !vis[nrow][ncol] && arr[nrow][ncol] == 1)
            dfs(vis, nrow, ncol, arr, n, n);
    }
}
int getTotalIslands(int **arr, int n, int m)
{
    // Write your code here.
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && !vis[i][j])
            {
                dfs(vis, i, j, arr, n, m);
                cnt++;
            }
        }
    }
    return cnt;
}
