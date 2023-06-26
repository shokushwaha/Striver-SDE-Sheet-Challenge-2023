bool isValid(int num, int row, int col, int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (matrix[row][i] == num)
            return false;

        if (matrix[i][col] == num)
            return false;

        if (matrix[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }

    return true;
}
bool solve(int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(num, i, j, matrix))
                    {

                        matrix[i][j] = num;

                        if (solve(matrix) == true)
                            return true;
                        else
                            matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9])
{
    // Write your code here.
    return solve(matrix);
}
