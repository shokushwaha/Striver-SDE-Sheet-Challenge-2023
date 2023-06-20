void makeZero(int row, int col, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = row;
    while (i >= 0)
    {
        matrix[i][col] = 0;
        i--;
    }
    int j = col;
    while (j >= 0)
    {
        matrix[row][j] = 0;
        j--;
    }
    i = row;
    while (i < n)
    {
        matrix[i][col] = 0;
        i++;
    }
    j = col;
    while (j < m)
    {
        matrix[row][j] = 0;
        j++;
    }
}
void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    vector<vector<int>> temp = matrix;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
            {
                makeZero(i, j, matrix);
            }
        }
    }
}