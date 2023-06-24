bool isValid(int row, int col, int n, int m)
{
    if (row >= 0 && col >= 0 && row < n && col < m)
        return true;
    else
        return false;
}
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    // Write your code here.
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else if (grid[i][j] == 1)
            {
                vis[i][j] = 1;
            }
        }
    }
    int delr[] = {-1, 0, 1, 0};
    int delc[] = {0, 1, 0, -1};

    int tm = 0;
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();
        tm = max(tm, time);

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delr[i];
            int ncol = col + delc[i];
            if (isValid(nrow, ncol, n, m) && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, time + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 1)
                return -1;
        }
    }

    return tm;
}