bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{

    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;

    while (col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        row++;
        col--;
    }

    return true;
}
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    if (col == n)
    {
        vector<int> temp;
        for (auto it : board)
        {
            for (int i = 0; i < it.size(); i++)
                temp.push_back(it[i]);
        }
        ans.push_back(temp);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, board, ans, n);
            board[row][col] = 0;
        }
    }
    return;
}
vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, board, ans, n);
    return ans;
}