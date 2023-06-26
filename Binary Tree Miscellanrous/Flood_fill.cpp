bool isValid(int row, int col, int n, int m)
{
    if (row >= 0 && col >= 0 && row < n && col < m)
        return true;
    else
        return false;
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int color = image[x][y];

    if (color == newColor)
        return image;

    vis[x][y] = 1;
    queue<pair<int, int>> q;
    image[x][y] = newColor;
    q.push({x, y});
    int delr[] = {0, 1, 0, -1};
    int delc[] = {1, 0, -1, 0};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if (isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && image[nrow][ncol] == color)
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
                image[nrow][ncol] = newColor;
            }
        }
    }

    return image;
}